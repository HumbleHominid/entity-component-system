#ifndef render_component_h
#define render_component_h

#include "Entity.h"
#include <iostream>

class RenderComponent
{
private:
    unsigned __int16 m_entity_id; // id of the entity this component belongs to
public:
    RenderComponent();
    RenderComponent(unsigned __int16 entity_id);
    ~RenderComponent();

    void render() const;
};

inline void RenderComponent::render() const 
{
    std::cout << "render:\t" << m_entity_id << std::endl;
}

#endif