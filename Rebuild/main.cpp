#include "Rebuild.h"
#include <QtWidgets/QApplication>
#include <QSqlTableModel>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Rebuild w;
  //  w.show();

    return a.exec();
}
