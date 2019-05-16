#ifndef logging_component_h
#define logging_component_h

#include "Entity.h"
#include <iostream>

namespace engine
{
    class LoggingComponent
    {
    private:
        unsigned __int16 m_entity_id;
    public:
        LoggingComponent() { };
        LoggingComponent(unsigned __int16 entity_id) : m_entity_id(entity_id) { };
        ~LoggingComponent() { };

        inline void log() { std::cout << "Logging: " << m_entity_id << std::endl; };
    };
}

#endif