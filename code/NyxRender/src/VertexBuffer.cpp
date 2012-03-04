#include <NyxRender\VertexBuffer.h>

namespace Nyx
{

VertexBuffer::VertexBuffer()
{
    _buffer = nullptr;
    _vertex_count = 0;
    _vertex_size = 0;
}

VertexBuffer::~VertexBuffer()
{
    term(*this);
}

} // namespace Nyx
