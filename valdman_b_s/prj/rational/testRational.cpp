#include <iostream>
#include "rational.h"

using namespace std;

int main()
{
    Rational firstNumber{ 5, 2 };
    Rational secondNumber{ 7, 8 };
    Rational zero{ 0 };

    cout << "Trying to create Rational with zero denuminator ";
    try {
        Rational err{ 1, 0 };
    } catch (std::invalid_argument ex) {
        std::cout << "- Exception caught!" << endl;
    }

    cout << firstNumber << " + " << secondNumber << " = " << (firstNumber + secondNumber) << endl;
    cout << firstNumber << " - " << secondNumber << " = " << (firstNumber - secondNumber) << endl;
    cout << firstNumber << " * " << secondNumber << " = " << (firstNumber * secondNumber) << endl;
    cout << firstNumber << " / " << secondNumber << " = " << (firstNumber / secondNumber) << endl;

    cout << firstNumber << " + " << 3 << " = " << (firstNumber + 3) << endl;
    cout << firstNumber << " - " << 2 << " = " << (firstNumber - 2) << endl;
    cout << firstNumber << " * " << 4 << " = " << (firstNumber * 4) << endl;
    cout << firstNumber << " / " << 3 << " = " << (firstNumber / 3) << endl;

    Rational thirdNumber{700000001, 800000000};

     cout << secondNumber << " == " << thirdNumber << "; result = " << (secondNumber == thirdNumber) << endl;

    cout << firstNumber << " >= " << secondNumber << " = " << (firstNumber >= secondNumber) << endl << endl;

    cout << secondNumber << " = (with float point) " << secondNumber.toDouble() << endl;
}