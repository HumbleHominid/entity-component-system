#include "RenderComponent.h"
#include "Handle.h"

#include <GL/glut.h>
#include <cmath>
#include <iostream>

namespace engine
{
    void RenderComponent::render() const
    {
        // @Note remove
        printf("Rendering:\n");
        printf("\tTexture: %d\n", m_texture);
        printf("\tMesh: %d\n", m_mesh);

        // @Todo make this do a texture thing later
        // Get the position Component of the entity
        glBegin(GL_POLYGON);

        float theta = (2 * 3.14159f) / m_texture; // evenly spaced about circle
        float radius = 0.2f;
        for (size_t i = 0; i  < m_texture; i++)
        {
            float angle = theta * i;
            glVertex3f(0.0f + (radius * cos(angle)), 0.0f + (radius * sin(angle)), 0.0f);
        }

        glEnd();
        glFlush();
    }
}