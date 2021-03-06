#ifndef position_component_h
#define position_component_h

#include "../Vector3.h"

namespace engine
{
    class PositionComponent
    {
    private:
        vec3 m_position;
        float m_rotation;
    public:
        PositionComponent() : m_rotation(0.0f) { }
        PositionComponent(vec3 position, float rotation) :
                m_position(position), m_rotation(rotation) { }
        ~PositionComponent() { }
    
        inline vec3 get_position() { return m_position; }
        inline float get_rotation() { return m_rotation; }
        inline void set_position(vec3 position) { m_position = position; }
        inline void set_rotation(float rotation) { m_rotation = rotation; }
    };
}

#endif