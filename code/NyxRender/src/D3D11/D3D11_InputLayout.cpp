#include <NyxRender\InputLayout.h>

#include <D3D11.h>

#include <NyxRender\RenderDevice.h>
#include <NyxRender\VertexFormat.h>
#include <NyxRender\DXGI\RenderFormat.h>

namespace Nyx
{

int InputLayout::init(InputLayout& obj, const VertexFormat& vf, const void* code, size_t length)
{
    NYX_ASSERT(obj._input_layout == nullptr);

    ID3D11Device* device = RenderDevice::device();

    D3D11_INPUT_ELEMENT_DESC descs[VertexFormat::MAX_ELEMENT_COUNT];
    size_t element_count = vf.element_count();

    for (size_t i = 0; i < element_count; ++i)
    {
        const VertexFormat::Element& elem = vf.element(i);

        descs[i].SemanticName = vertex_semantic_to_string(elem.semantic);
        descs[i].SemanticIndex = elem.semantic_index;
        descs[i].Format = to_dxgi(elem.format);
        descs[i].InputSlot = elem.input_slot;
        descs[i].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
        descs[i].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
        descs[i].InstanceDataStepRate = 0;
    }

    HRESULT hr = device->CreateInputLayout(descs, element_count, code, length, &obj._input_layout);
    if (FAILED(hr))
    {
        term(obj);
        return 1;
    }

    return 0;
}

void InputLayout::term(InputLayout& obj)
{
    if (obj._input_layout != nullptr)
    {
        obj._input_layout->Release();
        obj._input_layout = nullptr;
    }
}

} // namespace Nyx
