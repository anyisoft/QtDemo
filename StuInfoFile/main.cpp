#include "mainwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;


    w.resize(16*50, 9*50);

    w.show();
    return a.exec();
}
