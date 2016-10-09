#ifndef HG_RATIONAL_H_20160926
#define HG_RATIONAL_H_20160926

#include <iostream>
#include <cstdint>

class Rational
{
public:
    Rational();
    Rational(const int number);
    Rational(const int divided, const int dividor);

    //operators
    Rational& operator+=(const Rational& value);
    Rational& operator-=(const Rational& value);
    Rational& operator/=(const Rational& value);
    Rational& operator*=(const Rational& value);

    bool IsPositive();

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double toDouble();


private:
    int32_t _numerator{ 0 };
    int32_t _denumerator{ 1 };

    int32_t gcd(const int32_t a, const int32_t b);
    void _normalize();
};

Rational operator+(const Rational& left, const Rational& right);
Rational operator-(const Rational& left, const Rational& right);
Rational operator/(const Rational& left, const Rational& right);
Rational operator*(const Rational& left, const Rational& right);

bool operator>(const Rational& left, const Rational& right);
bool operator<(const Rational& left, const Rational& right);
bool operator>=(const Rational& left, const Rational& right);
bool operator<=(const Rational& left, const Rational& right);
bool operator==(const Rational& left, const Rational& right);
bool operator!=(const Rational& left, const Rational& right);

std::ostream& operator<<(std::ostream& ostr, Rational obj);
std::istream& operator>>(std::istream& istrm, Rational& obj);

#endif