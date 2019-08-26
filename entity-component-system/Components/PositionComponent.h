#ifndef position_component_h
#define position_component_h

#include "../Vector3.h"

namespace component
{
    struct PositionComponent
    {
        vec3 m_position;
        float m_rotation;
    };
}

#endif