#include "EngineConsts.h"
#include "Entity.h"
#include "EntityManager.h"
#include "Handle.h"

// Components
#include "HandleLogger.h"
#include "RenderComponent.h"
#include "PositionComponent.h"

#include <assert.h>

namespace engine
{
    EntityManager::EntityManager() {
        for (size_t i = 0; i < m_available_entity_slots.size(); i++) m_available_entity_slots.set(i);   
    }

    unsigned __int32 make_component_id(size_t index, component_types type) { return (index << 16) | type; }

    template<class T>
    void add_component(entity *e, std::vector<T> &component_list, entity_component_types ect, component_types ct, T comp_to_add)
    {
        e->components[ect] = make_component_id(component_list.size(), ct);
        component_list.push_back(comp_to_add);
        e->m_handle.m_counter++;
        if (component_list.capacity() > MAX_ENTITIES) component_list.reserve(MAX_ENTITIES);
    }

    template<class T>
    void delete_component(std::vector<T> &component_list, entity &e, size_t index)
    {
        size_t new_size = component_list.size() - 1;
        
        component_list[index] = component_list[new_size];
        component_list.resize(new_size);
        e.m_handle.m_counter--;
    }

    size_t EntityManager::next_available_entity_slot()
    {
        for (size_t i = 0; i < m_available_entity_slots.size(); i++)
        {
            if (m_available_entity_slots[i]) return i;
        }

        return -1;
    }

    // creates a new entity based on the type of entity to make that is passed in.
    handle EntityManager::add_entity(entity_types entity_type)
    {
        if (!m_available_entity_slots.any()) return handle(0, entity_types::base, -1);
        // --
        // get the next available entity position
        size_t next_available = next_available_entity_slot();
        entity* e = &m_entities[next_available];
        e->m_handle = handle(0, entity_type, next_available);
        m_available_entity_slots.set(next_available, 0);

        // all components have the handle logger for their logger component
        {
            HandleLogger hl = HandleLogger(&e->m_handle);
            add_component<HandleLogger>(e, m_handle_logging_components, entity_component_types::logger, component_types::handle_logger, hl);
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
                RenderComponent rc = RenderComponent(4, 0, e->m_handle);
                add_component<RenderComponent>(e, m_render_components, entity_component_types::render, component_types::render_component, rc);

                PositionComponent pc = PositionComponent();
                add_component<PositionComponent>(e, m_position_components, entity_component_types::position, component_types::position_component, pc);

                break;
            }
            case triangle:
            {
                RenderComponent rc = RenderComponent(3, 0, e->m_handle);
                add_component<RenderComponent>(e, m_render_components, entity_component_types::render, component_types::render_component, rc);

                PositionComponent pc = PositionComponent();
                add_component<PositionComponent>(e, m_position_components, entity_component_types::position, component_types::position_component, pc);
                
                break;
            }
            default:
            {
                for (size_t i = 0; i < NUM_COMPONENTS; i++) e->components[i] = none;
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
            case component_types::none: break;
            case component_types::handle_logger:
            {
                delete_component<HandleLogger>(m_handle_logging_components, e, comp_index);
                break;
            }
            case component_types::render_component:
            {
                delete_component<RenderComponent>(m_render_components, e, comp_index);
                break;
            }
            case component_types::position_component:
            {
                delete_component<PositionComponent>(m_position_components, e, comp_index);
                break;
            }
            }
        }

        // @Note we update the available entites every time we remove one because one entity might have references to another one. -mfryer 5/19
        for (size_t i = 0; i < MAX_ENTITIES; i++)
        {
            entity cur_entity = m_entities[i];
            
            if (cur_entity.m_handle.m_counter < 1) m_available_entity_slots.set(cur_entity.m_handle.m_index);
        }
    }

    void EntityManager::render()
    {

    }
}