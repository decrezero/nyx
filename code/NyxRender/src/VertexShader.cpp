#include <NyxRender\VertexShader.h>

namespace Nyx
{

VertexShader::VertexShader()
{
    _shader = nullptr;
}

VertexShader::~VertexShader()
{
    term(*this);
}

} // namespace Nyx
