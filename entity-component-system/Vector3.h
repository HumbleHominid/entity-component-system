#ifndef vector_3_h
#define vector_3_h

struct vec3
{
    __int32 m_x;
    __int32 m_y;
    __int32 m_z;

    vec3() : m_x(0), m_y(0), m_z(0) { }
    vec3(__int32 x, __int32 y, __int32 z) : m_x(x), m_y(y), m_z(z) { }
};

#endif