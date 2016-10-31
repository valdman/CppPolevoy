//
// Created by Борис Вальдман on 31.10.16.
//

#include <stdexcept>
#include "arrstack.h"

ArrStack::~ArrStack()
{
    delete[] data;
}

ArrStack& ArrStack::operator=(const ArrStack &rhs)
{
    if (&rhs != this)
    {
        delete[] data;
        capasity = rhs.capasity;
        cursor = rhs.cursor;
        data = new double[rhs.capasity];
        for (int i = 0; i < rhs.capasity; ++i) {
            data[i] = rhs.data[i];
        }
    }
    return *this;
}

const double& ArrStack::Pop()
{
    if (cursor <= -1) {
        throw std::out_of_range("Out of stack");
    }
    return data[cursor--];
}

void ArrStack::Push(const double& value)
{
    if (cursor >= capasity || capasity == 0) {
        Resize(capasity + 10);
    }
    data[++cursor] = value;
}

const double& ArrStack::Check() const
{
    if (cursor < 0) {
        throw std::out_of_range("Out of stack");
    }
    return data[cursor];
}

void ArrStack::Resize(const ptrdiff_t newSize)
{
    double* newData = new double[newSize];
    for (int i = 0; i < capasity; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capasity = newSize;
}

ArrStack::ArrStack(ArrStack &stack)
    : cursor{stack.cursor}
    , capasity{stack.capasity}
    , data{new double[stack.capasity]}
{
    for (int i = 0; i < cursor + 1; ++i) {
        data[i] = stack.data[i];
    }
}


