#ifndef NyxRender_VertexSemantic_h
#define NyxRender_VertexSemantic_h

namespace Nyx
{

namespace VertexSemantics
{
enum VertexSemantic
{
    Invalid,

    Binormal,
    Color,
    Normal,
    Position,
    Tangent,
    TexCoord,
};
} // namespace VertexSemantics
typedef VertexSemantics::VertexSemantic VertexSemantic;

const char* vertex_semantic_to_string(VertexSemantic e);

} // namespace Nyx

#endif // NyxRender_VertexSemantic_h
