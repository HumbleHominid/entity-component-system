#ifndef entity_manager_h
#define entity_manager_h

#include "EngineConsts.h"
#include "Entity.h"
#include "Handle.h"

// Components
#include "HandleLogger.h"
#include "PositionComponent.h"
#include "RenderComponent.h"

#include <vector>
#include <queue>
#include <bitset>

namespace engine
{
    class EntityManager
    {
    private:
        std::bitset<MAX_ENTITIES> m_available_entity_slots = std::bitset<MAX_ENTITIES>(MAX_ENTITIES);
        entity m_entities[MAX_ENTITIES];

        size_t next_available_entity_slot();

        std::vector<HandleLogger> m_handle_logging_components;
        std::vector<RenderComponent> m_render_components;
        std::vector<PositionComponent> m_position_components;
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
        inline entity* get_entities() { return m_entities; }

        // @Refactor with jai this can be done using meta programming
        // ---
        // Logging stuff
        inline std::vector<HandleLogger> get_logging_components() { return m_handle_logging_components; }
        inline size_t get_num_logging_components() { return m_handle_logging_components.size(); }

        // ---
        // Render stuff
        inline std::vector<RenderComponent> get_render_components() { return m_render_components; }
        inline size_t get_num_render_components() { return m_render_components.size(); }
        inline RenderComponent get_render_component(entity e) { return m_render_components[e.components[component_types::render_component] >> 16]; }


        // ---
        // Position stuff
        inline std::vector<PositionComponent>& get_position_components() { return m_position_components; }
        inline size_t get_num_position_components() { return m_position_components.size(); }
        inline PositionComponent& get_position_component(entity e) { return m_position_components[e.components[component_types::position_component] >> 16]; }

        // ---
        // Rendering
        void render();
    };
}

#endif