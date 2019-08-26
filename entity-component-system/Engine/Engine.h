#ifndef engine_h
#define engine_h

#include "../Systems/System.h"

#include <vector>

namespace engine
{
    class Engine
    {
    private:
        std::vector<game_system::System*> m_systems;
    public:
        Engine();
        inline void add(game_system::System *sys) { m_systems.push_back(sys); }
        void main_loop(void);
        void update(float dt);
        void render();
    };
}

#endif