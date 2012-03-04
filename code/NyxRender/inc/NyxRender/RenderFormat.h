#ifndef NyxRender_RenderFormat_h
#define NyxRender_RenderFormat_h

namespace Nyx
{

namespace RenderFormats
{
enum RenderFormat
{
    Invalid,

    // 16 byte
    R32_G32_B32_A32_Float,

    // 12 byte
    R32_G32_B32_Float,

    // 8 byte
    R16_G16_B16_A16_Float,
    R32_G32_Float,

    // 4 byte
    R8_G8_B8_A8_UNorm,
    R8_G8_B8_A8_UNorm_sRGB,
    R32_Float,

    // 2 byte
    B5_G5_R5_A1_UNorm,
    B5_G6_R5_UNorm,
    R8_G8_Norm,
    R16_Float,

    // 1 byte
    R8_UNorm,

    // block compressed
    BC1_UNorm,
    BC1_UNorm_sRGB,
    BC2_UNorm,
    BC2_UNorm_sRGB,
    BC3_UNorm,
    BC3_UNorm_sRGB,
    BC4_Norm,
    BC4_UNorm,
    BC5_Norm,
    BC5_UNorm,
};
} // namespace RenderFormats
typedef RenderFormats::RenderFormat RenderFormat;

size_t render_format_pitch(RenderFormat e, size_t width);
size_t render_format_size(RenderFormat e);

} // namespace Nyx

#endif // NyxRender_RenderFormat_h
