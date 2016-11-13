//
// Created by Борис Вальдман on 23.10.16.
//

#ifndef SSV_ROW_H
#define SSV_ROW_H


#include <cstddef>
#include <string>
#include <iostream>

class Row {
public:
    Row() = default;

    Row(ptrdiff_t size_);

    ~Row();

    std::string &operator[](const ptrdiff_t idx);

    const std::string &operator[](const ptrdiff_t idx) const;

    void Resize(ptrdiff_t new_size);

    std::ostream &WriteTo(std::ostream &os) const;

private:
    ptrdiff_t size{0};
    std::string *pointer{nullptr};

};

std::ostream &operator<<(std::ostream &os, const Row &row);


#endif //SSV_ROW_H
