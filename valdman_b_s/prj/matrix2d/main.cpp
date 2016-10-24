#include <iostream>
#include "matrix2d.h"

int main() {
    const int rowNumber{20};
    const int columnNumber{20};
    Matrix2d matrix{rowNumber, columnNumber};

    for (ptrdiff_t i = 0; i < rowNumber; ++i) {
        for (ptrdiff_t j = 1; j < columnNumber; ++j) {
            matrix.at(i, j) = i * j + j;
            std::cout << matrix.at(i, j) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;


    Matrix2d matrix2 {rowNumber, columnNumber};

    for (int i = 0; i < 100000; ++i) {
        matrix2 = matrix2;
        matrix2 = matrix;
    }

    for (ptrdiff_t i = 0; i < rowNumber; ++i) {
        for (ptrdiff_t j = 1; j < columnNumber; ++j) {
            std::cout << matrix2.at(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}