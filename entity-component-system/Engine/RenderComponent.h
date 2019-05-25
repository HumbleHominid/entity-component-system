#ifndef render_component_h
#define render_component_h

#include "Handle.h"

namespace engine
{
    class RenderComponent
    {
    private:
        unsigned __int32 m_texture;  // @TODO flush this out to be an actual texture
        unsigned __int32 m_mesh;     // @TODO flush this out to be an actual mesh
        handle m_entity_handle;
    public:
        RenderComponent() : m_texture(0), m_mesh(0) { }
        RenderComponent(unsigned __int32 texture, unsigned __int32 mesh, handle entity_handle) :
                m_texture(texture), m_mesh(mesh), m_entity_handle(entity_handle) { } 
        ~RenderComponent() { }

        void render() const;
    };
}

#endif