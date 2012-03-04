#include <NyxRender\DXGI\RenderFormat.h>

namespace Nyx
{

DXGI_FORMAT to_dxgi(RenderFormat e)
{
    using namespace RenderFormats;

    switch (e)
    {
        // 16 byte
        case R32_G32_B32_A32_Float:
            return DXGI_FORMAT_R32G32B32A32_FLOAT;

        // 12 byte
        case R32_G32_B32_Float:
            return DXGI_FORMAT_R32G32B32_FLOAT;

        // 8 byte
        case R16_G16_B16_A16_Float:
            return DXGI_FORMAT_R16G16B16A16_FLOAT;
        case R32_G32_Float:
            return DXGI_FORMAT_R32G32_FLOAT;

        // 4 byte
        case R8_G8_B8_A8_UNorm:
            return DXGI_FORMAT_R8G8B8A8_UNORM;
        case R8_G8_B8_A8_UNorm_sRGB:
            return DXGI_FORMAT_R8G8B8A8_UNORM_SRGB;
        case R32_Float:
            return DXGI_FORMAT_R32_FLOAT;

        // 2 byte
        case B5_G5_R5_A1_UNorm:
            return DXGI_FORMAT_B5G5R5A1_UNORM;
        case B5_G6_R5_UNorm:
            return DXGI_FORMAT_B5G6R5_UNORM;
        case R8_G8_Norm:
            return DXGI_FORMAT_R8G8_SNORM;
        case R16_Float:
            return DXGI_FORMAT_R16_FLOAT;

        // 1 byte
        case R8_UNorm:
            return DXGI_FORMAT_R8_UNORM;

        // block compressed
        case BC1_UNorm:
            return DXGI_FORMAT_BC1_UNORM;
        case BC1_UNorm_sRGB:
            return DXGI_FORMAT_BC1_UNORM_SRGB;
        case BC2_UNorm:
            return DXGI_FORMAT_BC2_UNORM;
        case BC2_UNorm_sRGB:
            return DXGI_FORMAT_BC2_UNORM_SRGB;
        case BC3_UNorm:
            return DXGI_FORMAT_BC3_UNORM;
        case BC3_UNorm_sRGB:
            return DXGI_FORMAT_BC3_UNORM_SRGB;
        case BC4_Norm:
            return DXGI_FORMAT_BC4_SNORM;
        case BC4_UNorm:
            return DXGI_FORMAT_BC4_UNORM;
        case BC5_Norm:
            return DXGI_FORMAT_BC5_SNORM;
        case BC5_UNorm:
            return DXGI_FORMAT_BC5_UNORM;

        default:
            return DXGI_FORMAT_UNKNOWN;
    }
}

} // namespace Nyx
