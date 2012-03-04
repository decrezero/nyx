#include <NyxRender\RenderDevice.h>

namespace Nyx
{

ID3D11Device* RenderDevice::_device;
ID3D11DeviceContext* RenderDevice::_immediate_context;

int RenderDevice::init()
{
    return 0;
}

void RenderDevice::term()
{
}

} // namespace Nyx
