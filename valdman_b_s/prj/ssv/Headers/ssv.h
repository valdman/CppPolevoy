//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_H
#define SSV_SSV_H

#include <string>
#include <iostream>
#include "row.h"

class Ssv {

public:
    Ssv() = default;

    Ssv(std::string ssv_data, char separator = ',') = delete;

    Ssv(ptrdiff_t columnNumber_, ptrdiff_t rowNumber_);

    ~Ssv();


    Ssv &operator=(const Ssv &rhs);

    const Row &operator[](std::ptrdiff_t idx) const;

    Row &operator[](std::ptrdiff_t idx);

    std::ostream &WriteTo(std::ostream &ostrm) const;

    Ssv &ReadFrom(std::istream &istrm) = delete;

private:
    Row *pointer{nullptr};
    ptrdiff_t columnNumber{0};
    ptrdiff_t rowNumber{0};

};

std::ostream &operator<<(std::ostream &ostrm, const Ssv &ssv);

std::istream &operator>>(std::istream &, Ssv &ssv);


#endif //SSV_SSV_H
