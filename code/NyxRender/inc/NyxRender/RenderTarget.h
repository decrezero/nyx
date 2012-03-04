#ifndef NyxRender_RenderTarget_h
#define NyxRender_RenderTarget_h

#include <NyxCore\Assert.h>
#include <NyxRender\RenderFormat.h>

struct ID3D11RenderTargetView;
struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;

namespace Nyx
{

class RenderTarget
{
public:
    static int init(RenderTarget& obj, RenderFormat format, size_t width, size_t height);
    static void term(RenderTarget& obj);

    RenderTarget();

    ~RenderTarget();

    ID3D11RenderTargetView* render_target_view() const;
    ID3D11ShaderResourceView* shader_resource_view() const;
    ID3D11Texture2D* texture() const;

    RenderFormat format() const { return _format; }
    size_t width() const { return _width; }
    size_t height() const { return _height; }

private:
    ID3D11RenderTargetView* _render_target_view;
    ID3D11ShaderResourceView* _shader_resource_view;
    ID3D11Texture2D* _texture;

    RenderFormat _format;
    size_t _width;
    size_t _height;

    // disable
    RenderTarget(RenderTarget&);
    RenderTarget& operator=(const RenderTarget&);
};

inline ID3D11RenderTargetView* RenderTarget::render_target_view() const
{
    NYX_ASSERT(_render_target_view != nullptr);
    return _render_target_view;
}

inline ID3D11ShaderResourceView* RenderTarget::shader_resource_view() const
{
    NYX_ASSERT(_shader_resource_view != nullptr);
    return _shader_resource_view;
}

inline ID3D11Texture2D* RenderTarget::texture() const
{
    NYX_ASSERT(_texture != nullptr);
    return _texture;
}

} // namespace Nyx

#endif // NyxRender_RenderTarget_h
