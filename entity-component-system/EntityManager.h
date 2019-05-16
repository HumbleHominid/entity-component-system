#ifndef entity_manager_h
#define entity_manager_h

#include "Entity.h"
#include "HandleLogger.h"

#include <vector>
#include <queue>

namespace engine
{
    const size_t MAX_ENTITIES = 5;

    class EntityManager
    {
    private:
        std::priority_queue<size_t, std::vector<size_t>, std::greater<size_t>> m_available_entity_slots;
        entity m_entities[MAX_ENTITIES];

        std::vector<HandleLogger> m_handle_logging_components;
    public:
        EntityManager();
        ~EntityManager() { }
    
        void add_entity(entity_types entity_type);
        void remove_entity(entity e);

        inline entity get_entity(size_t id) { return m_entities[id]; }
        inline entity get_entity_by_index(size_t index) { return m_entities[index]; }
        // @Note this gets the entity by using the handle's m_index property
        inline entity get_entity_by_id(handle hand) { return m_entities[hand.m_index]; }

        inline std::vector<HandleLogger> get_logging_components() { return m_handle_logging_components; }
        inline size_t get_num_logging_components() { return m_handle_logging_components.size(); }
    };
}

#endif