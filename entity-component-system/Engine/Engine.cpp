#include "Engine.h"
#include "../Systems/System.h"
#include "../Systems/GraphicsSystem.h"
#include "../Vector3.h"

#include <iostream>
#include <string>
#include <GL/glut.h>
#include <vector>

namespace engine
{
    Engine::Engine()
    {
        // Set up all the systems you are going to need
        add(new game_system::GraphicsSystem());
    }

    void Engine::main_loop(void)
    {
        printf("Engine MainLoop\n");
        // Set the beackground to be a better color
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.35f, 0.36f, 0.43f, 1.0f); // Greyish color
        update(0);
    }

    void Engine::render()
    {
        // the first thing will always be the render system
        m_systems[0]->update(0);
        // we just need to get the mesh, position, and vbo off of the entity
    }

    void Engine::update(float dt)
    {
        // we are going to skip the first one as it is the render system.
        for (std::vector<game_system::System*>::iterator it = ++(m_systems.begin()); it != m_systems.end();) (*it)->update(dt);
    }

    void render(vec3 pos, int VBO, std::vector<float> mesh)
    {

    }
}