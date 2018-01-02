#pragma once

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

class Rebuild : public QMainWindow
{
    Q_OBJECT
public:
    Rebuild(QWidget *parent = Q_NULLPTR);

	void fileOperation();
	void databaseOperation();
	void VisualDataBase();
	bool Connect(const QString &dbName);

private:

    Ui::RebuildClass ui;

};
