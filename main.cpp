#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating mainwindow and showing game
    MainWindow w;
    w.show();

    return a.exec();
}
