#include "RenderComponent.h"
#include "Handle.h"
#include "PositionComponent.h"

#include <cmath>
#include <iostream>

namespace engine
{
    void RenderComponent::render(PositionComponent pc) const
    {
        // @Todo make this do a texture thing later
        // Get the position Component of the entity
        /*
        glBegin(GL_POLYGON);


        vec3 pos = pc.get_position();
        auto x = pos.m_x;
        auto y = pos.m_y;
        auto z = pos.m_z;
        auto rotation = pc.get_rotation();

        float theta = (2 * 3.14159f) / m_texture; // evenly spaced about circle
        float radius = 0.1f;
        for (size_t i = 0; i  < m_texture; i++)
        {
            float angle = theta * i +  rotation;
            glVertex3f(x + (radius * cos(angle)), y + (radius * sin(angle)), z);
        }

        glEnd();
        glFlush();
        */
    }
}