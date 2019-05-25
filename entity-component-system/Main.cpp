#include "Engine/EngineConsts.h"
#include "Engine/Entity.h"
#include "Engine/EntityManager.h"
#include "Engine/Handle.h"
#include "Engine/PositionComponent.h"

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
    {
        using namespace engine;
        EntityManager em = EntityManager();
        // add some things
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            handle h = em.add_entity(i % 2 == 0 ? triangle : square);
        }

        entity* entities = em.get_entities();
        std::vector<PositionComponent> &position_components = em.get_position_components();
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            unsigned __int32 comp_id = entities[i].components[entity_component_types::position];
            if (comp_id != component_types::none)
            {
                vec3 new_pos;
                new_pos.m_x = i;
                new_pos.m_y = i;
                new_pos.m_z = i;
                
                unsigned __int16 comp_index = (comp_id >> 16);
                position_components[comp_index].set_position(new_pos);
                position_components[comp_index].set_rotation(3.14159f / (i + 1));
            }
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

        // display all the positions
        printf("\nDisplaying the entity positions:\n");
        for (auto pc : em.get_position_components())
        {
            vec3 vec = pc.get_position();
            printf("\tX: %f\n", vec.m_x);
            printf("\tY: %f\n", vec.m_y);
            printf("\tZ: %f\n", vec.m_z);
            printf("\tRotation: %f\n", pc.get_rotation());
        }
        
        std::string s;
        getline(std::cin, s);
    }

    // ---
    // Actual OpenGL things yay
    return 0;
    {
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
    }

    return 0;
}
