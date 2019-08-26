#ifndef physics_system_h
#define physics_system_h

#include "System.h"
#include "../Components/PositionComponent.h"

#include <vector>

namespace game_system
{
    class PhysicsSystem : public System
    {
    private:
        std::vector<component::PositionComponent> m_position_components;
    public:
        void update(float dt);
        void init(void);
    };
}

#endif