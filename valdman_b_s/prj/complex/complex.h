#ifndef HG_COMPLEX_H_20160926
#define HG_COMPLEX_H_20160926

struct Complex
{
    Complex() = default;
    explicit Complex(const double real);
    Complex(const double real, const double imaginary);

    bool operator==(const Complex& rhs) const { return (abs(re - rhs.re) < 1E-6) && (abs(im - rhs.im) < 1E-6); }
    bool operator!=(const Complex& rhs) const { return !operator==(rhs); }

    Complex& operator+=(const Complex& rhs);
    Complex& operator+=(const double rhs);
    Complex& operator-=(const Complex& rhs);
    Complex& operator-= (const double rhs);
    Complex& operator*=(const Complex& rhs);
    Complex& operator*=(const double rhs);
    Complex& operator/=(const double rhs);

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    double re{ 0.0 };
    double im{ 0.0 };
    static const char leftBrace{ '{' };
    static const char separator{ ',' };
    static const char rightBrace{ '}' };
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

Complex operator+(const Complex& lhs, const double rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator/(const Complex& lhs, const double rhs);

std::ostream& operator<< (std::ostream& ostrm, const Complex& rhs);
std::istream& operator >> (std::istream& istrm, Complex& rhs);

#endif // HG_COMPLEX_H_20160926
