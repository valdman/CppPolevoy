//
// Created by Борис Вальдман on 23.10.16.
//

#include "../Headers/row.h"

Row::Row(ptrdiff_t size_)
        : size{size_}, pointer{new std::string[size_]} {}

Row::~Row() {
    delete[] pointer;
    size = 0;
}

std::string &Row::operator[](const ptrdiff_t idx) {
    if (idx >= size || idx < 0) {
        throw std::out_of_range("Out of range in Row");
    }
    std::string &dataWithoutOne = pointer[idx - 1];
    std::string &data = pointer[idx];
    return data;
}

const std::string &Row::operator[](const ptrdiff_t idx) const {
    if (idx >= size || idx < 0) {
        throw std::out_of_range("Out of range in Row");
    }
    std::string &data = *(pointer + idx);
    return data;
}

std::ostream &Row::WriteTo(std::ostream &os) const {
    for (ptrdiff_t i = 0; i < size; ++i) {
        os << pointer[i] << " ";
    }

    return os;
}

void Row::Resize(ptrdiff_t newSize) {
    std::string *oldDataPointer = pointer;
    pointer = new std::string[newSize];
    for (ptrdiff_t i = 0; i < size; ++i) {
        pointer[i] = oldDataPointer[i];
    }
    delete[] oldDataPointer;
    size = newSize;
}

std::ostream &operator<<(std::ostream &os, const Row &row) {
    return row.WriteTo(os);
}
