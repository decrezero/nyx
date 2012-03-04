#include <NyxRender\InputLayout.h>

namespace Nyx
{

InputLayout::InputLayout()
{
    _input_layout = nullptr;
}

InputLayout::~InputLayout()
{
    term(*this);
}

} // namespace Nyx
