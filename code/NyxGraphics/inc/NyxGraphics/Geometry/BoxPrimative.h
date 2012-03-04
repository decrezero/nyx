#ifndef NyxGraphics_Geometry_BoxPrimative_h
#define NyxGraphics_Geometry_BoxPrimative_h

#include <NyxMath\IntVector3.h>
#include <NyxMath\Vector3.h>

namespace Nyx
{

class BoxPrimative
{
public:
    BoxPrimative();

    const IntVector3 divisions() const { return _divisions; }
    const Vector3& origin() const { return _origin; }
    const Vector3& scale() const { return _scale; }

private:
    IntVector3 _divisions;
    Vector3 _origin;
    Vector3 _scale;
};

} // namespace Nyx

#endif // NyxGraphics_Geometry_BoxPrimative_h
