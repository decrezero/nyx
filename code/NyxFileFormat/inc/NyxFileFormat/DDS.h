#ifndef NyxFileformat_DDS_H
#define NyxFileformat_DDS_H

#define MAGIC_NUMBER (0x20534444) // "DDS "

#define FOURCC_DXT1 (0x31545844) // "DXT1"
#define FOURCC_DXT2 (0x32545844) // "DXT2"
#define FOURCC_DXT3 (0x33545844) // "DXT3"
#define FOURCC_DXT4 (0x34545844) // "DXT4"
#define FOURCC_DXT5 (0x35545844) // "DXT5"

// PixelFormat::flags
#define DDPF_ALPHAPIXELS    (0x00000001)
#define DDPF_ALPHA          (0x00000002)
#define DDPF_FOURCC         (0x00000004)
#define DDPF_RGB            (0x00000040)
#define DDPF_LUMINANCE      (0x00020000)

// Header::flags
#define DDSD_CAPS           (0x00000001)
#define DDSD_HEIGHT         (0x00000002)
#define DDSD_WIDTH          (0x00000004)
#define DDSD_PITCH          (0x00000008)
#define DDSD_PIXELFORMAT    (0x00001000)
#define DDSD_MIPMAPCOUNT    (0x00020000)
#define DDSD_LINEARSIZE     (0x00080000)
#define DDSD_DEPTH          (0x00800000)

// Header::caps1
#define DDSCAPS_COMPLEX (0x00000008)
#define DDSCAPS_TEXTURE (0x00001000)
#define DDSCAPS_MIPMAP  (0x00400000)

// Header::caps2
#define DDSCAPS2_CUBEMAP            (0x00000200)
#define DDSCAPS2_CUBEMAP_POSITIVEX  (0x00000400)
#define DDSCAPS2_CUBEMAP_NEGATIVEX  (0x00000800)
#define DDSCAPS2_CUBEMAP_POSITIVEY  (0x00001000)
#define DDSCAPS2_CUBEMAP_NEGATIVEY  (0x00002000)
#define DDSCAPS2_CUBEMAP_POSITIVEZ  (0x00004000)
#define DDSCAPS2_CUBEMAP_NEGATIVEZ  (0x00008000)
#define DDSCAPS2_VOLUME             (0x00200000)

#define DDSCAPS2_CUBEMAP_ALLFACES ( DDSCAPS2_CUBEMAP_POSITIVEX | \
                                    DDSCAPS2_CUBEMAP_NEGATIVEX | \
                                    DDSCAPS2_CUBEMAP_POSITIVEY | \
                                    DDSCAPS2_CUBEMAP_NEGATIVEY | \
                                    DDSCAPS2_CUBEMAP_POSITIVEZ | \
                                    DDSCAPS2_CUBEMAP_NEGATIVEZ )

namespace Nyx
{
namespace DDS
{

// Header10::resource_dimension
namespace ResourceDimensions
{
enum ResourceDimension
{
    Invalid = 0,

    Texture1D = 2,
    Texture2D = 3,
    Texture3D = 4,
};
} // namespace ResourceDimensions
typedef ResourceDimensions::ResourceDimension ResourceDimension;

#pragma pack(push, 1)

struct PixelFormat
{
    uint32_t size;
    uint32_t flags;
    uint32_t fourcc;
    uint32_t bit_count;
    uint32_t r_mask;
    uint32_t g_mask;
    uint32_t b_mask;
    uint32_t a_mask;
};

struct Header
{
    uint32_t    size;
    uint32_t    flags;
    uint32_t    height;
    uint32_t    width;
    uint32_t    pitch;
    uint32_t    depth;
    uint32_t    mip_levels;
    uint32_t    reserved1[11]; // not used
    PixelFormat pixel_format;
    uint32_t    caps1;
    uint32_t    caps2;
    uint32_t    caps3; // not used
    uint32_t    caps4; // not used
    uint32_t    reserved2; // not used
};

struct Header10
{
    uint32_t dxgi_format;
    uint32_t resource_dimension;
    uint32_t misc_flag;
    uint32_t array_size;
    uint32_t reserved;
};

#pragma pack(pop)

} // namespace DDS
} // namespace Nyx

#endif // NyxFileformat_DDS_H
