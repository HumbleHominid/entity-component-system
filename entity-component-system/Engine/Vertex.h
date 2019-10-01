#ifndef vertex_h
#define vertex_h

#include "../Vector3.h"
#include "../Vector2.h"

namespace engine
{
    struct Vertex
    {
        vec3 m_position;
        vec3 m_normal;
        vec2 m_texture_coordinates;
    };
}

#endif