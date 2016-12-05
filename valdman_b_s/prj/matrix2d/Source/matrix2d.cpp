//
// Created by Борис Вальдман on 24.10.16.
//

#include <stdexcept>
#include "../Headers/matrix2d.h"

Matrix2d::Matrix2d(ptrdiff_t rowNumber, ptrdiff_t columnNumber)
{
    columnNumber_ = columnNumber;
    rowNumber_ = rowNumber;

    dataArrayPointer = new int[rowNumber * columnNumber];
}

Matrix2d::~Matrix2d()
{
    columnNumber_ = rowNumber_ = 0;

    delete dataArrayPointer;
}

Matrix2d &Matrix2d::operator=(const Matrix2d &rhs)
{
    columnNumber_ = rhs.columnNumber_;
    rowNumber_ = rhs.rowNumber_;

    long cellNumber {rhs.rowNumber_ * rhs.columnNumber_};
    delete[] dataArrayPointer;
    dataArrayPointer = new int[cellNumber];

    for (ptrdiff_t i = 0; i < cellNumber; ++i) {
        *(dataArrayPointer + i) = *(rhs.dataArrayPointer + i);
    }
    return *this;
}

int &Matrix2d::at(ptrdiff_t rowIdx, ptrdiff_t columnIdx)
{
    if(rowIdx >= rowNumber_ || columnIdx >= columnNumber_ || rowIdx < 0 || columnIdx < 0) {
        throw std::out_of_range("Out of range in Matrix2d");
    }

    return *(dataArrayPointer + columnIdx * rowIdx + columnIdx);
}

void Matrix2d::saveToFile(const std::string &path, std::ofstream &os)
{

}

void Matrix2d::loadFromFile(const std::string &path, std::ifstream &is)
{

}
