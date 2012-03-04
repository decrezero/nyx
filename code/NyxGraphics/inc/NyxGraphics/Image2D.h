#ifndef NyxGraphics_Image2D_h
#define NyxGraphics_Image2D_h

#include <cstdio>

#include <NyxCore\Assert.h>

namespace Nyx
{

class Kernel2D;

class Image2D
{
public:
    typedef float (*PixelProc)(float);

    static int init(Image2D& obj, size_t width, size_t height, size_t channel_count);
    static int init_from_tga(Image2D& obj, const char* filename);
    static void term(Image2D& obj);

    Image2D();

    ~Image2D();

    bool valid() const;

    size_t width() const { return _width; }
    size_t height() const { return _height; }
    size_t channel_count() const { return _channel_count; }

    const float* data() const;

    size_t length() const;

    float& at(size_t x, size_t y, size_t c);
    const float& at(size_t x, size_t y, size_t c) const;

    void set(const Image2D& rhs);
    void add(const Image2D& rhs);
    void sub(const Image2D& rhs);
    void mul(const Image2D& rhs);

    void process(PixelProc f);
    void process(size_t c, PixelProc f);

private:
    static void load_TGA_truecolor_data(Image2D& obj, FILE* stream, size_t pixelSize);
    static void load_TGA_RLE_truecolor_data(Image2D& obj, FILE* stream, size_t pixelSize);

    float* _data;

    size_t _width;
    size_t _height;
    size_t _channel_count;
};

bool dimensions_match(const Image2D& a, const Image2D& b);

void downsample_bilinear(Image2D& dst, const Image2D& src);

void fill(Image2D& obj, float value);
void fill(Image2D& obj, size_t c, float value);

void filter(Image2D& dst, const Image2D& src, const Kernel2D& k);

void flip_horizontal(Image2D& obj);
void flip_vertical(Image2D& obj);

void invert(Image2D& obj);
void invert(Image2D& obj, size_t c);

int save_TGA(const Image2D& obj, const char* filename);

inline bool Image2D::valid() const
{
    return _data != nullptr;
}

inline const float* Image2D::data() const
{
    NYX_ASSERT(_data != nullptr);
    return _data;
}

} // namespace Nyx

#endif // NyxGraphics_Image2D_h
