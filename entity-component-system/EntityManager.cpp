#include "EntityManager.h"
#include "Entity.h"
#include "HandleLogger.h"
#include "Handle.h"
#include "Position.h"

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

        // factory for making a new entity
        switch (entity_type)
        {
            case base:
            {
                // make the logging stuff
                e->components[handle_logger] = make_component_id(m_handle_logging_components.size(), handle_logger);
                HandleLogger hl = HandleLogger(&e->m_handle);
                m_handle_logging_components.push_back(hl);
                e->m_handle.m_counter++;
                if (m_handle_logging_components.capacity() > MAX_ENTITIES) m_handle_logging_components.reserve(MAX_ENTITIES);

                break;
            }
            case square:
            {
                // make the logging stuff
                e->components[handle_logger] = make_component_id(m_handle_logging_components.size(), handle_logger);
                HandleLogger hl = HandleLogger(&e->m_handle);
                m_handle_logging_components.push_back(hl);
                e->m_handle.m_counter++;
                if (m_handle_logging_components.capacity() > MAX_ENTITIES) m_handle_logging_components.reserve(MAX_ENTITIES);

                // make the logging stuff
                e->components[position] = make_component_id(m_position_componets.size(), position);
                Position p = Position();
                m_position_componets.push_back(p);
                e->m_handle.m_counter++;
                if (m_position_componets.capacity() > MAX_ENTITIES) m_position_componets.reserve(MAX_ENTITIES);

                break;
            }
        }

        return e->m_handle;
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
            case handle_logger:
            {
                size_t new_size = m_handle_logging_components.size() - 1;
                
                m_handle_logging_components[comp_index] = m_handle_logging_components[new_size];
                m_handle_logging_components.resize(new_size);
                e.m_handle.m_counter--;

                break;
            }
            case position:
            {
                size_t new_size = m_position_componets.size() - 1;
                
                m_position_componets[comp_index] = m_position_componets[new_size];
                m_position_componets.resize(new_size);
                e.m_handle.m_counter--;

                break;
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