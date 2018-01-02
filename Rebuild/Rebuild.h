#pragma once
#ifndef _REBUILD_H_
#define _REBUILD_H_

#include <string>
#include <QtWidgets/QMainWindow>
#include <QtCore>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QTime>
#include <QSqlError>
#include <QSqlDriver>
#include <QSqlRecord>
#include <QtDebug>
#include <QSqlTableModel>
#include <QTableView>
#include "ui_Rebuild.h"

class GlobalVaton;
class FileRW;
class DataBase;  

using namespace std;

class Rebuild : public QMainWindow
{
    Q_OBJECT
public:
    Rebuild(QWidget *parent = Q_NULLPTR);

	void fileOperation(string filePath);
	bool Connect(const QString &dbName);
	void databaseOperation(string  fileDataBase);
	void VisualDataBase();
	void ModelOperateDatabase(string fielPath);
private:

    Ui::RebuildClass ui;
	DataBase* m_DataBase;

};

#endif 