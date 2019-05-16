#ifndef handle_logger_h
#define handle_logger_h

#include "Handle.h"

#include <iostream>

namespace engine
{
    class HandleLogger
    {
    private:
        handle* m_entity_handle;
    public:
        HandleLogger() { }
        HandleLogger(handle* entity_handle) : m_entity_handle(entity_handle) { }
        ~HandleLogger() { }

        inline void log()
        {
            std::cout << "Handle id: " << m_entity_handle->as_uint32() << std::endl;
            std::cout << "\tCounter: " << m_entity_handle->m_counter << std::endl;
            std::cout << "\tType: " << m_entity_handle->m_type << std::endl;
            std::cout << "\tIndex: " << m_entity_handle->m_index << std::endl;
        }
    };
}

#endif