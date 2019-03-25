#ifndef MATRIXFACTORY_H
#define MATRIXFACTORY_H

#include "matrix.h"

template <typename T>
class MatrixFactory
{
public:
    MatrixFactory()=default;
    virtual Matrix<T>* createMatrix(int rows, int columns)=0;
};


template <typename T>
class Matrix2DFactory: public MatrixFactory<T>
{
public:
    Matrix2DFactory():MatrixFactory<T>() {}
    Matrix<T>* createMatrix(int rows, int columns) {
        return new Matrix2D<T>(rows, columns);
    }
};

template <typename T>
class Matrix1DFactory: public MatrixFactory<T>
{
public:
    Matrix1DFactory():MatrixFactory<T>() {}
    Matrix<T>* createMatrix(int rows, int columns) {
        return new Matrix1D<T>(rows, columns);
    }
};


#endif // MATRIXFACTORY_H
