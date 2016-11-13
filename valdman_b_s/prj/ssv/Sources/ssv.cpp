//
// Created by Борис Вальдман on 22.10.16.
//

#include "../Headers/ssv.h"

Ssv::Ssv(ptrdiff_t columnNumber_, ptrdiff_t rowNumber_)
        : columnNumber{columnNumber_}, rowNumber{rowNumber_}, pointer{new Row[rowNumber_]} {
    for (ptrdiff_t i = 0; i < rowNumber; ++i) {
        pointer[i].Resize(columnNumber_);
    }
}

Ssv::~Ssv() {
    delete[] pointer;
}

Ssv &Ssv::operator=(const Ssv &rhs) {
    if (this != &rhs) {
        columnNumber = rhs.columnNumber;
        rowNumber = rhs.rowNumber;

        delete[] pointer;
        pointer = new Row[rhs.rowNumber];
        for (int i = 0; i < rhs.rowNumber; ++i) {
            pointer[i] = rhs[i];
        }
    }
    return *this;
}

const Row &Ssv::operator[](std::ptrdiff_t idx) const {
    return pointer[idx];
}

Row &Ssv::operator[](std::ptrdiff_t idx) {
    return pointer[idx];
}

std::ostream &Ssv::WriteTo(std::ostream &ostrm) const {
    for (ptrdiff_t i = 0; i < rowNumber; ++i) {
        ostrm << pointer[i] << std::endl;
    }

    return ostrm;
}


std::ostream &operator<<(std::ostream &ostrm, const Ssv &ssv) {
    return ssv.WriteTo(ostrm);
}
