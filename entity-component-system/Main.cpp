#include "Engine/EntityManager.h"
#include "Engine/Handle.h"
#include "Engine/Entity.h"
#include "Engine/EngineConsts.h"

#include <iostream>
#include <string>
#include <vector>

int main()
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

    return 0;
}
