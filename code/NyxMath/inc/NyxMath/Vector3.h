#ifndef NyxMath_Vector3_h
#define NyxMath_Vector3_h

#include <cmath>

namespace Nyx
{

class Vector3
{
public:
    static const Vector3 One;
    static const Vector3 Zero;

    float x;
    float y;
    float z;

    Vector3() { /* none */ }
    Vector3(float _x, float _y, float _z) { x = _x; y = _y; z = _z; }

    Vector3& operator+=(const Vector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; };
    Vector3& operator+=(float s) { x += s; y += s; z += s; return *this; };
    Vector3& operator-=(const Vector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; };
    Vector3& operator-=(float s) { x -= s; y -= s; z -= s; return *this; };
    Vector3& operator*=(const Vector3& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; return *this; };
    Vector3& operator*=(float s) { x *= s; y *= s; z *= s; return *this; };

    Vector3 operator-() const { return Vector3(-x, -y, -z); }
    Vector3 operator+(const Vector3& rhs) const { return Vector3(x + rhs.x, y + rhs.y, z + rhs.z); }
    Vector3 operator+(float s) const { return Vector3(x + s, y + s, z + s); }
    Vector3 operator-(const Vector3& rhs) const { return Vector3(x - rhs.x, y - rhs.y, z - rhs.z); }
    Vector3 operator-(float s) const { return Vector3(x - s, y - s, z - s); }
    Vector3 operator*(const Vector3& rhs) const { return Vector3(x * rhs.x, y * rhs.y, z * rhs.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
};

inline float distance(const Vector3& a, const Vector3& b)
{
    Vector3 d(b - a);
    return sqrtf(d.x * d.x + d.y * d.y + d.z * d.z);
}

inline float distance_squared(const Vector3& a, const Vector3& b)
{
    Vector3 d(b - a);
    return d.x * d.x + d.y * d.y + d.z * d.z;
}

inline float dot(const Vector3& a, const Vector3& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

inline float length(const Vector3& a)
{
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline float length_squared(const Vector3& a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z;
}

} // namespace Nyx

#endif // NyxMath_Vector3_h
