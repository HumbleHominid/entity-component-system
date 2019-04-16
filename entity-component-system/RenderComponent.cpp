#include "RenderComponent.h"
#include "Entity.h"
#include "EntityManager.h"
#include <iostream>

RenderComponent::RenderComponent() { }

RenderComponent::RenderComponent(unsigned __int16 entity_id) :
        m_entity_id(entity_id) { }

RenderComponent::~RenderComponent() { }

void RenderComponent::render()
{
    std::cout << "render:\t" << m_entity_id << std::endl;
}