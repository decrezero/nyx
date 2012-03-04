#include <NyxRender\VertexSemantic.h>

namespace Nyx
{

const char* vertex_semantic_to_string(VertexSemantic e)
{
    using namespace VertexSemantics;

    switch (e)
    {
        case Binormal:
            return "BINORMAL";
        case Color:
            return "COLOR";
        case Normal:
            return "NORMAL";
        case Position:
            return "POSITION";
        case Tangent:
            return "TANGENT";
        case TexCoord:
            return "TEXCOORD";
        default:
            return 0;
    }
}

} // namespace Nyx
