#ifndef system_h
#define system_h

namespace game_system
{
    class System
    {
    public:
        virtual void update(float dt) = 0;
        virtual void init(void) = 0;
        // virtual void SendMessage(Message *msg) = 0;  @Note add me later
        virtual ~System() {} 
    };
}

#endif