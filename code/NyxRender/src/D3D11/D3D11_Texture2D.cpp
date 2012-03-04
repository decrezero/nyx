#include <NyxRender\Texture2D.h>

#include <D3D11.h>

#include <NyxRender\RenderDevice.h>
#include <NyxRender\DXGI\RenderFormat.h>

namespace Nyx
{

int Texture2D::init(Texture2D& obj, RenderFormat format, size_t width, size_t height, size_t mip_levels, const void* data)
{
    NYX_ASSERT(obj._shader_resource_view == nullptr);
    NYX_ASSERT(obj._texture == nullptr);

    ID3D11Device* device = RenderDevice::device();

    D3D11_TEXTURE2D_DESC desc;
    desc.Width = width;
    desc.Height = height;
    desc.MipLevels = mip_levels;
    desc.ArraySize = 1;
    desc.Format = to_dxgi(format);
    desc.SampleDesc.Count = 1;
    desc.SampleDesc.Quality = 0;
    desc.Usage = D3D11_USAGE_IMMUTABLE;
    desc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA init;
    init.pSysMem = data;
    init.SysMemPitch = render_format_pitch(format, width);
    init.SysMemSlicePitch = 0;

    HRESULT hr = device->CreateTexture2D(&desc, &init, &obj._texture);
    if (FAILED(hr))
    {
        term(obj);
        return 1;
    }

    D3D11_SHADER_RESOURCE_VIEW_DESC srv_desc;
    srv_desc.Format = desc.Format;
    srv_desc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
    srv_desc.Texture2D.MostDetailedMip = 0;
    srv_desc.Texture2D.MipLevels = desc.MipLevels;

    hr = device->CreateShaderResourceView(obj._texture, &srv_desc, &obj._shader_resource_view);
    if (FAILED(hr))
    {
        term(obj);
        return 1;
    }

    obj._format = format;
    obj._width = width;
    obj._height = height;
    obj._mip_levels = mip_levels;

    return 0;
}

void Texture2D::term(Texture2D& obj)
{
    if (obj._shader_resource_view != nullptr)
    {
        obj._shader_resource_view->Release();
        obj._shader_resource_view = nullptr;
    }

    if (obj._texture != nullptr)
    {
        obj._texture->Release();
        obj._texture = nullptr;
    }
}

} // namespace Nyx
