#ifndef render_component_h
#define render_component_h

namespace engine
{
    class RenderComponent
    {
    private:
        unsigned __int32 m_texture;  // @TODO flush this out to be an actual texture
        unsigned __int32 m_mesh;     // @TODO flush this out to be an actual mesh
    public:
        RenderComponent() : m_texture(0), m_mesh(0) { }
        RenderComponent(unsigned __int32 texture, unsigned __int32 mesh) : m_texture(texture), m_mesh(mesh) { } 
        ~RenderComponent() { }

        void render() const;
    };

    inline void RenderComponent::render() const
    {
        printf("Rendering:\n");
        printf("\tTexture: %d\n", m_texture);
        printf("\tMesh: %d\n", m_mesh);
    };
}

#endif