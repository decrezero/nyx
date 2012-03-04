#ifndef NyxMath_Gamma_h
#define NyxMath_Gamma_h

namespace Nyx
{

inline float linear_to_sRGB(float x)
{
    return x <= 0.0031308f ? x * 12.92f : 1.055f * powf(x, 1.0f / 2.4f) - 0.055f;
}

inline float sRGB_to_linear(float x)
{
    return x <= 0.04045f ? x / 12.92f : powf((x + 0.055f) / 1.055f, 2.4f);
}

} // namespace Nyx

#endif // NyxMath_Gamma_h
