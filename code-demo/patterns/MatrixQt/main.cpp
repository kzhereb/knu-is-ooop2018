#include "mainwindow.h"
#include "matrix.h"
#include "matrixfactory.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    Matrix1DFactory<int> factory;
    Matrix<int> * matr = factory.createMatrix(4,5);
    matr->set(1,3,12);
    qDebug()<< matr->get(1,3);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
