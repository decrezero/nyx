#ifndef NyxRender_InputLayout_h
#define NyxRender_InputLayout_h

#include <NyxCore\Assert.h>

struct ID3D11InputLayout;

namespace Nyx
{

class VertexFormat;

class InputLayout
{
public:
    static int init(InputLayout& obj, const VertexFormat& vf, const void* code, size_t length);
    static void term(InputLayout& obj);

    InputLayout();

    ~InputLayout();

    ID3D11InputLayout* input_layout() const;

private:
    ID3D11InputLayout* _input_layout;
};

inline ID3D11InputLayout* InputLayout::input_layout() const
{
    NYX_ASSERT(_input_layout != nullptr);
    return _input_layout;
}

} // namespace Nyx

#endif // NyxRender_InputLayout_h
