#ifndef vector_2_h
#define vector_2_h

struct vec2
{
    float m_x;
    float m_y;

    vec2() : m_x(0), m_y(0) { }
    vec2(float x, float y) : m_x(x), m_y(y) { }
};

#endif
