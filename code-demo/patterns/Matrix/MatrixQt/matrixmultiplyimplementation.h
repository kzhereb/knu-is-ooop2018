#ifndef MATRIXMULTIPLYIMPLEMENTATION_H
#define MATRIXMULTIPLYIMPLEMENTATION_H

#include "matrixmultiplicationalgorithm.h"

template< typename T>
class SimpleMultiplication: public MatrixMultiplicationAlgorithm<T>
{
public:
    Matrix<T>* multiply(const Matrix<T>* left, const Matrix<T>* right) const override;

};

template<typename T>
Matrix<T> *SimpleMultiplication<T>::multiply(const Matrix<T> *left, const Matrix<T> *right) const
{
    if (left->columns != right->rows) {
        throw incompatible_matrices("Multiply for matrices with wrong sizes");
    }
    Matrix<T>* result = createMatrix(left->rows, right->columns);
    for(int i=0;i<left->rows;i++) {
        for (int j=0; j<right->columns;j++) {
            T sum = 0;
            for (int k=0; k<left->columns;k++) {
                sum += (left->get(i,k)) * (right->get(k,j));
            }
            result->set(i,j,sum);
        }
    }
    return result;
}

#endif // MATRIXMULTIPLYIMPLEMENTATION_H
