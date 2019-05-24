#ifndef entity_manager_h
#define entity_manager_h

#include "Handle.h"
#include "Entity.h"
#include "EngineConsts.h"
#include "HandleLogger.h"
#include "RenderComponent.h"

#include <vector>
#include <queue>

namespace engine
{
    class EntityManager
    {
    private:
        std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> m_available_entity_slots;
        entity m_entities[MAX_ENTITIES];

        std::vector<HandleLogger> m_handle_logging_components;
        std::vector<RenderComponent> m_render_components;
    public:
        EntityManager();
        ~EntityManager() { }

        // ---
        // Entity Stuff
        handle add_entity(entity_types entity_type);
        void remove_entity(handle h);

        inline entity get_entity_by_index(size_t index) { return m_entities[index]; }
        // @Note this gets the entity by using the handle's m_index property
        inline entity get_entity_by_handle(handle hand) { return m_entities[hand.m_index]; }

        // @Refactor with jai this can be done using meta programming
        // ---
        // Logging stuff
        inline std::vector<HandleLogger> get_logging_components() { return m_handle_logging_components; }
        inline size_t get_num_logging_components() { return m_handle_logging_components.size(); }

        // ---
        // Render stuf
        inline std::vector<RenderComponent> get_render_components() { return m_render_components; }
        inline size_t get_num_render_components() { return m_render_components.size(); }
    };
}

#endif