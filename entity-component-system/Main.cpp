#include <iostream>
#include "EntityManager.h"
#include "RenderComponent.h"
#include <string>

int main()
{
    EntityManager em = EntityManager();
    for (unsigned __int8 i = 0; i < MAX_ENTITIES; i++)
    {
        component_type components[NUM_COMPONENTS] = { i % 2 ? none : render };
        em.add_entity(components);
    }
    
    RenderComponent *rcs = em.get_render_components();
    for (unsigned __int16 i = 0; i < em.get_num_render_components(); i++)
    {
        RenderComponent rc = rcs[i];
        rc.do_action();
    }

    std::string s;
    getline(std::cin, s);
    return 0;
}