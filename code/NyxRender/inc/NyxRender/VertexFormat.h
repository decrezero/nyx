#ifndef NyxRender_VertexFormat_h
#define NyxRender_VertexFormat_h

#include <NyxCore\Assert.h>
#include <NyxRender\RenderFormat.h>
#include <NyxRender\VertexSemantic.h>

namespace Nyx
{

class VertexFormat
{
public:
    class Element
    {
    public:
        VertexSemantic  semantic;
        size_t          semantic_index;
        RenderFormat    format;
        size_t          input_slot;

        Element();

        void clear();
    };

    static const size_t MAX_ELEMENT_COUNT = 8;

    VertexFormat();

    size_t element_count() const { return _element_count; }

    const Element& element(size_t n) const;

    void add_element(VertexSemantic semantic, size_t semantic_index, RenderFormat format, size_t input_slot);

    void clear();

private:
    Element _element_pool[MAX_ELEMENT_COUNT];
    size_t _element_count;
};

inline const VertexFormat::Element& VertexFormat::element(size_t n) const
{
    NYX_ASSERT(n < MAX_ELEMENT_COUNT);
    return _element_pool[n];
}

} // namespace Nyx

#endif // NyxRender_VertexFormat_h
