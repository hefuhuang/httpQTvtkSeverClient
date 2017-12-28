/********************************************************************************
** Form generated from reading UI file 'Rebuild.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REBUILD_H
#define UI_REBUILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RebuildClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RebuildClass)
    {
        if (RebuildClass->objectName().isEmpty())
            RebuildClass->setObjectName(QStringLiteral("RebuildClass"));
        RebuildClass->resize(600, 400);
        menuBar = new QMenuBar(RebuildClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        RebuildClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(RebuildClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        RebuildClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(RebuildClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        RebuildClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(RebuildClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RebuildClass->setStatusBar(statusBar);

        retranslateUi(RebuildClass);

        QMetaObject::connectSlotsByName(RebuildClass);
    } // setupUi

    void retranslateUi(QMainWindow *RebuildClass)
    {
        RebuildClass->setWindowTitle(QApplication::translate("RebuildClass", "Rebuild", 0));
    } // retranslateUi

};

namespace Ui {
    class RebuildClass: public Ui_RebuildClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REBUILD_H
