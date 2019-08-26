#include "GraphicsSystem.h"
#include "../Components/RenderComponent.h"
#include "../Components/PositionComponent.h"

#include <GL/glut.h>
#include <cmath>
#include <iostream>

namespace game_system
{
    void GraphicsSystem::update(float dt)
    {
        for (auto rc : m_render_components)
        {
            // rc has m_texture and m_mesh. I need to get the position component somehow.

            printf("Rendering:\n");
            printf("\tTexture: %d\n", rc.m_texture);
            printf("\tMesh: %d\n", rc.m_mesh);

            // @Todo make this do a texture thing later
            // Get the position Component of the entity
            glBegin(GL_POLYGON);

            float theta = (2 * 3.14159f) / rc.m_texture; // evenly spaced about circle
            float radius = 0.2f;
            for (size_t i = 0; i  < rc.m_texture; i++)
            {
                float angle = theta * i;
                glVertex3f(0.0f + (radius * cos(angle)), 0.0f + (radius * sin(angle)), 0.0f);
            }
        }
        // @Note remove

        glEnd();
        glFlush();
    }
    void GraphicsSystem::init(void) { }
}