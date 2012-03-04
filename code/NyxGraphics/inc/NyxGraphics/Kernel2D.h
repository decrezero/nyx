#ifndef NyxGraphics_Kernel2D_h
#define NyxGraphics_Kernel2D_h

namespace Nyx
{

class Kernel2D
{
public:
    static int init(Kernel2D& obj, size_t spread);
    static void term(Kernel2D& obj);

    Kernel2D();

    ~Kernel2D();

    bool valid() const;

    size_t spread() const { return _spread; }

    size_t length() const;
    size_t width() const;

    float& at(int x, int y);
    const float& at(int x, int y) const;

    void set(const Kernel2D& rhs);

private:
    float* _data;

    size_t _spread;
};

inline bool Kernel2D::valid() const
{
    return _data != nullptr;
}

} // namespace Nyx

#endif // NyxGraphics_Kernel2D_h
