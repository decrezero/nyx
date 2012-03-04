#ifndef NyxGraphics_Geometry_SpherePrimative_h
#define NyxGraphics_Geometry_SpherePrimative_h

#include <NyxMath\IntVector3.h>
#include <NyxMath\Vector3.h>

namespace Nyx
{

class SpherePrimative
{
public:
    SpherePrimative();

    const Vector3& origin() const { return _origin; }
    const Vector3& scale() const { return _scale; }

private:
    Vector3 _origin;
    Vector3 _scale;
};

} // namespace Nyx

#endif // NyxGraphics_Geometry_SpherePrimative_h
