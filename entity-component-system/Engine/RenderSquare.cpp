#include "RenderSquare.h"
#include "RenderComponent.h"

namespace engine
{
    RenderSquare::RenderSquare()
    {
        m_texture = 0;
        m_mesh = 0;
    }

    RenderSquare::RenderSquare(int texture, int mesh)
    {
        m_texture = texture;
        m_mesh = mesh;
    }

    RenderSquare::~RenderSquare() { }
}