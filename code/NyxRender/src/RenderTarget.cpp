#include <NyxRender\RenderTarget.h>

namespace Nyx
{

RenderTarget::RenderTarget()
{
    _render_target_view = nullptr;
    _shader_resource_view = nullptr;
    _texture = nullptr;

    _format = RenderFormats::Invalid;
    _width = 0;
    _height = 0;
}

RenderTarget::~RenderTarget()
{
    term(*this);
}

} // namespace Nyx
