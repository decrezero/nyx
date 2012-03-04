#ifndef NyxRender_VertexBuffer_h
#define NyxRender_VertexBuffer_h

#include <NyxCore\Assert.h>

struct ID3D11Buffer;

namespace Nyx
{

class VertexBuffer
{
public:
    static int init(VertexBuffer& obj, size_t vertex_count, size_t vertex_size, const void* data);
    static void term(VertexBuffer& obj);

    VertexBuffer();

    ~VertexBuffer();

    ID3D11Buffer* buffer() const;

    size_t vertex_count() const { return _vertex_count; }
    size_t vertex_size() const { return _vertex_size; }

private:
    ID3D11Buffer* _buffer;

    size_t _vertex_count;
    size_t _vertex_size;

    // disable
    VertexBuffer(VertexBuffer&);
    VertexBuffer& operator=(const VertexBuffer&);
};

inline ID3D11Buffer* VertexBuffer::buffer() const
{
    NYX_ASSERT(_buffer != nullptr);
    return _buffer;
}

} // namespace Nyx

#endif // NyxRender_VertexBuffer_h
