//
// Created by Борис Вальдман on 22.10.16.
//

#ifndef SSV_SSV_H
#define SSV_SSV_H

#include <string>
#include <iosfwd>
#include <vector>
#include "row.h"

class Ssv {
public:
    void addRow(const Row &rowToAdd);

    void insertRow(const Row &rowToInsert, const ptrdiff_t &idx);

    void deleteRow(const ptrdiff_t &idx);

    const Row &getRow(const ptrdiff_t &idx) const;

    Row &getRow(const ptrdiff_t &idx);

    void writeTo(std::ostream &os) const;

private:
    std::vector<Row> data;
};

inline std::ostream &operator<<(std::ostream &os, const Ssv &ssv) {
    ssv.writeTo(os);
    return os;
}

#endif //SSV_SSV_H
