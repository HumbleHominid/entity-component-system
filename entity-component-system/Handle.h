#ifndef handle_h
#define handle_h

namespace engine
{
    // sums to 32 bits used
    const unsigned __int16 counter_bits = 10;
    const unsigned __int16 type_bits = 8;
    const unsigned __int16 index_bits = 14;
    
    struct handle
    {
        unsigned __int32 m_counter;
        unsigned __int32 m_type;
        unsigned __int32 m_index;

        handle() : m_index(0), m_counter(0), m_type(0) { }
        handle(unsigned __int32 counter, unsigned __int32 type, unsigned __int32 index) :
                m_counter(counter), m_type(type), m_index(index) { }

        inline unsigned __int32 as_uint32() const
        {
            return m_counter << (index_bits + type_bits) | m_type << (index_bits) | m_index;
        }
    };
}

#endif