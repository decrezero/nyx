#include <NyxGraphics\Geometry\BoxPrimative.h>

namespace Nyx
{

BoxPrimative::BoxPrimative() :
    _divisions(1, 1, 1),
    _origin(Vector3::Zero),
    _scale(Vector3::One)
{
    // none
}

} // namespace Nyx
