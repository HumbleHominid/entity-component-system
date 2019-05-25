#include "Engine/EntityManager.h"
#include "Engine/Handle.h"
#include "Engine/Entity.h"
#include "Engine/EngineConsts.h"

#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>

engine::EntityManager entity_manager;

void display(void)
{
    // Set the beackground to be a better color
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.35f, 0.36f, 0.43f, 1.0f); // Greyish color

    // Render all the current entities
    for (auto rc : entity_manager.get_render_components()) rc.render();

    glFlush();
}

int main(int argc, char** argv)
{
    // Engine tests in lieu of real tests for now lmao
    /*
    {
        using namespace engine;
        EntityManager em = EntityManager();
        // add some things
        for (unsigned __int8 i = 0; i < MAX_ENTITIES; i++)
        {
            handle h = em.add_entity(i % 2 == 0 ? triangle : square);
        }
        
        // display some things    
        printf("\nFirst logging pass:\n");
        for (auto lc : em.get_logging_components()) lc.log();

        // remove some things
        printf("\nRemoving entities 4 and 1:\n");
        em.remove_entity(em.get_entity_by_index(4).m_handle);
        em.remove_entity(em.get_entity_by_index(1).m_handle);
        
        // display some things    
        printf("\nSecond logging pass:\n");
        for (auto lc : em.get_logging_components()) lc.log();

        // call render on all of the entities
        printf("\nRendering the entities:\n");
        for (auto rc : em.get_render_components()) rc.render();
        
        std::string s;
        getline(std::cin, s);
    }
    */

    // ---
    // Actual OpenGL things yay
    
    // Add a bunch of shit so we can test
    for (unsigned __int8 i = 0; i < engine::MAX_ENTITIES; i++)
    {
        engine::handle h = entity_manager.add_entity(i % 2 == 0 ? engine::triangle : engine::square);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello World!");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
