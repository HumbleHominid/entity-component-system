#ifndef entity_manager_h
#define entity_manager_h

#include "Entity.h"
#include "RenderComponent.h"

const unsigned __int8 MAX_ENTITIES = 5;

enum component_type { none, render };

class EntityManager
{
private:
    unsigned __int16 m_num_entities;
    entity m_entities[MAX_ENTITIES];

    unsigned __int16 m_num_render_components;
    RenderComponent m_render_components[NUM_COMPONENTS];
public:
    EntityManager();
    ~EntityManager();
    void add_entity(component_type cts[NUM_COMPONENTS]);
    void remove_entity(entity e);

    inline entity get_entity(unsigned __int16 id) { return m_entities[id]; }
    inline RenderComponent* get_render_components() { return m_render_components; }
    inline unsigned __int16 get_num_render_components() { return m_num_render_components; }
};

#endif