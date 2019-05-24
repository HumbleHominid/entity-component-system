#include "RenderSquare.h"
#include "RenderComponent.h"

namespace engine
{
    RenderSquare::RenderSquare(int texture, int mesh)
    {
        m_texture = texture;
        m_mesh = mesh;
    }

    RenderSquare::~RenderSquare() { }
}