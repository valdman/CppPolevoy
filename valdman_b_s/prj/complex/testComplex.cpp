#include <iostream>
#include <sstream>
#include "complex.h"

using namespace std;

bool testParse(const std::string& str)
{
    std::istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    } else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}

void runArufmeticsTests(Complex a, Complex b)
{
    cout << "Arifmetics tests: " << endl;
    Complex z(a), j(b);

    cout << "Z = " << z << "; Z += {8, 2}; Z = ";
    z += Complex{ 8, 2 };
    cout << z << endl;

    cout << j << " + " << z << " = " << (j + z) << endl;
    cout << j << " - " << z << " = " << (j - z) << endl;
    cout << j << " * " << z << " = " << (j * z) << endl;
    cout << j << " equal to " << z << " = " << (j == z) << endl;
    cout << j << " not equal to " << z << " = " << (j != z) << endl;

    cout << j << " + " << 3 << " = " << (j + 3) << endl;
    cout << j << " - " << 5 << " = " << (j - 5) << endl;
    cout << j << " * " << 2 << " = " << (j * 2) << endl << endl;
}

void runParseTest()
{
    cout << endl << "Parse tests: " << endl;

    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");
}

int main()
{
    runArufmeticsTests({ 1,1 }, { 8, 2 });

    cout << endl;

    runParseTest();

    return 0;
}