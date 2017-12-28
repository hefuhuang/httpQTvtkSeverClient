#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Rebuild.h"

class Rebuild : public QMainWindow
{
    Q_OBJECT

public:
    Rebuild(QWidget *parent = Q_NULLPTR);

private:
    Ui::RebuildClass ui;
};
