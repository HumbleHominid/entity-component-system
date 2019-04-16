#ifndef render_component_h
#define render_component_h

#include "Entity.h"
#include <iostream>

class RenderComponent
{
private:
    unsigned __int16 m_entity_id;
public:
    RenderComponent();
    RenderComponent(unsigned __int16 entity_id);
    ~RenderComponent();

    inline void render() { std::cout << "render:\t" << m_entity_id << std::endl; }
};

#endif