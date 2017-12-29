#include "Rebuild.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Rebuild w;
    w.show();
    return a.exec();
}
