#ifndef vector_3_h
#define vector_3_h

struct vec3
{
    float m_x;
    float m_y;
    float m_z;

    vec3() : m_x(0), m_y(0), m_z(0) { }
    vec3(float x, float y, float z) : m_x(x), m_y(y), m_z(z) { }
};

#endif