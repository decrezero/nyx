#include <NyxRender\IndexBuffer.h>

namespace Nyx
{

IndexBuffer::IndexBuffer()
{
    _buffer = nullptr;
    _index_count = 0;
    _index_size = 0;
}

IndexBuffer::~IndexBuffer()
{
    term(*this);
}

} // namespace Nyx
