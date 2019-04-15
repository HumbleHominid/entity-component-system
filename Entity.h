#ifndef entity_h
#define entity_h

#include "EntityManager.h"

extern const int MAX_ENTITIES;

struct entity
{
    int id;
    int components[MAX_ENTITIES];
};

#endif