#ifndef entity_manager_h
#define entity_manager_h

#include "Entity.h"
#include "RenderComponent.h"
#include <vector>

const unsigned __int8 MAX_ENTITIES = 5;

enum component_type { none, render };

class EntityManager
{
private:
    std::vector<entity> m_entities;

    std::vector<RenderComponent> m_render_components;
public:
    EntityManager();
    ~EntityManager();
    void add_entity(component_type cts[NUM_COMPONENTS]); // factory method for creating a new entity
    void remove_entity(entity e);

    entity get_entity(unsigned __int16 id) const;
    std::vector<RenderComponent> get_render_components() const;
    unsigned __int16 get_num_render_components() const;
};

inline entity EntityManager::get_entity(unsigned __int16 id) const
{
    return m_entities[id];
}

inline std::vector<RenderComponent> EntityManager::get_render_components() const
{
    return m_render_components;
}

inline unsigned __int16 EntityManager::get_num_render_components() const
{
    return m_render_components.size();
}

#endif