#ifndef NyxFileFormats_TGA_h
#define NyxFileFormats_TGA_h

namespace Nyx
{
namespace TGA
{

namespace ImageTypes
{
enum ImageType
{
    Invalid = 0,

    Indexed = 1,
    Truecolor = 2,
    Greyscale = 3,

    RLE_Indexed = 9,
    RLE_Truecolor = 10,
    RLE_Greyscale = 11,
};
} // namespace ImageTypes
typedef ImageTypes::ImageType ImageType;

#pragma pack(push, 1)

struct Header
{
    uint8_t     ident_length;
    uint8_t     index_type;
    uint8_t     image_type;
    uint16_t    index_start;
    uint16_t    index_length;
    uint8_t     index_entry_size;
    uint16_t    x;
    uint16_t    y;
    uint16_t    width;
    uint16_t    height;
    uint8_t     pixel_depth;
    uint8_t     image_descriptor;
};

#pragma pack(pop)

} // namespace TGA
} // namespace Nyx

#endif // NyxFileFormats_TGA_h
