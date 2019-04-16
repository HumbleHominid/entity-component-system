#ifndef render_component_h
#define render_component_h

#include "Component.h"
#include "Entity.h"

class RenderComponent : Component
{
private:
    unsigned __int16 m_entity_id;
public:
    RenderComponent();
    RenderComponent(unsigned __int16 entity_id);
    ~RenderComponent();
    unsigned __int16 get_entity_id();
    inline void do_action() const;
};

#endif