#include <NyxRender\VertexShader.h>

#include <D3D11.h>

#include <NyxRender\RenderDevice.h>

namespace Nyx
{

int VertexShader::init(VertexShader& obj, const void* code, size_t length)
{
    NYX_ASSERT(obj._shader == nullptr);

    ID3D11Device* device = RenderDevice::device();

    HRESULT hr = device->CreateVertexShader(code, length, nullptr, &obj._shader);
    if (FAILED(hr))
    {
        term(obj);
        return 1;
    }

    return 0;
}

void VertexShader::term(VertexShader& obj)
{
    if (obj._shader != nullptr)
    {
        obj._shader->Release();
        obj._shader = nullptr;
    }
}

} // namespace Nyx
