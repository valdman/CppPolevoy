#include <cmath>
#include <stdexcept>
#include "rational.h"

using namespace std;


Rational::Rational() {};

Rational::Rational(const int number) : _numerator{ number } {}

Rational::Rational(const int divided, const int dividor) : _numerator{ divided }, _denumerator{ dividor }
{
    if (!dividor) {
        throw invalid_argument("Zero denumerator in Rational");
    }

    _normalize();
}


Rational& Rational::operator+=(const Rational& value)
{
    _numerator = _numerator * value._denumerator + _denumerator * value._numerator;
    _denumerator *= value._denumerator;
    _normalize();
    return *this;
}

Rational& Rational::operator-=(const Rational& value)
{
    _numerator = _numerator * value._denumerator - _denumerator * value._numerator;
    _denumerator *= value._denumerator;
    _normalize();
    return *this;
}

Rational& Rational::operator/=(const Rational& value)
{
    _numerator *= value._denumerator;
    _denumerator *= value._numerator;
    _normalize();
    return *this;
}

Rational& Rational::operator*=(const Rational& value)
{
    _numerator *= value._numerator;
    _denumerator *= value._denumerator;
    _normalize();
    return *this;
}

bool Rational::IsPositive()
{
    return (_numerator > 0) == (_denumerator > 0);
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
    int32_t nod = gcd(_numerator, _denumerator);
    _numerator /= nod;
    _denumerator /= nod;
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
    ostrm << _numerator << "/" << _denumerator;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm)
{
    int32_t divided(0);
    char slash(0);
    int32_t dividor(0);
    istrm >> divided >> slash >> dividor;
    if (istrm.good()) {
        if ((Rational::_numerator == divided) && (Rational::_denumerator == dividor)) {
            _numerator = divided;
            _denumerator = dividor;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}

double Rational::toDouble() {
    return _numerator / (double_t )_denumerator;
}

std::ostream& operator<<(std::ostream& ostr, Rational obj)
{
    return obj.writeTo(ostr);
}

std::istream& operator >> (std::istream& istrm, Rational& obj)
{
    return obj.readFrom(istrm);
}

bool operator==(const Rational &left, const Rational &right) {
    Rational difference = right - left;
    return fabs(difference.toDouble()) < 1E-6;
}

bool operator!=(const Rational &left, const Rational &right) {
    return !operator==(left, right);
}
