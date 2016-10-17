#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    int firstNumber = a;
    int secondNumber = b;

    int c;
    while (secondNumber)
    {
        c = firstNumber % secondNumber;
        firstNumber = secondNumber;
        secondNumber = c;
    }

    return(firstNumber);
}

int main()
{
    cout << "gcd(144, 60) = " << gcd(144, 60)  << endl;
    cout << "gcd(77, 77) = " << gcd(77, 77)<< endl;
    cout << "gcd(-11, 77) = "  << gcd(-11, 77) << endl;
    cout << "gcd(-12, -4) = " << gcd(-12, -4) << endl;
}