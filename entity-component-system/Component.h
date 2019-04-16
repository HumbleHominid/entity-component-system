#ifndef component_h
#define component_h

#include "Entity.h"

class Component
{
public:
    virtual inline void do_action() const = 0;
};

#endif