#ifndef entity_h
#define entity_h

#include "Handle.h"
#include "EngineConsts.h"

namespace engine
{
    struct entity
    {
        handle m_handle;
        // id of the componets that describe this entity
        // indexed bassed off of entity_components
        unsigned __int32 components[NUM_COMPONENTS];
    };
}

#endif