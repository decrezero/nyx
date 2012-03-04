#ifndef NyxRender_RenderDevice_h
#define NyxRender_RenderDevice_h

#include <NyxCore\Assert.h>

struct ID3D11Device;
struct ID3D11DeviceContext;

namespace Nyx
{

class RenderDevice
{
public:
    static int init();
    static void term();

    static ID3D11Device* device();
    static ID3D11DeviceContext* immediate_context();

//private:
    static ID3D11Device* _device;
    static ID3D11DeviceContext* _immediate_context;
};

inline ID3D11Device* RenderDevice::device()
{
    NYX_ASSERT(_device != nullptr);
    return _device;
}

inline ID3D11DeviceContext* RenderDevice::immediate_context()
{
    NYX_ASSERT(_immediate_context != nullptr);
    return _immediate_context;
}

} // namespace Nyx

#endif // NyxRender_RenderDevice_h
