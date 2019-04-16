#ifndef entity_h
#define entity_h

const unsigned __int8 NUM_COMPONENTS = 1;

struct entity
{
    unsigned __int16 id;
    // id of the component
    unsigned __int32 components[NUM_COMPONENTS];
};

#endif