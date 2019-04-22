#include "EntityManager.h"
#include "Entity.h"
#include "RenderComponent.h"
#include <assert.h>
#include <vector>

EntityManager::EntityManager()
{
    m_entities = std::vector<entity>();
    m_render_components = std::vector<RenderComponent>();
}

EntityManager::~EntityManager() { }

inline unsigned __int32 make_component_id(unsigned __int16 desc, unsigned __int16 type)
{
    unsigned __int32 comp_id = type;
    comp_id |= (desc << 16);
    return comp_id;
}

void EntityManager::add_entity(component_type cts[NUM_COMPONENTS])
{
    size_t num_entities = m_entities.size();
    assert(num_entities < MAX_ENTITIES);
    entity e;
    e.id = num_entities;
    for (unsigned __int8 i = 0; i < NUM_COMPONENTS; i++)
    {
        switch (cts[i])
        {
        case none:
        {
            e.components[i] = none;
            break;
        }
        case render:
        {
            unsigned __int16 num_render_components = m_render_components.size();
            m_render_components.push_back(RenderComponent(e.id));
            e.components[i] = make_component_id(num_render_components, render);
            
            break;
        }
        }
    }
    m_entities.push_back(e);
    // If we allocated more memory than our MAX_ENTITIES change the size
    if (m_entities.capacity() > MAX_ENTITIES) m_entities.reserve(MAX_ENTITIES);
    if (m_render_components.capacity() > MAX_ENTITIES) m_render_components.reserve(MAX_ENTITIES);
}

void EntityManager::remove_entity(entity e)
{
    for (unsigned __int8 i = 0; i < NUM_COMPONENTS; i++)
    {
        unsigned __int32 comp_id = e.components[i];
        unsigned __int16 comp_type = comp_id;
        unsigned __int16 comp_index = (comp_id >> 16);

        switch(comp_type)
        {
        case none:
        case render:
        {
            size_t num_render_components = m_render_components.size();
            m_render_components[comp_index] = m_render_components[num_render_components - 1]; //move the last thing in the list to the spot we want to remove
            // shrink the array
            m_render_components.resize(num_render_components - 1);
            break;
        }
        }
    }
}