#ifndef NyxCore_Endian_h
#define NyxCore_Endian_h

namespace Nyx
{

uint16_t byte_swap(uint16_t x);
uint32_t byte_swap(uint32_t x);
uint64_t byte_swap(uint64_t x);

inline uint16_t byte_swap(uint16_t x)
{
    return (x << 8) | (x >> 8);
}

inline uint32_t byte_swap(uint32_t x)
{
    return
        (x << 24) | ((x & 0x0000FF00) << 8) |
        (x >> 24) | ((x & 0x00FF0000) >> 8);
}

inline uint64_t byte_swap(uint64_t x)
{
    return
        (x << 56) | ((x & 0x00FF000000000000) << 40) | ((x & 0x0000FF0000000000) << 24) | ((x & 0x000000FF00000000) << 8) |
        (x >> 56) | ((x & 0x000000000000FF00) >> 40) | ((x & 0x0000000000FF0000) >> 24) | ((x & 0x00000000FF000000) >> 8);
}

} // namespace Nyx

#endif // NyxCore_Endian_h
