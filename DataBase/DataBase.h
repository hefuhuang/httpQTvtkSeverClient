#pragma once
#ifndef _DATABASE_H_
#define _DATABASE_H_

#include <string>
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QtDebug>
#include <QSqlTableModel>
#include <QTableView> 
#include <QHeaderView>
#include <QMessageBox>

#include "database_global.h"

class DATABASE_EXPORT DataBase
{
public:
    DataBase();
	~DataBase();
	void CreateTable(std::string fileDataBase);
	bool ModelOperateDatabase(std::string fielPath);
	bool Connect(const QString &dbName);
	void VisualDataBase(std::string fielPath);
	 

private: 

	std::string filepath;
	enum ColumnIndex
	{
		Column_ID = 0,
		Column_Name = 1,
		Column_Age = 2
	};

};

#endif 