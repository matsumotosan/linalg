#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

template<typename T>
class Matrix {
    private:
        std::vector<std::vector<T> > mat;
        unsigned rows;
        unsigned cols;

    public:
        Matrix(unsigned _rows, unsigned _cols, const T& _initial);
        Matrix(const Matrix<T>& rhs);
        virtual ~Matrix();

        // operator overloading
        Matrix<T>& operator=(const Matrix<T>& rhs);

        // matrix-scalar operations
        Matrix<T> operator+(const T& rhs);
        Matrix<T> operator-(const T& rhs);
        Matrix<T> operator*(const T& rhs);
        Matrix<T> operator/(const T& rhs);

        // matrix-vector operations
        std::vector<T> operator*(const std::vector<T>& rhs);
        std::vector<T> diag_vec();

        // matrix-matrix operations
        Matrix<T> operator+(const Matrix<T>& rhs);
        Matrix<T> operator-(const Matrix<T>& rhs);
        Matrix<T> operator*(const Matrix<T>& rhs);

        Matrix<T>& operator+=(const Matrix<T>& rhs);
        Matrix<T>& operator-=(const Matrix<T>& rhs);
        Matrix<T>& operator*=(const Matrix<T>& rhs);

        Matrix<T> transpose();

        // access elements
        T& operator()(const unsigned& row, const unsigned& col);
        const T& operator()(const unsigned& row, const unsigned& col) const;

        // return number of rows and columns
        unsigned get_rows() const;
        unsigned get_cols() const;
};

#include "matrix.cpp"

#endif
