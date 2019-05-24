#ifndef render_component_h
#define render_component_h

namespace engine
{
    class RenderComponent
    {
    protected:
        int m_texture;  // @TODO flush this out to be an actual texture
        int m_mesh;     // @TODO flush this out to be an actual mesh
    public:
        virtual void render() const = 0;
    };
}

#endif