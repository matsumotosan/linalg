#ifndef MATRIX_CPP
#define MATRIX_CPP

#include "matrix.h"

// Parameter costructor
template <typename T>
Matrix<T>::Matrix(unsigned _rows, unsigned _cols, const T& _initial) {
    mat.resize(_rows);
    for (unsigned i = 0; i < mat.size(); i++) {
        mat[i].resize(_cols, _initial);
    }
    rows = _rows;
    cols = _cols;
}

// Copy constructor
template <typename T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    mat = rhs.mat;
    rows = rhs.get_rows();
    cols = rhs.get_cols();
}

// Destructor
template <typename T>
Matrix<T>::~Matrix() {}

// Assignment operator
template <typename T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T>& rhs) {
    if (&rhs == this)
        return *this;

    unsigned new_rows = rhs.get_rows();
    unsigned new_cols = rhs.get_cols();

    mat.resize(new_rows);
    for (unsigned i = 0; i < mat.size(); i++) {
        mat[i].resize(new_cols);
    }

    for (unsigned i = 0; i < new_rows; i++) {
        for (unsigned j = 0; j < new_cols; j++) {
            mat[i][j] = rhs(i, j);
        }
    }

    rows = new_rows;
    cols = new_cols;
    return *this;
}

// Matrix-scalar addition
template <typename T>
Matrix<T> Matrix<T>::operator+(const T& rhs) {
    Matrix result(rows, cols, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->mat[i][j] + rhs;
        }
    }
    return result;
}

// Matrix-scalar subtraction
template <typename T>
Matrix<T> Matrix<T>::operator-(const T& rhs) {
    Matrix result(rows, cols, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->mat[i][j] - rhs;
        }
    }
    return result;
}

// Matrix-scalar multiplication
template <typename T>
Matrix<T> Matrix<T>::operator*(const T& rhs) {
    Matrix result(rows, cols, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->mat[i][j] * rhs;
        }
    }
    return result;
}

// Matrix-scalar division
template <typename T>
Matrix<T> Matrix<T>::operator/(const T& rhs) {
    Matrix result(rows, cols, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->mat[i][j] / rhs();
        }
    }
    return result;
}

// Matrix-vector multiplication
template <typename T>
std::vector<T> Matrix<T>::operator*(const std::vector<T>& rhs) {
    std::vector<T> result(rhs.size(), 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result[i] = this->mat[i][j] * rhs[j];
        }
    }
}

// Matrix-matrix addition
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) {
    Matrix result(rows, cols, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(i, j) = this->mat[i][j] + rhs(i, j);
        }
    }
    return result;
}

// Matrix-matrix cumulative addition
template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T>& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            this->mat[i][j] += rhs(i, j);
        }
    }
    return *this;
}

// Matrix multiplication
template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& rhs) {
    unsigned l = this->rows;
    unsigned m = this->cols;
    unsigned m_ = rhs.get_rows();
    unsigned n = rhs.get_cols();

    Matrix result(l, n, 0.0);

    for (unsigned k = 0; k < m; k++) {
        for (unsigned i = 0; i < n; i++) {
            for (unsigned j = 0; j < rows; j++) {
                result(i, j) += this->mat[i][k] * rhs(k, j);
            }
        }
    }
    return result;
}

// Cumulative left multiplication
template <typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix<T>& rhs) {
    Matrix result = (*this) * rhs;
    (*this) = result;
    return *this;
}

// Access individual elements
template <typename T>
T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) {
    return this->mat[row][col];
}

// Access individual elements (const)
template <typename T>
const T& Matrix<T>::operator()(const unsigned& row, const unsigned& col) const {
    return this->mat[row][col];
}

// Return transpose of matrix
template<typename T>
Matrix<T> Matrix<T>::transpose() {
    unsigned rows = this->rows;
    unsigned cols = this->cols;

    Matrix result(cols, rows, 0.0);

    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols; j++) {
            result(j, i) = this->mat[i][j];
        }
    }
    return result;
}

// Return diagonal of matrix
template <typename T>
std::vector<T> Matrix<T>::diag_vec() {
    std::vector<T> result(rows, 0.0);
    for (unsigned i = 0; i < rows; i++) {
        result[i] = this->mat[i][i];
    }
    return result;
}

// Return number of rows of matrix
template <typename T>
unsigned Matrix<T>::get_rows() const {
    return this->rows;
}

// Return number of columns of matrix
template <typename T>
unsigned Matrix<T>::get_cols() const {
    return this->cols;
}

#endif
