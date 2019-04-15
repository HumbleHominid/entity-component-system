#include "RenderComponent.h"
#include "Entity.h"
#include "EntityManager.h"
#include <iostream>

void RenderComponent::do_action(entity &e)
{
    std::cout << e.id << std::endl;
}