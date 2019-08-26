#ifndef vector_4_h
#define vector_4_h

struct vec4
{
    float m_x;
    float m_y;
    float m_z;
    float m_w;

    vec4() : m_x(0), m_y(0), m_z(0), m_w(0) { }
    vec4(float x, float y, float z, float w) : m_x(x), m_y(y), m_z(z), m_w(w) { }
};

#endif