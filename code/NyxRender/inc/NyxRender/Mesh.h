#ifndef NyxRender_Mesh_h
#define NyxRender_Mesh_h

#include <NyxRender\IndexBuffer.h>
#include <NyxRender\VertexBuffer.h>
#include <NyxRender\VertexFormat.h>

namespace Nyx
{

class Mesh
{
public:
    static const size_t MAX_VERTEX_BUFFER_COUNT = VertexFormat::MAX_ELEMENT_COUNT;

    Mesh();

    ~Mesh();

    const VertexBuffer& vertex_buffer(size_t n = 0) const { return _vertex_buffer_pool[n]; }
    const IndexBuffer& index_buffer() const { return _index_buffer; }

private:
    VertexBuffer _vertex_buffer_pool[MAX_VERTEX_BUFFER_COUNT];
    IndexBuffer _index_buffer;
};

} // namespace Nyx

#endif // NyxRender_Mesh_h
