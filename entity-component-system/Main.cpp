#include <iostream>
#include "EntityManager.h"
#include "RenderComponent.h"
#include <string>
#include <vector>

int main()
{
    EntityManager em = EntityManager();
    // add some things
    std::cout << "Adding some entities" << std::endl;
    for (unsigned __int8 i = 0; i < MAX_ENTITIES; i++)
    {
        component_type components[NUM_COMPONENTS] = { i % 2 ? none : render };
        em.add_entity(components);
    }
    
    // display some things
    for (auto &rc : em.get_render_components()) rc.render();

    // remove some things
    std::cout << "Removing some entities" << std::endl;
    em.remove_entity(em.get_entity(0));
    
    // display some things
    for (auto &rc : em.get_render_components()) rc.render();

    std::string s;
    getline(std::cin, s);

    return 0;
}