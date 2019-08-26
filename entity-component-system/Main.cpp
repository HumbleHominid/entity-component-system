#include "Engine/EngineConsts.h"
#include "Engine/Entity.h"
#include "Engine/EntityManager.h"
#include "Engine/Handle.h"
#include "Engine/PositionComponent.h"
#include "Engine/EngineConsts.h"

#include <iostream>
#include <string>
#include <vector>
#include <GL/glut.h>
#include <cmath>

engine::EntityManager entity_manager;

void display(void)
{
    using namespace engine;
    // Set the beackground to be a better color
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.35f, 0.36f, 0.43f, 1.0f); // Greyish color

    // Render all the current entities
    entity_manager.render();
    // get all my entities to render
    entity* entities = entity_manager.get_entities();

    for (size_t i = 0; i < MAX_ENTITIES; i++)
    {
        entity e = *entities;
        
        PositionComponent pc = entity_manager.get_position_component(e);
        RenderComponent rc = entity_manager.get_render_component(e);

        rc.render(pc);

        entities++;
    }

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
            em.add_entity(i % 2 == 0 ? triangle : square);
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
        // for (auto rc : em.get_render_components()) rc.render();

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
        // getline(std::cin, s);
    }

    // ---
    // Actual OpenGL things yay
    {
        using namespace engine;
        // Add one triangle for the player and fill the rest with squares
        handle player_handle = entity_manager.add_entity(triangle);
        {
            entity e = entity_manager.get_entity_by_handle(player_handle);
            PositionComponent& pc = entity_manager.get_position_component(e);
            
            vec3 new_pos;
            new_pos.m_x = 0;
            new_pos.m_y = -0.8f;

            pc.set_position(new_pos);
            pc.set_rotation(3.14159f / (-6));
        }
        int count = 0;
        while (!entity_manager.is_max_entities())
        {
            handle h = entity_manager.add_entity(square);
            entity e = entity_manager.get_entity_by_handle(h);
            PositionComponent& pc = entity_manager.get_position_component(e);

            vec3 new_pos;
            float num = count * 0.9f;
            new_pos.m_x = cos(sqrt(num));
            new_pos.m_y = cos(num);
            new_pos.m_y *= new_pos.m_y;
            new_pos.m_y *= 0.25f;
            new_pos.m_y += 0.5f;

            pc.set_position(new_pos);
            pc.set_rotation(3.14159f / 2);
            count++;
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
