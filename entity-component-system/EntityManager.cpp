#include "EntityManager.h"
#include "Entity.h"
#include "RenderComponent.h"
#include "Component.h"
#include <assert.h>
#include <iostream>

EntityManager::EntityManager() : m_num_entities(0), m_num_render_components(0) { }

EntityManager::~EntityManager() { }

inline unsigned __int32 make_component_id(unsigned __int16 desc, unsigned __int16 type)
{
    unsigned __int32 comp_id = render;
    comp_id |= (desc << 16);
    return comp_id;
}

void EntityManager::add_entity(component_type cts[NUM_COMPONENTS])
{
    assert(m_num_entities < MAX_ENTITIES);
    m_entities[m_num_entities].id = m_num_entities;
    for (unsigned __int8 i = 0; i < NUM_COMPONENTS; i++)
    {
        switch (cts[i])
        {
        case none:
        {
            m_entities[m_num_entities].components[i] = none; // i think this works /shrug
            break;
        }
        case render:
        {
            m_render_components[m_num_render_components] = RenderComponent(m_entities[m_num_entities].id);
            m_entities[m_num_entities].components[i] = make_component_id(++m_num_render_components, render);
            
            break;
        }
        }
    }
    m_num_entities++;
}

inline entity EntityManager::get_entity(unsigned __int16 id)
{
    return m_entities[id];
}

void EntityManager::remove_entity(entity &e)
{
    // call the destructor for all the components
    for (unsigned __int8 i = 0; i < NUM_COMPONENTS; i++)
    {
        unsigned __int32 comp_id = e.components[i];
        unsigned __int16 comp_type = (comp_id |= 0xFF);
        unsigned __int16 comp_index = (comp_id >> 16);

        switch(comp_type)
        {
        case none:
        case render:
        {
            m_render_components[comp_index] = m_render_components[--m_num_render_components];

            break;
        }
        }
    }

    // move it so we don't have gaps in the array
    m_entities[e.id] = m_entities[--m_num_entities];
}

RenderComponent* EntityManager::get_render_components()
{
    return m_render_components;
}

unsigned __int16 EntityManager::get_num_render_components()
{
    return m_num_render_components;
}