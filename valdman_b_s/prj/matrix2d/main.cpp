#include <iostream>
#include "Headers/matrix2d.h"

void bin_test();

void bin_test_write()
{

}

int main() {
    const int rowNumber{100};
    const int columnNumber{200};
    Matrix2d matrix{rowNumber, columnNumber};

    for (ptrdiff_t i = 0; i < rowNumber; ++i) {
        for (ptrdiff_t j = 1; j < columnNumber; ++j) {
            matrix.at(i, j) = i * j + j;
        }
    }

    bin_test_write();


    return 0;
}

