#include "EntityManager.h"
#include "HandleLogger.h"

#include <iostream>
#include <string>
#include <vector>

int main()
{
    using namespace engine;
    EntityManager em = EntityManager();
    // add some things
    for (unsigned __int8 i = 0; i < MAX_ENTITIES; i++) em.add_entity(base);
    
    // display some things
    std::vector<HandleLogger> lcs = em.get_logging_components();
    
    printf("\nFirst logging pass:\n");
    for (auto lc : lcs) lc.log();

    // remove some things
    printf("\nRemoving entities 4 and 1:\n");
    em.remove_entity(em.get_entity_by_index(4));
    em.remove_entity(em.get_entity_by_index(1));
    
    // display some things
    lcs = em.get_logging_components();
    
    printf("\nSecond logging pass:\n");
    for (auto lc : lcs) lc.log();

    std::string s;
    getline(std::cin, s);
    return 0;
}