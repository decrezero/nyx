#include <NyxRender\DXGI\IndexBuffer.h>

namespace Nyx
{

DXGI_FORMAT index_size_to_dxgi(size_t n)
{
    switch (n)
    {
        case 2:
            return DXGI_FORMAT_R16_UINT;
        case 4:
            return DXGI_FORMAT_R32_UINT;
        default:
            return DXGI_FORMAT_UNKNOWN;
    }
}

} // namespace Nyx
