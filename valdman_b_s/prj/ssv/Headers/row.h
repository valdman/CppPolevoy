//
// Created by Борис Вальдман on 23.10.16.
//

#ifndef SSV_ROW_H
#define SSV_ROW_H


#include <vector>
#include <string>
#include <iosfwd>

class Row {
public:
    Row() = default;

    ~Row() = default;

    ptrdiff_t getSize() { return data.size(); };

    std::ostream &writeTo(std::ostream &os) const {
        for (ptrdiff_t i = 0; i < data.size(); ++i) {
            os << data[i];
        }
        return os;
    };

public:
    std::vector<std::string> data;
};

std::ostream &operator<<(std::ostream &os, const Row &row) {
    row.writeTo(os);
    return os;
};


#endif //SSV_ROW_H
