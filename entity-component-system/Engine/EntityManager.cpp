#include "Entity.h"
#include "EntityManager.h"
#include "Handle.h"
#include "HandleLogger.h"
#include "RenderSquare.h"
#include "EngineConsts.h"

#include <assert.h>

namespace engine
{
    EntityManager::EntityManager()
    {
        // set all the entity slots to be initially available
        for (size_t i = 0; i < MAX_ENTITIES; i++) m_available_entity_slots.push(i);
    }

    unsigned __int32 make_component_id(size_t index, component_types type) { return (index << 16) | type; }

    // creates a new entity based on the type of entity to make that is passed in.
    handle EntityManager::add_entity(entity_types entity_type)
    {
        assert(!m_available_entity_slots.empty());
        
        // --
        // get the next available entity position
        size_t next_available = m_available_entity_slots.top();
        m_available_entity_slots.pop();
        entity* e = &m_entities[next_available];
        e->m_handle = handle(0, entity_type, next_available);

        // all components have the handle logger for their logger component
        // @Refactor should be able to make a meta program to handle this genericly
        {
            // @Note using the namespace to be more explicit
            e->components[entity_component_types::logger] = make_component_id(m_handle_logging_components.size(), component_types::handle_logger);
            HandleLogger hl = HandleLogger(&e->m_handle);
            m_handle_logging_components.push_back(hl);
            e->m_handle.m_counter++;
            if (m_handle_logging_components.capacity() > MAX_ENTITIES) m_handle_logging_components.reserve(MAX_ENTITIES);
        }

        // factory for making a new entity
        switch (entity_type)
        {
            case entity_types::base:
            {
                for (size_t i = 0; i < NUM_COMPONENTS; i++) e->components[i] = none;

                break;
            }
            case square:
            {
                // @Note using the namespace to be more explicit
                e->components[entity_component_types::render] = make_component_id(m_render_square_components.size(), component_types::render_square);
                RenderSquare rs = RenderSquare(0, 0); // @Note change to actual texture and mest later
                m_render_square_components.push_back(rs);
                e->m_handle.m_counter++;
                if (m_render_square_components.capacity() > MAX_ENTITIES) m_render_square_components.reserve(MAX_ENTITIES);            

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

            // @Refactor This should be handled with meta programming so i
            //  don't have to change this method every damn time i add a new component
            switch(comp_type)
            {
            case component_types::none: break;
            case component_types::handle_logger:
            {
                size_t new_size = m_handle_logging_components.size() - 1;
                
                m_handle_logging_components[comp_index] = m_handle_logging_components[new_size];
                m_handle_logging_components.resize(new_size);
                e.m_handle.m_counter--;

                break;
            }
            case component_types::render_square:
            {
                size_t new_size = m_render_square_components.size() - 1;
                
                m_render_square_components[comp_index] = m_render_square_components[new_size];
                m_render_square_components.resize(new_size);
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

    void EntityManager::render_entities() const
    {
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            entity e = m_entities[i];
            handle h = e.m_handle;

            if (h.m_counter < 0) continue;
            
            unsigned __int32 comp_id = e.components[entity_component_types::render];
            // @Note chops upper bits
            unsigned __int16 comp_type = comp_id;

            if (comp_type == component_types::none) continue;

            // @Refactor Meta programmig yo
            switch (comp_type)
            {
            case component_types::render_square:
            {
                unsigned __int16 comp_index = (comp_id >> 16);

                if (comp_index >= m_render_square_components.size()) break;
                    
                m_render_square_components[comp_index].render();
            }
            }
        }
    }
}