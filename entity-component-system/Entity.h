#ifndef entity_h
#define entity_h

#include "Handle.h"

namespace engine
{
    enum component_types { handle_logger = 0, position = 1, none = 0xFF };
    enum entity_types { base, square }; // just uses the logging thing

    const unsigned __int8 NUM_COMPONENTS = 2;

    struct entity
    {
        // 32 bit integer. 
        // upper 8 bits are the type of entity (max: 256)
        // middle 10 bits are the references (max: 1024)
        // lower 14 bits for the index (max: 16384) (of same type)
        handle m_handle;
        // id of the componets that describe this entity
        // { handle_logger }
        unsigned __int32 components[NUM_COMPONENTS];
    };
}

#endif