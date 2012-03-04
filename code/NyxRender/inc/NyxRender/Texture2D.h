#ifndef NyxRender_Texture2D_h
#define NyxRender_Texture2D_h

#include <NyxCore\Assert.h>
#include <NyxRender\RenderFormat.h>

struct ID3D11ShaderResourceView;
struct ID3D11Texture2D;

namespace Nyx
{

class Texture2D
{
public:
    static int init(Texture2D& obj, RenderFormat format, size_t width, size_t height, size_t mip_levels, const void* data);
    static void term(Texture2D& obj);

    Texture2D();

    ~Texture2D();

    ID3D11ShaderResourceView* shader_resource_view() const;
    ID3D11Texture2D* texture() const;

    RenderFormat format() const { return _format; }
    size_t width() const { return _width; }
    size_t height() const { return _height; }
    size_t mip_levels() const { return _mip_levels; }

private:
    ID3D11ShaderResourceView* _shader_resource_view;
    ID3D11Texture2D* _texture;

    RenderFormat _format;
    size_t _width;
    size_t _height;
    size_t _mip_levels;

    // disable
    Texture2D(Texture2D&);
    Texture2D& operator=(const Texture2D&);
};

inline ID3D11ShaderResourceView* Texture2D::shader_resource_view() const
{
    NYX_ASSERT(_shader_resource_view != nullptr);
    return _shader_resource_view;
}

inline ID3D11Texture2D* Texture2D::texture() const
{
    NYX_ASSERT(_texture != nullptr);
    return _texture;
}

} // namespace Nyx

#endif // NyxRender_Texture2D_h
