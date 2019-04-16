#include <iostream>
#include "EntityManager.h"
#include "RenderComponent.h"
#include <string>

int main()
{
    EntityManager em = EntityManager();
    // add some things
    for (unsigned __int8 i = 0; i < MAX_ENTITIES; i++)
    {
        component_type components[NUM_COMPONENTS] = { i % 2 ? none : render };
        em.add_entity(components);
    }
    
    // display some things
    RenderComponent *rcs = em.get_render_components();
    for (unsigned __int16 i = 0; i < em.get_num_render_components(); i++)
    {
        // there is some memory thing going on here and i don't know what is going on
        RenderComponent rc = rcs[i];
        rc.do_action();
    }

    // remove some things
    em.remove_entity(em.get_entity(0));
    
    // display some things
    rcs = em.get_render_components();
    for (unsigned __int16 i = 0; i < em.get_num_render_components(); i++)
    {
        // there is some memory thing going on here and i don't know what is going on
        RenderComponent rc = rcs[i];
        rc.do_action();
    }

    std::string s;
    getline(std::cin, s);
    return 0;
}