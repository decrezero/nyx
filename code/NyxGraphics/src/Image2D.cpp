#include <NyxGraphics\Image2D.h>

#include <cstdint>

#include <NyxCore\STL\AlgoBase.h>
#include <NyxFileFormat\TGA.h>
#include <NyxGraphics\Kernel2D.h>
#include <NyxMath\Common.h>

namespace Nyx
{

int Image2D::init(Image2D& obj, size_t width, size_t height, size_t channel_count)
{
    NYX_ASSERT(!obj.valid());

    obj._data = new float[width * height * channel_count];

    if (obj._data == nullptr)
    {
        return 1;
    }

    obj._width = width;
    obj._height = height;
    obj._channel_count = channel_count;

    return 0;
}

int Image2D::init_from_tga(Image2D& obj, const char* filename)
{
    FILE* fp = 0;

    fopen_s(&fp, filename, "rb");

    if (fp == 0)
    {
        return 1;
    }

    TGA::Header header;
    fread(&header, sizeof(TGA::Header), 1, fp);

    size_t width = header.width;
    size_t height = header.height;
    size_t channel_count = 0;

    if (header.pixel_depth == 32)
    {
        channel_count = 4;
    }
    else if (header.pixel_depth == 24)
    {
        channel_count = 3;
    }
    else
    {
        return 1;
    }

    if (init(obj, width, height, channel_count))
    {
        return 1;
    }

    fseek(fp, header.ident_length, SEEK_CUR);

    switch (header.image_type)
    {
        case TGA::ImageTypes::Truecolor:
            load_TGA_truecolor_data(obj, fp, channel_count);
            break;

        case TGA::ImageTypes::RLE_Truecolor:
            load_TGA_RLE_truecolor_data(obj, fp, channel_count);
            break;

        default:
            NYX_FAIL();
            return 1;
    }

    fclose(fp);

    return 0;
}

void Image2D::term(Image2D& obj)
{
    delete[] obj._data;
    obj._data = nullptr;
}

Image2D::Image2D()
{
    _data = nullptr;

    _width = 0;
    _height = 0;
    _channel_count = 0;
}

Image2D::~Image2D()
{
    term(*this);
}

size_t Image2D::length() const
{
    return _width * _height * _channel_count;
}

float& Image2D::at(size_t x, size_t y, size_t c)
{
    NYX_ASSERT(x < _width && y < _height && c < _channel_count);

    return _data[(_width * y + x) * _channel_count + c];
}

const float& Image2D::at(size_t x, size_t y, size_t c) const
{
    NYX_ASSERT(x < _width && y < _height && c < _channel_count);

    return _data[(_width * y + x) * _channel_count + c];
}

void Image2D::set(const Image2D& rhs)
{
    NYX_ASSERT(dimensions_match(*this, rhs));

    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] = _data[i];
    }
}

void Image2D::add(const Image2D& rhs)
{
    NYX_ASSERT(dimensions_match(*this, rhs));

    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] += _data[i];
    }
}

void Image2D::sub(const Image2D& rhs)
{
    NYX_ASSERT(dimensions_match(*this, rhs));

    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] -= _data[i];
    }
}

void Image2D::mul(const Image2D& rhs)
{
    NYX_ASSERT(dimensions_match(*this, rhs));

    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] *= _data[i];
    }
}

void Image2D::process(PixelProc f)
{
    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] = f(_data[i]);
    }
}

void Image2D::process(size_t c, PixelProc f)
{
    size_t len = length();

    for (size_t i = c; i < len; i += _channel_count)
    {
        _data[i] = f(_data[i]);
    }
}

void Image2D::load_TGA_truecolor_data(Image2D& obj, FILE* stream, size_t pixelSize)
{
    uint8_t pixel[4] = { 0 };

    for (size_t y = 0; y < obj._height; ++y)
    {
        for (size_t x = 0; x < obj._width; ++x)
        {
            fread(pixel, pixelSize, 1, stream);

            float& r = obj.at(x, y, 0);
            r = static_cast<float>(pixel[2]) / 255.0f;
            float& g = obj.at(x, y, 1);
            g = static_cast<float>(pixel[1]) / 255.0f;
            float& b = obj.at(x, y, 2);
            b = static_cast<float>(pixel[0]) / 255.0f;

            if (pixelSize > 3)
            {
                float& a = obj.at(x, y, 3);
                a = static_cast<float>(pixel[3]) / 255.0f;
            }
        }
    }
}

void Image2D::load_TGA_RLE_truecolor_data(Image2D& obj, FILE* stream, size_t pixelSize)
{
    bool raw = true;
    bool rle_first = true;
    uint8_t count = 0;

    uint8_t pixel[4] = { 0 };

    for (size_t y = 0; y < obj._height; ++y)
    {
        for (size_t x = 0; x < obj._width; ++x)
        {
            if (count == 0)
            {
                uint8_t code;
                fread(&code, 1, 1, stream);
                if (code < 128)
                {
                    raw = true;
                    count = code + 1;
                }
                else
                {
                    raw = false;
                    rle_first = true;
                    count = code - 127;
                }
            }

            if (raw || rle_first)
            {
                fread(pixel, pixelSize, 1, stream);
                rle_first = false;
            }

            float& r = obj.at(x, y, 0);
            r = static_cast<float>(pixel[2]) / 255.0f;
            float& g = obj.at(x, y, 1);
            g = static_cast<float>(pixel[1]) / 255.0f;
            float& b = obj.at(x, y, 2);
            b = static_cast<float>(pixel[0]) / 255.0f;

            if (pixelSize > 3)
            {
                float& a = obj.at(x, y, 3);
                a = static_cast<float>(pixel[3]) / 255.0f;
            }

            --count;
        }
    }
}

bool dimensions_match(const Image2D& a, const Image2D& b)
{
    return a.width() == b.width() && a.height() == b.height() && a.channel_count() == b.channel_count();
}

void downsample_bilinear(Image2D& dst, const Image2D& src)
{
    NYX_ASSERT(dst.width() * 2 == src.width());
    NYX_ASSERT(dst.height() * 2 == src.height());
    NYX_ASSERT(dst.channel_count() == src.channel_count());

    size_t width = dst.width();
    size_t height = dst.height();
    size_t channel_count = dst.channel_count();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                size_t src_x = x * 2;
                size_t src_y = y * 2;

                float sample0 = src.at(src_x    , src_y    , c);
                float sample1 = src.at(src_x + 1, src_y    , c);
                float sample2 = src.at(src_x    , src_y + 1, c);
                float sample3 = src.at(src_x + 1, src_y + 1, c);

                float sum = sample0 + sample1 + sample2 + sample3;

                dst.at(x, y, c) = sum * 0.25f;
            }
        }
    }
}

void fill(Image2D& obj, float value)
{
    size_t width = obj.width();
    size_t height = obj.height();
    size_t channel_count = obj.channel_count();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                obj.at(x, y, c) = value;
            }
        }
    }
}

void fill(Image2D& obj, size_t c, float value)
{
    NYX_ASSERT(c < obj.channel_count());

    size_t width = obj.width();
    size_t height = obj.height();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            obj.at(x, y, c) = value;
        }
    }
}

void filter(Image2D& dst, const Image2D& src, const Kernel2D& k)
{
    NYX_ASSERT(&dst != &src);
    NYX_ASSERT(dimensions_match(dst, src));

    size_t width = src.width();
    size_t height = src.height();
    size_t channel_count = src.channel_count();

    int spread = k.spread();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                float& result = dst.at(x, y, c);
                result = 0.0f;

                for (int ky = -spread; ky <= spread; ++ky)
                {
                    for (int kx = -spread; kx <= spread; ++kx)
                    {
                        float weight = k.at(kx, ky);

                        int adj_x = clamp<int>(static_cast<int>(x) + kx, 0, width - 1);
                        int adj_y = clamp<int>(static_cast<int>(y) + ky, 0, height - 1);

                        result += src.at(adj_x, adj_y, c) * weight;
                    }
                }
            }
        }
    }
}

void flip_horizontal(Image2D& obj)
{
    size_t width = obj.width();
    size_t height = obj.height();
    size_t channel_count = obj.channel_count();

    size_t half_width = width / 2;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < half_width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                size_t x2 = width - x - 1;
                float& a = obj.at(x, y, c);
                float& b = obj.at(x2, y, c);
                Nyx::swap(a, b);
            }
        }
    }
}

void flip_vertical(Image2D& obj)
{
    size_t width = obj.width();
    size_t height = obj.height();
    size_t channel_count = obj.channel_count();

    size_t half_height = height / 2;

    for (size_t y = 0; y < half_height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                size_t y2 = height - y - 1;
                float& a = obj.at(x, y, c);
                float& b = obj.at(x, y2, c);
                Nyx::swap(a, b);
            }
        }
    }
}

void invert(Image2D& obj)
{
    size_t width = obj.width();
    size_t height = obj.height();
    size_t channel_count = obj.channel_count();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            for (size_t c = 0; c < channel_count; ++c)
            {
                float& f = obj.at(x, y, c);
                f = 1.0f - f;
            }
        }
    }
}

void invert(Image2D& obj, size_t c)
{
    NYX_ASSERT(c < obj.channel_count());

    size_t width = obj.width();
    size_t height = obj.height();

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            float& f = obj.at(x, y, c);
            f = 1.0f - f;
        }
    }
}

int save_TGA(const Image2D& obj, const char* filename)
{
    size_t width = obj.width();
    size_t height = obj.height();
    size_t channel_count = obj.channel_count();

    FILE* fp = 0;

    fopen_s(&fp, filename, "wb");

    if (fp == 0)
    {
        return 1;
    }

    TGA::Header header;
    header.ident_length = 0;
    header.index_type = 0;
    header.image_type = TGA::ImageTypes::Truecolor;
    header.index_start = 0;
    header.index_length = 0;
    header.index_entry_size = 0;
    header.x = 0;
    header.y = 0;
    header.width = static_cast<uint16_t>(width);
    header.height = static_cast<uint16_t>(height);
    header.pixel_depth = static_cast<uint8_t>(channel_count * 8);

    switch (channel_count)
    {
        case 3:
            header.image_descriptor = 0;
            break;

        case 4:
            header.image_descriptor = 8;
            break;

        default:
            return 1;
    }

    fwrite(&header, sizeof(header), 1, fp);

    size_t pixelSize = channel_count;

    for (size_t y = 0; y < height; ++y)
    {
        for (size_t x = 0; x < width; ++x)
        {
            float r = obj.at(x, y, 0);
            float g = obj.at(x, y, 1);
            float b = obj.at(x, y, 2);
            float a = channel_count > 3 ? obj.at(x, y, 3) : 1.0f;

            r = clamp<float>(r, 0.0f, 1.0f);
            g = clamp<float>(g, 0.0f, 1.0f);
            b = clamp<float>(b, 0.0f, 1.0f);
            a = clamp<float>(a, 0.0f, 1.0f);

            uint8_t pixel[4];
            pixel[0] = static_cast<uint8_t>(b * 255.0f);
            pixel[1] = static_cast<uint8_t>(g * 255.0f);
            pixel[2] = static_cast<uint8_t>(r * 255.0f);
            pixel[3] = static_cast<uint8_t>(a * 255.0f);

            fwrite(pixel, pixelSize, 1, fp);
        }
    }

    fclose(fp);

    return 0;
}

} // namespace Nyx
