#ifndef HG_VEC2D_H_20161003
#define HG_VEC2D_H_20161003

#include <iostream>
#include <cstdlib>

class Vec2d
{
public:
    Vec2d() = default;
    Vec2d(const double x_, const double y_) : x{ x_ }, y{ y_ } {};

    ~Vec2d() = default;

    Vec2d& operator=(const Vec2d& rhs) = default;
    Vec2d& operator+=(const Vec2d& rhs);
    Vec2d& operator-=(const Vec2d& rhs);

    Vec2d& operator*=(const double rhs);
    Vec2d& operator/=(const double rhs);


    Vec2d operator+(const Vec2d& value);
    Vec2d operator-(const Vec2d& value);

    Vec2d operator/(const double value);
    Vec2d operator*(const double value);

    
    double operator[](const int idx) const;
    double& operator [](const int idx);

    std::ostream& writeTo(std::ostream& ostrm) const;

    double static abs(Vec2d vectr)
    {
        return std::sqrt(scalar_multiply(vectr, vectr));
    }

    double static scalar_multiply(const Vec2d& first, const Vec2d& second)
    {
        return first[0] * second[0] + first[1] * second[1];
    }

    double static pseudoscalar_multiply(const Vec2d& first, const Vec2d& second)
    {
        return first[0] * second[1] - first[1] * second[0];
    }

public:
    double x{ 0 };
    double y{ 0 };
};

std::ostream& operator<<(std::ostream& ostrm, Vec2d obj);


#endif // !HG_VEC2D_H_20161003

