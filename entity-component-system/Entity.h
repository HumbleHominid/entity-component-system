#ifndef entity_h
#define entity_h

const unsigned __int8 NUM_COMPONENTS = 1;

struct entity
{
    // @Note right now this is just an array index but this means i can't move
    //   the entities around in memory without messing up this id.
    unsigned __int16 id;
    // array of handles for a component. uses a simple bit shift for now
    // upper 16 is the index of the component in the arry
    // lower 16 is the type of the component
    unsigned __int32 components[NUM_COMPONENTS];
};

#endif