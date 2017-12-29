#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Rebuild.h"

class GlobalVaton;
class FileRW; 

class Rebuild : public QMainWindow
{
    Q_OBJECT
public:
    Rebuild(QWidget *parent = Q_NULLPTR);
	void fileOperation();
private:

    Ui::RebuildClass ui;

};
