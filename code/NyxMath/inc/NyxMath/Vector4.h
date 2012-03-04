#ifndef NyxMath_Vector4_h
#define NyxMath_Vector4_h

namespace Nyx
{

class Vector4
{
public:
    static const Vector4 Zero;

    float x;
    float y;
    float z;
    float w;

    Vector4() { /* none */ }
    Vector4(float _x, float _y, float _z, float _w) { x = _x; y = _y; z = _z; w = _w; }

    Vector4& operator+=(const Vector4& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; w += rhs.w; return *this; };
    Vector4& operator+=(float s) { x += s; y += s; z += s; w += s; return *this; };
    Vector4& operator-=(const Vector4& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; w -= rhs.w; return *this; };
    Vector4& operator-=(float s) { x -= s; y -= s; z -= s; w -= s; return *this; };
    Vector4& operator*=(const Vector4& rhs) { x *= rhs.x; y *= rhs.y; z *= rhs.z; w *= rhs.w; return *this; };
    Vector4& operator*=(float s) { x *= s; y *= s; z *= s; w *= s; return *this; };

    Vector4 operator-() const { return Vector4(-x, -y, -z, -w); }
    Vector4 operator+(const Vector4& rhs) const { return Vector4(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w); }
    Vector4 operator+(float s) const { return Vector4(x + s, y + s, z + s, w + s); }
    Vector4 operator-(const Vector4& rhs) const { return Vector4(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w); }
    Vector4 operator-(float s) const { return Vector4(x - s, y - s, z - s, w - s); }
    Vector4 operator*(const Vector4& rhs) const { return Vector4(x * rhs.x, y * rhs.y, z * rhs.z, w * rhs.w); }
    Vector4 operator*(float s) const { return Vector4(x * s, y * s, z * s, w * s); }
};

inline float dot(const Vector4& a, const Vector4& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

inline float length_squared(const Vector4& a)
{
    return a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
}

} // namespace Nyx

#endif // NyxMath_Vector4_h
