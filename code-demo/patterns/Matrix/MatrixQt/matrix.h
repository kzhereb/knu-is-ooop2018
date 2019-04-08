#ifndef MATRIX_H
#define MATRIX_H

#include "matrixmultiplicationalgorithm.h"

template< typename T>
class Matrix
{
protected:
    int _rows;
    int _columns;
    MatrixMultiplicationAlgorithm<T> * multiply_algorithm;
public:
    Matrix(int rows, int columns);
    virtual T get(int row, int col) const =0;
    virtual void set(int row, int col, T val)=0;
    virtual Matrix<T>* createMatrix(int rows, int columns) const = 0;
    Matrix<T>* operator*(const Matrix<T>& other);

    int rows() const { return _rows;}
    int columns() const { return _columns;}

};

#include "matrixmultiplyimplementation.h"

template<typename T>
Matrix<T>::Matrix(int rows, int columns):_rows(rows),_columns(columns){
    multiply_algorithm = new SimpleMultiplication<T>;
}

template<typename T>
Matrix<T> *Matrix<T>::operator*(const Matrix<T> &other) {

    return this->multiply_algorithm->multiply(this,&other);
    //        if (this->columns != other.rows) {
    //            throw incompatible_matrices("Multiply for matrices with wrong sizes");
    //        }
    //        Matrix<T>* result = createMatrix(this->rows, other.columns);
    //        for(int i=0;i<this->rows;i++) {
    //            for (int j=0; j<other.columns;j++) {
    //                T sum = 0;
    //                for (int k=0; k<this->columns;k++) {
    //                    sum += (this->get(i,k)) * (other.get(k,j));
    //                }
    //                result->set(i,j,sum);
    //            }
    //        }
    //        return result;
}

template< typename T>
class Matrix2D: public Matrix<T>
{
private:
    T** arr;
public:
    Matrix2D(int rows, int columns): Matrix<T>(rows,columns) {
        arr = new T* [rows];
        for(int i =0;i<rows;i++) {
            arr[i] = new T[columns];
        }
    }
    T get(int row, int col) const override {
        return arr[row][col];
    }
    void set(int row, int col, T val) override {
        arr[row][col] = val;
    }
    Matrix2D<T>* createMatrix(int rows, int columns) const override {
        return new Matrix2D<T>(rows, columns);
    }
};

template< typename T>
class Matrix1D: public Matrix<T>
{
private:
    T* arr;
public:
    Matrix1D(int rows, int columns):Matrix<T>(rows,columns) {
        arr = new T [rows*columns];
    }
    T get(int row, int col) const override {
        return arr[row*this->columns()+col];
    }
    void set(int row, int col, T val) override {
        arr[row*this->columns()+col] = val;
    }
    Matrix1D<T>* createMatrix(int rows, int columns) const override {
        return new Matrix1D<T>(rows, columns);
    }
 };


#endif // MATRIX_H
