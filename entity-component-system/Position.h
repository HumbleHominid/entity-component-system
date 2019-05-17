#ifndef position_h
#define position_h

#include "Vector3.h"

class Position
{
private:
    vec3 m_position;
public:
    Position() {
        m_position.m_x = 0;
        m_position.m_y = 0;
        m_position.m_z = 0;
    }

    Position(__int32 x, __int32 y, __int32 z)
    {
        m_position.m_x = x;
        m_position.m_y = y;
        m_position.m_z = z;
    }

    inline __int32 get_x() const { return m_position.m_x; }
    inline __int32 get_y() const { return m_position.m_y; }
    inline __int32 get_z() const { return m_position.m_z; }

    inline void set_x(__int32 x) { m_position.m_x = x; } 
    inline void set_y(__int32 y) { m_position.m_y = y; }
    inline void set_z(__int32 z) { m_position.m_z = z; }

    ~Position() { }
};

#endif