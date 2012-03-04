#include <NyxRender\VertexFormat.h>

#include <NyxCore\Assert.h>

namespace Nyx
{

VertexFormat::Element::Element()
{
    clear();
}

void VertexFormat::Element::clear()
{
    semantic = VertexSemantics::Invalid;
    semantic_index = 0;
    format = RenderFormats::Invalid;
    input_slot = 0;
}

VertexFormat::VertexFormat()
{
    clear();
}

void VertexFormat::add_element(VertexSemantic semantic, size_t semantic_index, RenderFormat format, size_t input_slot)
{
    NYX_ASSERT(_element_count < MAX_ELEMENT_COUNT);

    VertexFormat::Element& elem = _element_pool[_element_count];

    elem.semantic = semantic;
    elem.semantic_index = semantic_index;
    elem.format = format;
    elem.input_slot = input_slot;

    ++_element_count;
}

void VertexFormat::clear()
{
    for (size_t i = 0; i < MAX_ELEMENT_COUNT; ++i)
    {
        _element_pool[i].clear();
    }
}

} // namespace Nyx
