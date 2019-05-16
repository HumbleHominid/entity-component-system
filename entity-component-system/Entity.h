#ifndef entity_h
#define entity_h

namespace engine
{
    const unsigned __int8 NUM_COMPONENTS = 2;

    struct entity
    {
        unsigned __int16 id;
        // id of the componets that describe this entity
        // { logging, render }
        unsigned __int32 components[NUM_COMPONENTS];
    };
}

#endif