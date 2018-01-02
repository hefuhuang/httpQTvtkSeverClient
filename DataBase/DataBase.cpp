#include "DataBase.h"

DataBase::DataBase()
{
}

bool DataBase::Connect(const QString &dbName)   
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

void DataBase::CreateTable(std::string fileDataBase)
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
			qDebug() << " Create REGEN TABLE successful ";

			m_Query.prepare("INSERT INTO student (name, age) VALUES (?, ?)");   // Insert student Table 
			QVariantList m_Names;    // continus operate database 
			m_Names << "huang" << "LI" << "Tom" << "Jack";
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

bool DataBase::ModelOperateDatabase(std::string fielPath)  // QSqlTableModel 进行 SELECT 操作：
{
	//  row 行 col 列 
	if (Connect("demo.db")) {
		QSqlTableModel model;
		model.setTable("student");
		model.setFilter("age > 20 and age < 25");
		if (model.select()) {
			for (int i = 0; i < model.rowCount(); ++i) {
				QSqlRecord record = model.record(i);
				QString name = record.value("name").toString();
				int age = record.value("age").toInt();
				qDebug() << name << ": " << age;
			}
		}
	}
	else {
		return 1;
	}
} 

void DataBase::VisualDataBase(std::string fielPath)
{
	if (Connect(fielPath.c_str())) {
		QSqlTableModel *model = new QSqlTableModel;
		model->setTable("student");
		model->setSort(Column_Name, Qt::AscendingOrder);
		model->setHeaderData(Column_Name, Qt::Horizontal, "Name");
		model->setHeaderData(Column_Age, Qt::Horizontal, "Age");
		model->select();

		QTableView *view = new QTableView;
		view->setModel(model);
		view->setSelectionMode(QAbstractItemView::SingleSelection);
		view->setSelectionBehavior(QAbstractItemView::SelectRows); 

		view->setColumnHidden(Column_ID, true);    // hide function

		view->resizeColumnsToContents();
		view->setEditTriggers(QAbstractItemView::NoEditTriggers);

		QHeaderView *header = view->horizontalHeader();
		header->setStretchLastSection(true);
		view->show();

	}
}

void DataBase::CreateDBTable(std::string fileDataBase,std::string DBCommand)
{
	QFile::remove(fileDataBase.c_str());   // mkaing sure sys.db do not exist 

	if (Connect(fileDataBase.c_str()))  //  connect Table 
	{
		QSqlQuery m_Query;
		bool  SuccessFlg = m_Query.exec(DBCommand.c_str());
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
			qDebug() << " Create REGEN TABLE successful ";

			m_Query.prepare("INSERT INTO student (name, age) VALUES (?, ?)");   // Insert student Table 
			QVariantList m_Names;    // continus operate database 
			m_Names << "huang" << "LI" << "Tom" << "Jack";
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
			std::string DBcommand = "SELECT name, age FROM student";
		//	m_Query.exec("SELECT name, age FROM student");
			PrintInfo(m_Query, DBcommand.c_str());
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

void DataBase::PrintInfo(QSqlQuery m_Query ,std::string DBCommand)
{   
	m_Query.exec(DBCommand.c_str());
	while (m_Query.next()) {
		QString name = m_Query.value(0).toString();
		int age = m_Query.value(1).toInt();
		qDebug() << name << ": " << age;
	}

}