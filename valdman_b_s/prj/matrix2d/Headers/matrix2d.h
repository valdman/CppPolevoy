//
// Created by Борис Вальдман on 24.10.16.
//

#ifndef MATRIX2D_MATRIX2D_H
#define MATRIX2D_MATRIX2D_H


#include <cstddef>
#include <iosfwd>
#include <string>

class Matrix2d {

public:
    Matrix2d() = delete;
    Matrix2d(ptrdiff_t rowNumber, ptrdiff_t columnNumber);

    ~Matrix2d();

    Matrix2d& operator=(const Matrix2d& rhs);
    int& at(ptrdiff_t rowIdx, ptrdiff_t columnIdx);

    void saveToFile(const std::string& path, std::ofstream& os);
    void loadFromFile(const std::string& path, std::ifstream& is);

private:
    int* dataArrayPointer {nullptr};
    ptrdiff_t rowNumber_ {0};
    ptrdiff_t columnNumber_ {0};
};

#endif //MATRIX2D_MATRIX2D_H
