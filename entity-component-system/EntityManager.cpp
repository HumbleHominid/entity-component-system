#include "EntityManager.h"
#include "Entity.h"
#include "RenderComponent.h"
#include <assert.h>

namespace engine
{
    EntityManager::EntityManager() { }
    EntityManager::~EntityManager() { }

    inline unsigned __int32 make_component_id(size_t desc, unsigned __int16 type)
    {
        unsigned __int32 comp_id = type;
        comp_id |= (desc << 16);
        return comp_id;
    }

    void EntityManager::add_entity(entity_types entity_type)
    {
        assert(m_entities.size() < MAX_ENTITIES);
        
        entity e;
        e.id = (__int16) m_entities.size();

        // factory for making a new entity
        switch (entity_type)
        {
            case base:
            {
                // make the logging stuff
                e.components[logging] = (__int32) make_component_id(m_logging_components.size(), logging);
                LoggingComponent lc = LoggingComponent(e.id);
                m_logging_components.push_back(lc);
                // check that the allocated memory is less than or equal to the max entities. if not reallocate to the size of max_entities
                if (m_logging_components.capacity() > MAX_ENTITIES) m_logging_components.reserve(MAX_ENTITIES);

                // make the rendering stuff
                e.components[render] = (__int32) make_component_id(m_render_components.size(), render);
                RenderComponent rc = RenderComponent(e.id);
                m_render_components.push_back(rc);
                // check that the allocated memory is less than or equal to the max entities. if not reallocate to the size of max_entities
                if (m_render_components.capacity() > MAX_ENTITIES) m_render_components.reserve(MAX_ENTITIES);

                break;
            }
        }
        m_entities.push_back(e);
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
                size_t num_render_components_size = m_render_components.size() - 1;
                // set the one you are removing to the last one
                m_render_components[comp_index] = m_render_components[num_render_components_size];
                m_render_components.resize(num_render_components_size);
                break;
            }
            case logging:
            {
                size_t num_logging_components_size = m_logging_components.size() - 1;
                // set the one you are removing to the last one
                m_logging_components[comp_index] = m_logging_components[num_logging_components_size];
                m_logging_components.resize(num_logging_components_size);
                break;
            }
            }
        }
    }
}