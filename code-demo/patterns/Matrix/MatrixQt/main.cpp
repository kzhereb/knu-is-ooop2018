#include "mainwindow.h"
#include "matrix.h"
#include "matrixfactory.h"
#include "matrix_exceptions.h"
#include <QApplication>
#include <QDebug>

void check_incompatible() {
    Matrix1DFactory<int> factory;
    Matrix<int>* matr1 = factory.createMatrix(1,2);
    Matrix<int>* matr2 = factory.createMatrix(3,4);

    try {
        Matrix<int>* result = (*matr1) * (*matr2);

        qDebug()<< result->get(0,0);
    } catch(incompatible_matrices const & ex) {
        qDebug()<<ex.what();
    }

}

void check_multiply() {
    Matrix1DFactory<int> factory;
    Matrix<int>* matr1 = factory.createMatrix(2,3);
    Matrix<int>* matr2 = factory.createMatrix(3,4);
    matr1->set(0,0,3);
    matr2->set(0,0,5);

    Matrix<int>* result = (*matr1) * (*matr2);
    qDebug()<<result->get(0,0);
}

int main(int argc, char *argv[])
{
    Matrix1DFactory<int> factory;
    Matrix<int> * matr = factory.createMatrix(4,5);
    matr->set(1,3,12);
    qDebug()<< matr->get(1,3);

    check_incompatible();
    check_multiply();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
