#include <iostream>
#include <sstream>

#include "complex.h"


Complex& Complex::operator+=(const Complex& rhs)
{
    re += rhs.re;
    im += rhs.im;
    return *this;
}

Complex& Complex::operator+=(const double rhs)
{
    return operator+=(Complex(rhs));
}

Complex& Complex::operator-=(const Complex& rhs)
{
    re -= rhs.re;
    im -= rhs.im;
    return *this;
}

Complex& Complex::operator-=(const double rhs)
{
    return operator-=(Complex(rhs));
}

Complex& Complex::operator*=(const Complex& rhs)
{
    double re0(re);
    re = re * rhs.re - im * rhs.im;
    im = re0 * rhs.im + im * rhs.re;
    return *this;
};

Complex& Complex::operator*=(const double rhs)
{
    re *= rhs;
    im *= rhs;
    return *this;
};

Complex& Complex::operator/=(const double rhs) 
{
    if (rhs < 1E-6) {
        throw std::invalid_argument("Divide by zero in Complex");
    }
    re /= rhs;
    im /= rhs;
    return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs)
{
    Complex answer(lhs);
    return answer += rhs;
};

Complex operator-(const Complex& lhs, const Complex& rhs)
{
    Complex answer(lhs);
    return answer -= rhs;
};

Complex operator*(const Complex& lhs, const Complex& rhs)
{
    Complex answer(lhs);
    return answer *= rhs;
};

Complex operator+(const Complex& lhs, const double rhs)
{
    Complex ans(lhs);
    ans += Complex{ rhs, 0 };
    return ans;
};

Complex operator-(const Complex& lhs, const double rhs)
{
    Complex ans(lhs);
    ans -= Complex{ rhs, 0 };
    return ans;
};

Complex operator*(const Complex& lhs, const double rhs)
{
    Complex ans(lhs);
    ans *= Complex{ rhs, 0 };
    return ans;
};

Complex operator/(const Complex& lhs, const double rhs)
{
    Complex ans(lhs);
    ans /= rhs;
    return ans;
};

std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

Complex::Complex(const double real)
    : Complex(real, 0.0)
{
}

Complex::Complex(const double real, const double imaginary)
    : re(real)
    , im(imaginary)
{ }

std::ostream& Complex::writeTo(std::ostream& ostrm) const
{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream& Complex::readFrom(std::istream& istrm)
{
    char leftBrace(0);
    double real(0.0);
    char comma(0);
    double imaganary(0.0);
    char rightBrace(0);
    istrm >> leftBrace >> real >> comma >> imaganary >> rightBrace;
    if (istrm.good()) {
        if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma)
            && (Complex::rightBrace == rightBrace)) {
            re = real;
            im = imaganary;

        }
        else {
            istrm.setstate(std::ios_base::failbit);

        }

    }
    return istrm;
}

bool Complex::operator==(const Complex &rhs) const
{
    return (fabs(re - rhs.re) < 1E-6) && (fabs(im - rhs.im) < 1E-6);
}

bool Complex::operator!=(const Complex &rhs) const
{
    return !operator==(rhs);
}
