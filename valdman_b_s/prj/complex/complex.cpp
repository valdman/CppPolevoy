#include <iostream>
#include <sstream>

struct Complex {
    Complex() {}

    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    bool operator==(const Complex& rhs) const { return (re - rhs.re < 1E-5) && (im - rhs.im < 1E-5); }
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

    Complex& operator+=(const Complex& rhs)
    {
        re += rhs.re;
        im += rhs.im;
        return *this;
    }

    Complex& operator+=(const double rhs)
    {
        return operator+=(Complex(rhs));
    }

    Complex& operator-=(const Complex& rhs)
    {
        re -= rhs.re;
        im -= rhs.im;
        return *this;
    }

    Complex& operator-=(const double rhs)
    {
        return operator-=(Complex(rhs));
    }

    Complex& operator*=(const Complex& rhs)
    {
        re = re * rhs.re - im * rhs.im;
        im = re * rhs.im + im * rhs.re;
        return *this;
    };

    Complex& operator*=(const double rhs)
    {
        re *= rhs;
        im *= rhs;
        return *this;
    };

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

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

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator >> (std::istream& istrm, Complex& rhs)
{
    return rhs.readFrom(istrm);
}

bool testParse(const std::string& str)
{
    using namespace std;
    istringstream istrm(str);
    Complex z;
    istrm >> z;
    if (istrm.good()) {
        cout << "Read success: " << str << " -> " << z << endl;
    }
    else {
        cout << "Read error : " << str << " -> " << z << endl;
    }
    return istrm.good();
}

int main()
{
    using namespace std;

    Complex z;
    z += Complex(8.0);
    testParse("{8.9,9}");
    testParse("{8.9, 9}");
    testParse("{8.9,9");

    return 0;
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