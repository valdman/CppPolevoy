#include "rational.h"

#include <iostream>
#include <cstdint>

using namespace std;


Rational::Rational() {};

Rational::Rational(const int number) : _divided{ number } {}

Rational::Rational(const int divided, const int dividor) : _divided{ divided }, _dividor{ dividor }
{
    if (!dividor) {
        throw invalid_argument("Zero denumerator in Rational");
    }

    _normalize();
}


Rational& Rational::operator+=(const Rational& value)
{
    _divided = _divided * value._dividor + _dividor * value._divided;
    _dividor *= value._dividor;
    _normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& value)
{
    _divided = _divided * value._dividor - _dividor * value._divided;
    _dividor *= value._dividor;
    _normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& value)
{
    _divided *= value._dividor;
    _dividor *= value._divided;
    _normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& value)
{
    _divided *= value._divided;
    _dividor *= value._dividor;
    _normalize();
    return *this;
}

bool Rational::IsPositive()
{
    return _divided > 0 == _dividor > 0;
}

bool Rational::IsZero()
{
    return _divided == 0;
};

int32_t Rational::gcd(const int32_t a, const int32_t b)
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

    return(abs(firstNumber));
}

void Rational::_normalize()
{
    int32_t nod = gcd(_divided, _dividor);
    _divided /= nod;
    _dividor /= nod;
}


Rational operator+(const Rational& left, const Rational& right)
{
    Rational answer{ left };

    answer += right;
    return answer;
}

Rational operator-(const Rational& left, const Rational& right)
{
    Rational answer{ left };

    answer -= right;
    return answer;
}

Rational operator*(const Rational& left, const Rational& right)
{
    Rational answer{ left };

    answer *= right;
    return answer;
}

Rational operator/(const Rational& left, const Rational& right)
{
    Rational answer{ left };

    answer /= right;
    return answer;
}

bool operator>(const Rational& left, const Rational& right)
{
    Rational tmp{ left };

    tmp -= right;
    return tmp.IsPositive();
}

bool operator<(const Rational& left, const Rational& right)
{
    Rational tmp{ left };

    tmp -= right;
    return !tmp.IsPositive();
}

bool operator>=(const Rational& left, const Rational& right)
{
    return !(left < right);
}

bool operator<=(const Rational& left, const Rational& right)
{
    return !(left > right);
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << _divided << "/" << _dividor;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int32_t divided(0);
    char slash(0);
    int32_t dividor(0);
    istrm >> divided >> slash >> dividor;
    if (istrm.good()) {
        if ((Rational::_divided == divided) && (Rational::_dividor == dividor)) {
            _divided == divided;
            _dividor == dividor;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}

std::ostream& operator<<(std::ostream& ostr, Rational obj)
{
    return obj.writeTo(ostr);
}

std::istream& operator >> (std::istream& istrm, Rational& obj)
{
    return obj.readFrom(istrm);
}