#include "EntityManager.h"

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
        handle h = em.add_entity(square);
        // update the positions
        unsigned __int32 comp_id = em.get_entity_by_handle(h).components[position];
        unsigned __int16 comp_index = (comp_id >> 16);
        Position &p = em.get_position_components()[comp_index];
        p.set_x(i % 2);
        p.set_y(i % 3);
        p.set_z(i % 4);
    }
    
    // display some things    
    printf("\nFirst logging pass:\n");
    for (auto lc : em.get_logging_components()) lc.log();

    printf("\nFirst position pass:\n");
    for (auto p : em.get_position_components())
    {
        printf("Position: %d %d %d\n", p.get_x(), p.get_y(), p.get_z());
    }

    // remove some things
    printf("\nRemoving entities 4 and 1:\n");
    em.remove_entity(em.get_entity_by_index(4));
    em.remove_entity(em.get_entity_by_index(1));

    printf("\nSettin entity in index 1 to position (1, 4, 9)\n");
    {
        // @Note this is super annoying and the entity manager should probably have a thing for this
        //  or better yet make a component manager that does this -mfryer 5/19
        unsigned __int32 comp_id = em.get_entity_by_index(1).components[position];
        unsigned __int16 comp_index = (comp_id >> 16);
        Position &p = em.get_position_components()[comp_index];
        p.set_x(1);
        p.set_y(4);
        p.set_z(9);
    }
    
    // display some things    
    printf("\nSecond logging pass:\n");
    for (auto lc : em.get_logging_components()) lc.log();

    printf("\nSecond position pass:\n");
    for (auto p : em.get_position_components())
    {
        printf("Position: %d %d %d\n", p.get_x(), p.get_y(), p.get_z());
    }

    std::string s;
    getline(std::cin, s);

    return 0;
}