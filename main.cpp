#include "mainwindow.h"
//#include "licznik.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //return a.exec();

//    Licznik licznik;
//    licznik.show();
    return a.exec();
}
