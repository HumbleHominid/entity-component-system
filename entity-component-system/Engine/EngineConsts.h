#ifndef engine_consts_h
#define engine_consts_h

namespace engine
{
    enum component_types { handle_logger = 0, render_component = 1, none = 0xFF };
    enum entity_types { base, square };

    const unsigned __int8 NUM_COMPONENTS = 2;
    const size_t MAX_ENTITIES = 5;
}

#endif