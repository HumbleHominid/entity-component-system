#ifndef engine_consts_h
#define engine_consts_h

namespace engine
{
    // @NOTE These are the types of components we can make. not the ones an entity can hold.
    //  i.e. there will be multiple types of render components here but only one in the entity
    enum component_types { handle_logger, render_component, position_component, none = 0xFF };
    // @NOTE Thes are then components that describe an entity
    enum entity_component_types { logger = 0, render = 1, position = 2 };
    enum entity_types { base, triangle, square };

    const unsigned __int8 NUM_COMPONENTS = 3;
    const size_t MAX_ENTITIES = 10;
}

#endif