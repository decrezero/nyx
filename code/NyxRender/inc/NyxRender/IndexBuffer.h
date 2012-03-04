#ifndef NyxRender_IndexBuffer_h
#define NyxRender_IndexBuffer_h

#include <NyxCore\Assert.h>

struct ID3D11Buffer;

namespace Nyx
{

class IndexBuffer
{
public:
    static int init(IndexBuffer& obj, size_t index_count, size_t index_size, const void* data);
    static void term(IndexBuffer& obj);

    IndexBuffer();

    ~IndexBuffer();

    ID3D11Buffer* buffer() const;

    size_t index_count() const { return _index_count; }
    size_t index_size() const { return _index_size; }

private:
    ID3D11Buffer* _buffer;

    size_t _index_count;
    size_t _index_size;

    // disable
    IndexBuffer(IndexBuffer&);
    IndexBuffer& operator=(const IndexBuffer&);
};

inline ID3D11Buffer* IndexBuffer::buffer() const
{
    NYX_ASSERT(_buffer != nullptr);
    return _buffer;
}

} // namespace Nyx

#endif // NyxRender_IndexBuffer_h
