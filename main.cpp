#include "mainwindow.h"
#include <QApplication>
#include "sample.h"
#include "cont1.h"
#include "cont.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
