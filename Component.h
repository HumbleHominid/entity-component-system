#ifndef component_h
#define component_h

#include "Entity.h"

class Component
{
public:
    virtual void do_action(entity &e) = 0;
};

#endif