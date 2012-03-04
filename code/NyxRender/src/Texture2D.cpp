#include <NyxRender\Texture2D.h>

namespace Nyx
{

Texture2D::Texture2D()
{
    _shader_resource_view = nullptr;
    _texture = nullptr;

    _format = RenderFormats::Invalid;
    _width = 0;
    _height = 0;
    _mip_levels = 0;
}

Texture2D::~Texture2D()
{
    term(*this);
}

} // namespace Nyx
