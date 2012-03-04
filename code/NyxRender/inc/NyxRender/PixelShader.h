#ifndef NyxRender_PixelShader_h
#define NyxRender_PixelShader_h

#include <NyxCore\Assert.h>

struct ID3D11PixelShader;

namespace Nyx
{

class PixelShader
{
public:
    static int init(PixelShader& obj, const void* code, size_t length);
    static void term(PixelShader& obj);

    PixelShader();

    ~PixelShader();

    ID3D11PixelShader* shader() const;

private:
    ID3D11PixelShader* _shader;
};

inline ID3D11PixelShader* PixelShader::shader() const
{
    NYX_ASSERT(_shader != nullptr);
    return _shader;
}

} // namespace Nyx

#endif // NyxRender_PixelShader_h
