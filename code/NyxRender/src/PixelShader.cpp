#include <NyxRender\PixelShader.h>

namespace Nyx
{

PixelShader::PixelShader()
{
    _shader = nullptr;
}

PixelShader::~PixelShader()
{
    term(*this);
}

} // namespace Nyx
