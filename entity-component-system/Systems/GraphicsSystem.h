#ifndef graphics_system_h
#define graphics_system_h

#include "System.h"
#include "../Components/RenderComponent.h" // has mesh and tex

#include <vector>

namespace game_system
{
    class GraphicsSystem : public System
    {
    private:
        std::vector<component::RenderComponent> m_render_components;
    public:
        void update(float dt);
        void init(void);
    };
}

#endif