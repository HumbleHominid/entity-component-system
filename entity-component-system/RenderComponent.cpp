#include "RenderComponent.h"
#include "Entity.h"
#include "EntityManager.h"

RenderComponent::RenderComponent() { }

RenderComponent::RenderComponent(unsigned __int16 entity_id) :
        m_entity_id(entity_id) { }

RenderComponent::~RenderComponent() { }
