#ifndef entity_manager_h
#define entity_manager_h

#include "Entity.h"
#include "RenderComponent.h"
#include "LoggingComponent.h"

#include <vector>

namespace engine
{
    const size_t MAX_ENTITIES = 5;

    enum component_types { logging = 0, render = 1, none = 0xFF };
    enum entity_types { base }; // just used the logging thing

    class EntityManager
    {
    private:
        std::vector<entity> m_entities;

        std::vector<RenderComponent> m_render_components;

        std::vector<LoggingComponent> m_logging_components;
    public:
        EntityManager();
        ~EntityManager();
    
        void add_entity(entity_types entity_type);
        void remove_entity(entity e);

        inline entity get_entity(size_t id) { return m_entities[id]; }

        inline std::vector<RenderComponent> get_render_components() { return m_render_components; }
        inline size_t get_num_render_components() { return m_render_components.size(); }

        inline std::vector<LoggingComponent> get_logging_components() { return m_logging_components; }
        inline size_t get_num_logging_components() { return m_logging_components.size(); }
    };
}

#endif