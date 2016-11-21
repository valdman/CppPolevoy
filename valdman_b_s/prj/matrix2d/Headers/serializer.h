//
// Created by Борис Вальдман on 21.11.16.
//

#ifndef MATRIX2D_SERIALIZER_H
#define MATRIX2D_SERIALIZER_H


#include "matrix2d.h"
#include <iostream>

class Serializer {

public:
    Serializer() = default;
    ~Serializer() = default;

    void serializeTo(std::istream& ostream, const Matrix2d& matrix);
    const Matrix2d& deserializeFrom(std::ostream& istream, const Matrix2d& matrix);

};


#endif //MATRIX2D_SERIALIZER_H
