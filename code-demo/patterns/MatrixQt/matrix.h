#ifndef MATRIX_H
#define MATRIX_H

template< typename T>
class Matrix
{
protected:
    int rows;
    int columns;
public:
    Matrix(int rows, int columns):rows(rows),columns(columns){}
    virtual T get(int row, int col)=0;
    virtual void set(int row, int col, T val)=0;

};

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
    T get(int row, int col) override {
        return arr[row][col];
    }
    void set(int row, int col, T val) override {
        arr[row][col] = val;
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
    T get(int row, int col) override {
        return arr[row*this->columns+col];
    }
    void set(int row, int col, T val) override {
        arr[row*this->columns+col] = val;
    }
 };


#endif // MATRIX_H
