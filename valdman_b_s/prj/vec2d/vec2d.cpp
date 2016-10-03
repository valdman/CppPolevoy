#include "vec2d.h"
#include <stdexcept>

Vec2d& Vec2d::operator+=(const Vec2d& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2d& Vec2d::operator-=(const Vec2d& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vec2d& Vec2d::operator*=(const double rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

Vec2d& Vec2d::operator/=(const double rhs)
{
    if (rhs < 1E-6) {
        throw std::invalid_argument("Divide by zero in Vec2d");
    }

    x /= rhs;
    y /= rhs;
    return *this;
}

Vec2d Vec2d::operator+(const Vec2d& value) 
{
    Vec2d ans{ *this };
    ans += value;
    return ans;
}

Vec2d Vec2d::operator-(const Vec2d& value)
{
    Vec2d ans{ *this };
    ans -= value;
    return ans;
}

Vec2d Vec2d::operator*(const double value)
{
    Vec2d ans{ *this };
    ans *= value;
    return ans;
}

Vec2d Vec2d::operator/(const double value)
{
    Vec2d ans{ *this };
    ans /= value;
    return ans;
}

double&  Vec2d::operator[](const int idx) 
{
    switch (idx)
    {
    case(0):
        return x;
        break;

    case(1):
        return y;
        break;

    default:
        throw std::out_of_range("Out of range in Vec2d");
        break;
    }
}

double Vec2d::operator[](const int idx) const
{
    switch (idx)
    {
    case(0):
        return x;
        break;

    case(1):
        return y;
        break;

    default:
        throw std::out_of_range("Out of range in Vec2d");
        break;
    }
}