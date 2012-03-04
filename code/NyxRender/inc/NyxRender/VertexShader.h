#ifndef NyxRender_VertexShader_h
#define NyxRender_VertexShader_h

#include <NyxCore\Assert.h>

struct ID3D11VertexShader;

namespace Nyx
{

class VertexShader
{
public:
    static int init(VertexShader& obj, const void* code, size_t length);
    static void term(VertexShader& obj);

    VertexShader();

    ~VertexShader();

    ID3D11VertexShader* shader() const;

private:
    ID3D11VertexShader* _shader;
};

inline ID3D11VertexShader* VertexShader::shader() const
{
    NYX_ASSERT(_shader != nullptr);
    return _shader;
}

} // namespace Nyx

#endif // NyxRender_VertexShader_h
