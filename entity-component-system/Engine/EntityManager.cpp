#include "Entity.h"
#include "EntityManager.h"
#include "Handle.h"
#include "HandleLogger.h"
#include "RenderSquare.h"

#include <assert.h>

namespace engine
{
    EntityManager::EntityManager()
    {
        // set all the entity slots to be initially available
        for (size_t i = 0; i < MAX_ENTITIES; i++) m_available_entity_slots.push(i);
    }

    inline unsigned __int32 make_component_id(size_t desc, unsigned __int16 type)
    {
        unsigned __int32 comp_id = type;
        comp_id |= (desc << 16);
        return comp_id;
    }

    // creates a new entity based on the type of entity to make that is passed in.
    handle EntityManager::add_entity(entity_types entity_type)
    {
        assert(!m_available_entity_slots.empty());
        
        size_t next_available = m_available_entity_slots.top();
        m_available_entity_slots.pop();
        entity* e = &m_entities[next_available];
        e->m_handle = handle(0, entity_type, next_available);

        // all components have the handle logger
        {
            e->components[handle_logger] = make_component_id(m_handle_logging_components.size(), handle_logger);
            HandleLogger hl = HandleLogger(&e->m_handle);
            m_handle_logging_components.push_back(hl);
            e->m_handle.m_counter++;
            if (m_handle_logging_components.capacity() > MAX_ENTITIES) m_handle_logging_components.reserve(MAX_ENTITIES);
        }

        // factory for making a new entity
        switch (entity_type)
        {
            case base:
            {
                for (size_t i = 0; i < NUM_COMPONENTS; i++) e->components[i] = none;

                break;
            }
            case square:
            {
                e->components[render_component] = none;

                break;
            }
        }

        return e->m_handle;
    }

    void EntityManager::remove_entity(handle h)
    {
        entity e = get_entity_by_handle(h);
        
        for (size_t i = 0; i < NUM_COMPONENTS; i++)
        {
            unsigned __int32 comp_id = e.components[i];
            unsigned __int16 comp_type = comp_id;
            unsigned __int16 comp_index = (comp_id >> 16);

            switch(comp_type)
            {
            case none: break;
            case handle_logger:
            {
                size_t new_size = m_handle_logging_components.size() - 1;
                
                m_handle_logging_components[comp_index] = m_handle_logging_components[new_size];
                m_handle_logging_components.resize(new_size);
                e.m_handle.m_counter--;

                break;
            }
            case render_component:
            {
                // get the type of component
                
            }
            }
        }

        // @Note we update the available entites every time we remove one because one entity might have references to another one. -mfryer 5/19
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            entity cur_entity = m_entities[i];
            
            if (cur_entity.m_handle.m_counter < 1) m_available_entity_slots.push(cur_entity.m_handle.m_index);
        }
    }
}