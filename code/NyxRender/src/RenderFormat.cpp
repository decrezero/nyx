#include <NyxRender\RenderFormat.h>

namespace Nyx
{

size_t render_format_pitch(RenderFormat e, size_t width)
{
    using namespace RenderFormats;

    switch (e)
    {
        // 16 byte
        case R32_G32_B32_A32_Float:
            return 16 * width;

        // 12 byte
        case R32_G32_B32_Float:
            return 12 * width;

        // 8 byte
        case R16_G16_B16_A16_Float:
        case R32_G32_Float:
            return 8 * width;

        // 4 byte
        case R8_G8_B8_A8_UNorm:
        case R8_G8_B8_A8_UNorm_sRGB:
        case R32_Float:
            return 4 * width;

        // 2 byte
        case B5_G5_R5_A1_UNorm:
        case B5_G6_R5_UNorm:
        case R8_G8_Norm:
        case R16_Float:
            return 2 * width;

        // 1 byte
        case R8_UNorm:
            return width;

        // block compressed
        case BC1_UNorm:
        case BC1_UNorm_sRGB:
        case BC4_Norm:
        case BC4_UNorm:
            return 8 * ((width + 3) / 4);
        case BC2_UNorm:
        case BC2_UNorm_sRGB:
        case BC3_UNorm:
        case BC3_UNorm_sRGB:
        case BC5_Norm:
        case BC5_UNorm:
            return 16 * ((width + 3) / 4);

        default:
            return 0;
    }
}

size_t render_format_size(RenderFormat e)
{
    using namespace RenderFormats;

    switch (e)
    {
        // 16 byte
        case R32_G32_B32_A32_Float:
            return 16;

        // 12 byte
        case R32_G32_B32_Float:
            return 12;

        // 8 byte
        case R16_G16_B16_A16_Float:
        case R32_G32_Float:
            return 8;

        // 4 byte
        case R8_G8_B8_A8_UNorm:
        case R8_G8_B8_A8_UNorm_sRGB:
        case R32_Float:
            return 4;

        // 2 byte
        case B5_G5_R5_A1_UNorm:
        case B5_G6_R5_UNorm:
        case R8_G8_Norm:
        case R16_Float:
            return 2;

        // 1 byte
        case R8_UNorm:
            return 1;

        default:
            return 0;
    }
}

} // namespace Nyx
