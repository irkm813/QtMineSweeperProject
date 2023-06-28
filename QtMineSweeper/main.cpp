#include "QtMineSweeper.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtMineSweeper w;
    w.show();
    return a.exec();
}
