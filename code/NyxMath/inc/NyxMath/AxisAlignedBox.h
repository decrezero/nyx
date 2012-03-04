#ifndef NyxMath_AxisAlignedBox_h
#define NyxMath_AxisAlignedBox_h

#include <NyxMath\Vector3.h>

namespace Nyx
{

class AxisAlignedBox
{
public:
    Vector3 minimum;
    Vector3 maximum;

    AxisAlignedBox() { /* none */ }
    AxisAlignedBox(const Vector3& _minimum, const Vector3& _maximum);

    bool contains(const Vector3& p) const;
};

inline AxisAlignedBox::AxisAlignedBox(const Vector3& _minimum, const Vector3& _maximum) :
    minimum(_minimum),
    maximum(_maximum)
{
    // none
}

inline bool AxisAlignedBox::contains(const Vector3& p) const
{
    return
        p.x <= maximum.x &&
        p.y <= maximum.y &&
        p.z <= maximum.z &&
        minimum.x <= p.x &&
        minimum.y <= p.y &&
        minimum.z <= p.z;
}

} // namespace Nyx

#endif // NyxMath_AxisAlignedBox_h
