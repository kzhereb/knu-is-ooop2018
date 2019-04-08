#ifndef MATRIXMULTIPLICATIONALGORITHM_H
#define MATRIXMULTIPLICATIONALGORITHM_H

//#include "matrix.h"
#include "matrix_exceptions.h"

template< typename T> class Matrix;

template< typename T>
class MatrixMultiplicationAlgorithm
{
public:
    MatrixMultiplicationAlgorithm() =default;
    virtual Matrix<T>* multiply(const Matrix<T>* left, const Matrix<T>* right) const =0;
};






#endif // MATRIXMULTIPLICATIONALGORITHM_H
