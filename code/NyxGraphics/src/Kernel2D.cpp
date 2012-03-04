#include <NyxGraphics\Kernel2D.h>

#include <NyxCore\Assert.h>
#include <NyxMath\Common.h>

namespace Nyx
{

int Kernel2D::init(Kernel2D& obj, size_t spread)
{
    NYX_ASSERT(!obj.valid());

    obj._spread = spread;

    obj._data = new float[obj.length()];

    if (obj._data == nullptr)
    {
        return 1;
    }

    return 0;
}

void Kernel2D::term(Kernel2D& obj)
{
    delete[] obj._data;
    obj._data = nullptr;
}

Kernel2D::Kernel2D()
{
    _data = nullptr;

    _spread = 0;
}

Kernel2D::~Kernel2D()
{
    term(*this);
}

size_t Kernel2D::length() const
{
    size_t w = width();
    return w * w;
}

size_t Kernel2D::width() const
{
    return _spread * 2 + 1;
}

float& Kernel2D::at(int x, int y)
{
    NYX_ASSERT(abs(x) <= static_cast<int>(_spread));
    NYX_ASSERT(abs(y) <= static_cast<int>(_spread));

    size_t adj_x = x + _spread;
    size_t adj_y = y + _spread;

    return _data[width() * adj_y + adj_x];
}

const float& Kernel2D::at(int x, int y) const
{
    NYX_ASSERT(abs(x) <= static_cast<int>(_spread));
    NYX_ASSERT(abs(y) <= static_cast<int>(_spread));

    size_t adj_x = x + _spread;
    size_t adj_y = y + _spread;

    return _data[width() * adj_y + adj_x];
}

void Kernel2D::set(const Kernel2D& rhs)
{
    NYX_ASSERT(_spread == rhs._spread);

    size_t len = length();

    for (size_t i = 0; i < len; ++i)
    {
        _data[i] = rhs._data[i];
    }
}

} // namespace Nyx
