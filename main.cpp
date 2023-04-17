#include "matrix.h"
#include <iostream>

int main(int argc, char **argv) {
    Matrix<double> mat1(5, 5, 1.0);
    Matrix<double> mat2(5, 5, 2.0);
    Matrix<double> mat3 = mat1 + mat2;
    
    std::cout << "mat1\n";
    for (int i = 0; i < mat1.get_rows(); i++) {
        for (int j = 0; j < mat1.get_cols(); j++) {
            std::cout << mat1(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "mat2\n";
    for (int i = 0; i < mat2.get_rows(); i++) {
        for (int j = 0; j < mat2.get_cols(); j++) {
            std::cout << mat2(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "mat1 + mat2\n";
    for (int i = 0; i < mat3.get_rows(); i++) {
        for (int j = 0; j < mat3.get_cols(); j++) {
            std::cout << mat3(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    Matrix<double> mat4(2, 3, 1.0);
    Matrix<double> mat5(3, 2, 2.0);
    Matrix<double> mat6 = mat4 * mat5;

    std::cout << "mat4\n";
    for (int i = 0; i < mat4.get_rows(); i++) {
        for (int j = 0; j < mat4.get_cols(); j++) {
            std::cout << mat4(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "mat5\n";
    for (int i = 0; i < mat5.get_rows(); i++) {
        for (int j = 0; j < mat5.get_cols(); j++) {
            std::cout << mat5(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "mat4 * mat5\n";
    for (int i = 0; i < mat6.get_rows(); i++) {
        for (int j = 0; j < mat6.get_cols(); j++) {
            std::cout << mat6(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;


    Matrix<double> mat7(3, 2, 1.0);
    Matrix<double> mat8 = mat7.transpose();
    
    std::cout << "mat7\n";
    for (int i = 0; i < mat7.get_rows(); i++) {
        for (int j = 0; j < mat7.get_cols(); j++) {
            std::cout << mat7(i, j) << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "mat7.T\n";
    for (int i = 0; i < mat8.get_rows(); i++) {
        for (int j = 0; j < mat8.get_cols(); j++) {
            std::cout << mat8(i, j) << ", ";
        }
        std::cout << std::endl;
    }

    return 0;
}
