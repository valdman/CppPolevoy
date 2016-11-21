//
// Created by Борис Вальдман on 22.10.16.
//

#include "../Headers/ssv.h"

void Ssv::addRow(const Row &rowToAdd) {
    data.push_back(rowToAdd);
}

void Ssv::insertRow(const Row &rowToInsert, const ptrdiff_t &idx) {
    data.insert(data.cbegin() + idx, rowToInsert);
}

void Ssv::deleteRow(const ptrdiff_t &idx) {
    data.erase(data.cbegin() + idx);
}

const Row &Ssv::getRow(const ptrdiff_t &idx) const {
    return data.at(idx);
}

Row &Ssv::getRow(const ptrdiff_t &idx) {
    return data.at(idx);
}

void Ssv::writeTo(std::ostream &os) const {
    for (int i = 0; i < data.size(); ++i) {
        os << getRow(i) << " ";
    }
}