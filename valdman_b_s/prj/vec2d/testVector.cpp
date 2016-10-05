#include <iostream>
#include "vec2d.h"

using namespace std;

int main()
{
    Vec2d first{ 2, 3 }, second{ -5 , -7 }, third{ 3, 4 };

    cout << "a = " << first << "; first = Vec2d{ 12, -8 }; ";
    first = Vec2d{ 12, -8 };
    cout << "a = " << first << endl << endl;

    cout << "a = " << first << "; b= " << second << "; c= " <<third << endl;
    cout << "a+b+c = " << (first + second + third) << endl;
    cout << "a-b = " << (first - second) << endl;
    cout << "a*b (scalar) = " << Vec2d::scalar_multiply(first, second) << endl;
    cout << "a*b (pseudoscalar) = " << Vec2d::pseudoscalar_multiply(first, second) << endl << endl;

    cout << "a*4 = " << first * 4 << endl;
    cout << "a*(-3) = " << first * (-3) << endl << endl;

    cout << "length of " << third << "= " << Vec2d::abs(third) << endl;
    return 0;
}