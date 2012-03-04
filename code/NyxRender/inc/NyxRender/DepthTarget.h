#ifndef NyxRender_DepthTarget_h
#define NyxRender_DepthTarget_h

#include <NyxCore\Assert.h>
#include <NyxRender\RenderFormat.h>

struct ID3D11DepthStencilView;
struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;

namespace Nyx
{

class DepthTarget
{
public:
    static int init(DepthTarget& obj, RenderFormat format, size_t width, size_t height);
    static void term(DepthTarget& obj);

    DepthTarget();

    ~DepthTarget();

    ID3D11DepthStencilView* depth_stencil_view() const;
    ID3D11ShaderResourceView* shader_resource_view() const;
    ID3D11Texture2D* texture() const;

    RenderFormat format() const { return _format; }
    size_t width() const { return _width; }
    size_t height() const { return _height; }

private:
    ID3D11DepthStencilView* _depth_stencil_view;
    ID3D11ShaderResourceView* _shader_resource_view;
    ID3D11Texture2D* _texture;

    RenderFormat _format;
    size_t _width;
    size_t _height;

    // disable
    DepthTarget(DepthTarget&);
    DepthTarget& operator=(const DepthTarget&);
};

inline ID3D11DepthStencilView* DepthTarget::depth_stencil_view() const
{
    NYX_ASSERT(_depth_stencil_view != nullptr);
    return _depth_stencil_view;
}

inline ID3D11ShaderResourceView* DepthTarget::shader_resource_view() const
{
    NYX_ASSERT(_shader_resource_view != nullptr);
    return _shader_resource_view;
}

inline ID3D11Texture2D* DepthTarget::texture() const
{
    NYX_ASSERT(_texture != nullptr);
    return _texture;
}

} // namespace Nyx

#endif // NyxRender_DepthTarget_h
