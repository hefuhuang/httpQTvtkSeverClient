#include "Rebuild.h"
#include "GlobalVAton.h" 
#include "FileRW.h"
#include "Qt3DRebuild.h"

Rebuild::Rebuild(QWidget *parent)
	: QMainWindow(parent)
{
	GlobalVaton *singletonObj = GlobalVaton::Instance();   
	fileOperation();
	VisualDataBase();

	ui.setupUi(this);
}

void Rebuild::fileOperation()
{   
	string filePath = "../System.ini";
	FileRW file(filePath.c_str()); 
	file.ReadINI(filePath); 
	file.SetValue("class1","name1","tom"); 

	file.SetValue("class1", "m", "1");
	file.SetValue("class1", "n", "2");
	file.WriteINI("../System.ini");
}
void Rebuild::databaseOperation()
{  
	QFile::remove("../SysConf.db");   // mkaing sure sys.db do not exist 
	QSqlDatabase m_Db = QSqlDatabase::addDatabase("QSQLITE"); 
	m_Db.setHostName("regen");   // seting hostname 
	m_Db.setDatabaseName("../SysConf.db");
	m_Db.setUserName("haung"); 
	m_Db.setPassword("123456");  // seting log password 
	m_Db.open();     // open database Link
	QSqlQuery m_Query;  
	bool  SuccessFlg = m_Query.exec("create table REGEN(id int primary key,LastName varchar(100),FirstName varchar(100),Address varchar(100),City varchar(50))");    // 创建表格 
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
	}
	else
	{
		qDebug() << " Create Table failed ! "; 
	}



}

bool Rebuild::Connect(const QString &dbName)
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
	//    db.setHostName("host");
	//    db.setDatabaseName("dbname");
	//    db.setUserName("username");
	//    db.setPassword("password");
	db.setDatabaseName(dbName);
	if (!db.open()) {
		QMessageBox::critical(0, QObject::tr("Database Error"),
			db.lastError().text());
		return false;
	}
	return true;
}
 
void Rebuild::VisualDataBase()
{
	if (Connect("../SysConf.db")) {
		QSqlTableModel *model = new QSqlTableModel;
		model->setTable("REGEN");
		model->setSort(1, Qt::AscendingOrder);
		model->setHeaderData(1, Qt::Horizontal, "Name");
		model->setHeaderData(2, Qt::Horizontal, "Age");
		model->select();

		QTableView *view = new QTableView;
		view->setModel(model);
		view->setSelectionMode(QAbstractItemView::SingleSelection);
		view->setSelectionBehavior(QAbstractItemView::SelectRows);
		//        view->setColumnHidden(0, true);
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