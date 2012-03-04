#ifndef NyxMath_Sphere_h
#define NyxMath_Sphere_h

#include <NyxMath\Vector3.h>

namespace Nyx
{

class Sphere
{
public:
    Vector3 origin;
    float radius;

    Sphere() { /* none */ }
    Sphere(const Vector3& _origin, float _radius);

    bool contains(const Vector3& p) const;
};

inline Sphere::Sphere(const Vector3& _origin, float _radius) :
    origin(_origin)
{
    radius = _radius;
}

inline bool Sphere::contains(const Vector3& p) const
{
    return distance_squared(origin, p) <= radius * radius;
}

} // namespace Nyx

#endif // NyxMath_Sphere_h
