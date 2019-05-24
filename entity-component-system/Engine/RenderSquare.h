#ifndef render_square_h
#define render_square_h

#include <iostream>

#include "RenderComponent.h"

#include <iostream>

namespace engine
{
    class RenderSquare : RenderComponent
    {
    public:
        RenderSquare(int texture, int mesh); // @TODO update this so that it uses actual textures and meshes later
        ~RenderSquare();
        void render() const;
    };

    inline void RenderSquare::render() const
    {
        std::cout << "I am rendering a square!" << std::endl;
    }
}

#endif