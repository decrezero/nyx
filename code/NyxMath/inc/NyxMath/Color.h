#ifndef NyxMath_Color_h
#define NyxMath_Color_h

#include <cstdint>

namespace Nyx
{

class Color
{
public:
    static const Color Black;

    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    Color() { /* none */ }
    Color(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a) { r = _r; g = _g; b = _b; a = _a; }

    bool operator==(const Color& rhs) const { return r == rhs.r && g == rhs.g && b == rhs.b && a == rhs.a; }
    bool operator!=(const Color& rhs) const { return !(*this == rhs); }
};

} // namespace Nyx

#endif // NyxMath_Color_h
