#include "mainwindow.h"
#include "picalculator.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    //TwoAtanCalculator calc(1,2,1,1,3,1);
    TwoAtanCalculator calc(1,5,4,1,239,-1);
    qDebug()<<calc.calculate(2);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
