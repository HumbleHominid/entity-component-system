#ifndef mesh_component_h
#define mesh_component_h

#include "../Engine/Vertex.h"

#include <vector>

namespace engine
{
    class Mesh
    {
        std::vector<Vertex> verticies;
    };
}

#endif