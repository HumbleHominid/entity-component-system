#ifndef vector_3_h
#define vector_3_h

struct vec3
{
    double m_x;
    double m_y;
    double m_z;

    vec3() : m_x(0), m_y(0), m_z(0) { }
    vec3(double x, double y, double z) : m_x(x), m_y(y), m_z(z) { }
};

#endif