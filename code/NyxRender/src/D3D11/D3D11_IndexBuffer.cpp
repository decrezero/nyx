#include <NyxRender\IndexBuffer.h>

#include <D3D11.h>

#include <NyxRender\RenderDevice.h>

namespace Nyx
{

int IndexBuffer::init(IndexBuffer& obj, size_t index_count, size_t index_size, const void* data)
{
    NYX_ASSERT(obj._buffer == nullptr);

    ID3D11Device* device = RenderDevice::device();

    D3D11_BUFFER_DESC desc;
    desc.ByteWidth = index_count * index_size;
    desc.Usage = D3D11_USAGE_IMMUTABLE;
    desc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    desc.CPUAccessFlags = 0;
    desc.MiscFlags = 0;
    desc.StructureByteStride = 0;

    D3D11_SUBRESOURCE_DATA init;
    init.pSysMem = data;
    init.SysMemPitch = 0;
    init.SysMemSlicePitch = 0;

    HRESULT hr = device->CreateBuffer(&desc, &init, &obj._buffer);
    if (FAILED(hr))
    {
        term(obj);
        return 1;
    }

    obj._index_count = index_count;
    obj._index_size = index_size;

    return 0;
}

void IndexBuffer::term(IndexBuffer& obj)
{
    if (obj._buffer != nullptr)
    {
        obj._buffer->Release();
        obj._buffer = nullptr;
    }
}

} // namespace Nyx
