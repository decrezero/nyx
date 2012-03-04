#include <NyxRender\DepthTarget.h>

namespace Nyx
{

DepthTarget::DepthTarget()
{
    _depth_stencil_view = nullptr;
    _shader_resource_view = nullptr;
    _texture = nullptr;

    _format = RenderFormats::Invalid;
    _width = 0;
    _height = 0;
}

DepthTarget::~DepthTarget()
{
    term(*this);
}

} // namespace Nyx
