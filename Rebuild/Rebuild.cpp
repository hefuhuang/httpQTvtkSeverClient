/*
* Author	: huanghefu (Opensource)
* Project	: https://github.com/hefuhuang/httpQTvtkSeverClient
* QQ     	: 1966423770
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include <QVBoxLayout>
#include <QThread>
#include <QLCDNumber>
#include <QPushButton>
#include <QSharedMemory>
#include <QLabel>
#include <QFileDialog>

#include "Rebuild.h"
#include "GlobalVAton.h" 
#include "FileRW.h"
#include "Qt3DRebuild.h"
#include "DataBase.h" 
#include "NetUtil.h" 
#include "WorkerThread.h"

class Rebuild::Private
{
public:
	Private()
	{
	
	}
	void fetchWeather(const QString &cityName) const
	{
		m_NetUtil->Get(QString("http://www.weather.com.cn/data/cityinfo/101190408.html").arg(cityName));
	}
 
	NetUtil *m_NetUtil;
};

Rebuild::~Rebuild()
{
	delete m_Private;
	m_Private = nullptr;

}

Rebuild::Rebuild(QWidget *parent)
: QMainWindow(parent), m_Private(new Rebuild::Private),m_sharedMemory(new QSharedMemory("shared", this))
{
//	GlobalVaton *singletonObj = GlobalVaton::Instance();   

	string filePath = "../System.ini";
	string DataFilePath = "../SysConf.db ";
	fileOperation(filePath);
//	databaseOperation(DataFilePath);
//	VisualDataBase(); 
	m_DataBase = new DataBase;
	m_DataBase->CreateTable(DataFilePath);
	m_DataBase->VisualDataBase(DataFilePath);


	QWidget *widget = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout;
	widget->setLayout(layout);
	QLCDNumber* lcdNumber = new QLCDNumber(this);
	layout->addWidget(lcdNumber);
	QPushButton *button = new QPushButton(tr("Start"), this);
	layout->addWidget(button);
	setCentralWidget(widget);

	QTimer *timer = new QTimer(this);
	connect(timer, &QTimer::timeout, [=]() {
		static int sec = 0;
		lcdNumber->display(QString::number(sec++));
	});

	WorkerThread *thread = new WorkerThread(this);
	connect(thread, &WorkerThread::Done, timer, &QTimer::stop);
	connect(thread, &WorkerThread::finished, thread, &WorkerThread::deleteLater);

	connect(button, &QPushButton::clicked, [=]() {
		timer->start(1);
		thread->start();
	});

	QWidget *mainWidget = new QWidget(this);
	QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
	setCentralWidget(mainWidget);

	QPushButton *saveButton = new QPushButton(tr("Save"), this);
	mainLayout->addWidget(saveButton);
	QLabel *picLabel = new QLabel(this);
	mainLayout->addWidget(picLabel);
	QPushButton *loadButton = new QPushButton(tr("Load"), this);
	mainLayout->addWidget(loadButton);
	connect(saveButton, &QPushButton::clicked, [=]() {
		if (m_sharedMemory->isAttached()) {
			m_sharedMemory->detach();
		}
		QString filename = QFileDialog::getOpenFileName(this);
		QPixmap pixmap(filename);
		picLabel->setPixmap(pixmap);

		QBuffer buffer;
		QDataStream out(&buffer);
		buffer.open(QBuffer::ReadWrite);
		out << pixmap;

		int size = buffer.size();
		if (!m_sharedMemory->create(size)) {
			qDebug() << tr("Create Error: ") << m_sharedMemory->errorString();
		}
		else {
			m_sharedMemory->lock();
			char *to = static_cast<char *>(m_sharedMemory->data());
			const char *from = buffer.data().constData();
			memcpy(to, from, qMin(size, m_sharedMemory->size()));
			m_sharedMemory->unlock();
		}
	});

	connect(loadButton, &QPushButton::clicked, [=]() {
		if (!m_sharedMemory->attach()) {
			qDebug() << tr("Attach Error: ") << m_sharedMemory->errorString();
		}
		else {
			QBuffer buffer;
			QDataStream in(&buffer);
			QPixmap pixmap;
			m_sharedMemory->lock();
			buffer.setData(static_cast<const char *>(m_sharedMemory->constData()), m_sharedMemory->size());
			buffer.open(QBuffer::ReadWrite);
			in >> pixmap;
			m_sharedMemory->unlock();
			m_sharedMemory->detach();
			picLabel->setPixmap(pixmap);
		}
	});
//	ui.setupUi(this);
}

void Rebuild::fileOperation(string filePath)
{   
	QFile::remove(filePath.c_str());   // mkaing sure filePath do not exist 
	FileRW file(filePath.c_str()); 
	file.ReadINI(filePath); 

	file.SetValue("class1","name1","tom"); 
	file.SetValue("class1", "m", "1");
	file.SetValue("class1", "n", "2");
	file.WriteINI("../System.ini");
}



void Rebuild::databaseOperation(string fileDataBase)
{  
	QFile::remove(fileDataBase.c_str());   // mkaing sure sys.db do not exist 

	if (Connect(fileDataBase.c_str()))  //  connect Table 
	{
	QSqlQuery m_Query;  
	bool  SuccessFlg = m_Query.exec("create table REGEN("
		"id int primary key,"
		"LastName varchar(100),"
		"FirstName varchar(100),"
		"Address varchar(255),"
		"City varchar(50))");    // Create REGEN  Table   

	m_Query.exec("CREATE TABLE student ("                //Create student table 
		"id INTEGER PRIMARY KEY AUTOINCREMENT,"
		"name VARCHAR,"
		"age INT)");  

	/*
		CREATE TABLE Persons
		(
		Id_P int NOT NULL,
		LastName varchar(255) NOT NULL,
		FirstName varchar(255),
		Address varchar(255),
		City varchar(255),
		PRIMARY KEY (Id_P)
		)
	*/
	// PRIMARY KEY 约束唯一标识数据库表中的每条记录。

	if (SuccessFlg)
	{
		qDebug() <<" Create REGEN TABLE successful ";

		m_Query.prepare("INSERT INTO student (name, age) VALUES (?, ?)");   // Insert student Table 
		QVariantList m_Names;    // continus operate database 
		m_Names << "huang"<< "LI"<< "Tom" << "Jack";  
		m_Query.addBindValue(m_Names); 
		QVariantList m_Ages;
		m_Ages << "18" << "50" << "80" << "25"; 
		m_Query.addBindValue(m_Ages);  
		if (!m_Query.execBatch())
		{
		QMessageBox::critical(0, QObject::tr("Database Error"),
			m_Query.lastError().text());
		}
		m_Query.finish();
		m_Query.exec("SELECT name, age FROM student");

		while (m_Query.next()) {
			QString name = m_Query.value(0).toString();
			int age = m_Query.value(1).toInt();
			qDebug() << name << ": " << age;
		}
	}
	else
	{
		qDebug() << " Create Table failed ! "; 
		QMessageBox::critical(0, QObject::tr("Database Error"),
			m_Query.lastError().text());
	}
	m_Query.clear();
	}
	
}


bool Rebuild::Connect(const QString &dbName)
{
	QSqlDatabase m_Db = QSqlDatabase::addDatabase("QSQLITE");
	m_Db.setHostName("regen");   // seting hostname 
	m_Db.setUserName("haung");
	m_Db.setPassword("123456");  // seting log password 
	m_Db.setDatabaseName(dbName);
	if (!m_Db.open()) {
		QMessageBox::critical(0, QObject::tr("Database Error"),
			m_Db.lastError().text());
		return false;
	}
	return true;
}
 

void Rebuild::VisualDataBase()
{
	if (Connect("../SysConf.db")) {
		QSqlTableModel *model = new QSqlTableModel;
		model->setTable("student");
		model->setSort(1, Qt::AscendingOrder);
		model->setHeaderData(1, Qt::Horizontal, "Name");
		model->setHeaderData(2, Qt::Horizontal, "Age");
		model->select();

		QTableView *view = new QTableView;
		view->setModel(model);
		view->setSelectionMode(QAbstractItemView::SingleSelection);
		view->setSelectionBehavior(QAbstractItemView::SelectRows);

		view->resizeColumnsToContents();
		view->setEditTriggers(QAbstractItemView::NoEditTriggers);

		QHeaderView *header = view->horizontalHeader();
		header->setStretchLastSection(true);
		view->show(); 
	}
	else {
		return ;
	}
}


