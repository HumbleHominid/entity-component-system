#ifndef render_component_h
#define render_component_h

#include "../Engine/Handle.h"

namespace component
{
    struct RenderComponent
    {
        unsigned __int32 m_texture; // @TODO flush this out to be an actual texture
        unsigned __int32 m_mesh;    // @TODO flush this out to be an actual mesh
        engine::handle m_entity_handle;     // Entity this render component belongs to. 
    };
}

#endif