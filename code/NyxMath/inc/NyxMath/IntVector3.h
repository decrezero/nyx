#ifndef NyxMath_IntVector3_h
#define NyxMath_IntVector3_h

namespace Nyx
{

class IntVector3
{
public:
    static const IntVector3 One;
    static const IntVector3 Zero;

    int x;
    int y;
    int z;

    IntVector3() { /* none */ }
    IntVector3(int _x, int _y, int _z) { x = _x; y = _y; z = _z; }

    IntVector3& operator+=(const IntVector3& rhs) { x += rhs.x; y += rhs.y; z += rhs.z; return *this; };
    IntVector3& operator+=(int s) { x += s; y += s; z += s; return *this; };
    IntVector3& operator-=(const IntVector3& rhs) { x -= rhs.x; y -= rhs.y; z -= rhs.z; return *this; };
    IntVector3& operator-=(int s) { x -= s; y -= s; z -= s; return *this; };

    IntVector3 operator-() const { return IntVector3(-x, -y, -z); }
    IntVector3 operator+(const IntVector3& rhs) const { return IntVector3(x + rhs.x, y + rhs.y, z + rhs.z); }
    IntVector3 operator+(int s) const { return IntVector3(x + s, y + s, z + s); }
    IntVector3 operator-(const IntVector3& rhs) const { return IntVector3(x - rhs.x, y - rhs.y, z - rhs.z); }
    IntVector3 operator-(int s) const { return IntVector3(x - s, y - s, z - s); }
};

} // namespace Nyx

#endif // NyxMath_IntVector3_h
