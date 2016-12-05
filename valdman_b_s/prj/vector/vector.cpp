//
// Created by Борис Вальдман on 17.10.16.
//

#include "vector.h"

ptrdiff_t Vector::size() const
{
    return size_;
}

Vector::Vector(ptrdiff_t init_size)
{
    pointer_ = new double[init_size];
    size_ = init_size;
}

Vector::Vector()
{
    pointer_ = new double[0];
    size_ = 0;
}

double &Vector::operator[](const ptrdiff_t idx)
{
    if (idx >= size_) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(pointer_+idx);
}

const double &Vector::operator[](const ptrdiff_t idx) const
{
    if (idx >= size_) {
        throw std::out_of_range("Out of range in vector");
    }
    return *(pointer_+idx);
}

void Vector::resize(const ptrdiff_t size)
{
    if (size > size_) {
        Vector tmp{*this};
        delete[] pointer_;
        pointer_ = new double[size];
        *this = tmp;
        this->size_ = size;
    }
    size_ = size;
}

std::ostream& Vector::writeTo(std::ostream& ostrm) {
    for (int i = 0; i < size_; ++i) {
        ostrm << '{' << (*this)[i] << '}' << ((i != size_ - 1) ? ", " : ";" );
    }
    return ostrm;
}

Vector::~Vector() {
    delete[] pointer_;
}

Vector::Vector(const Vector &vector) {
    *this = vector;
}

Vector &Vector::operator=(const Vector &rhs) {
    if (this != &rhs) {
        delete[] pointer_;
        size_ = rhs.size_;
        pointer_ = new double[size_];
        for (int i(0); i < size_; ++i) {
            pointer_[i] = rhs[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &ostrm, Vector& obj) {
    obj.writeTo(ostrm);
    return ostrm;
}
