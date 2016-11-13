#include "Headers/ssv.h"

using namespace std;

int main() {
    const int row(5), columns(9);
    Ssv testSsv(columns, row);

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < columns; ++j) {
            testSsv[i][j] = "str№[" + std::to_string(i) + ", " + std::to_string(j) + "], ";
        }
    }

    cout << testSsv << endl;
    return 0;
}