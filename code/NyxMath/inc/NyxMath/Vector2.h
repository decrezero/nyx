#ifndef NyxMath_Vector2_h
#define NyxMath_Vector2_h

#include <cmath>

namespace Nyx
{

class Vector2
{
public:
    static const Vector2 Zero;

    float x;
    float y;

    Vector2() { /* none */ }
    Vector2(float _x, float _y) { x = _x; y = _y; }

    Vector2& operator+=(const Vector2& rhs) { x += rhs.x; y += rhs.y; return *this; };
    Vector2& operator+=(float s) { x += s; y += s; return *this; };
    Vector2& operator-=(const Vector2& rhs) { x -= rhs.x; y -= rhs.y; return *this; };
    Vector2& operator-=(float s) { x -= s; y -= s; return *this; };
    Vector2& operator*=(const Vector2& rhs) { x *= rhs.x; y *= rhs.y; return *this; };
    Vector2& operator*=(float s) { x *= s; y *= s; return *this; };

    Vector2 operator-() const { return Vector2(-x, -y); }
    Vector2 operator+(const Vector2& rhs) const { return Vector2(x + rhs.x, y + rhs.y); }
    Vector2 operator+(float s) const { return Vector2(x + s, y + s); }
    Vector2 operator-(const Vector2& rhs) const { return Vector2(x - rhs.x, y - rhs.y); }
    Vector2 operator-(float s) const { return Vector2(x - s, y - s); }
    Vector2 operator*(const Vector2& rhs) const { return Vector2(x * rhs.x, y * rhs.y); }
    Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
};

inline float distance(const Vector2& a, const Vector2& b)
{
    Vector2 d(b - a);
    return sqrtf(d.x * d.x + d.y * d.y);
}

inline float distance_squared(const Vector2& a, const Vector2& b)
{
    Vector2 d(b - a);
    return d.x * d.x + d.y * d.y;
}

inline float dot(const Vector2& a, const Vector2& b)
{
    return a.x * b.x + a.y * b.y;
}

inline float length(const Vector2& a)
{
    return sqrtf(a.x * a.x + a.y * a.y);
}

inline float length_squared(const Vector2& a)
{
    return a.x * a.x + a.y * a.y;
}

} // namespace Nyx

#endif // NyxMath_Vector2_h
