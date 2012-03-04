#ifndef NyxMath_Common_h
#define NyxMath_Common_h

namespace Nyx
{

template <class T>
T abs(const T& x)
{
    return x < 0 ? -x : x;
}

template <class T>
const T& clamp(const T& x, const T& minimum, const T& maximum)
{
    return x < minimum ? minimum : x > maximum ? maximum : x;
}

template <class T, class U>
T lerp(const T& x, const T& y, const U& s)
{
    return (y - x) * s + x;
}

} // namespace Nyx

#endif // NyxMath_Common_h
