#include "wscPsExchangeBuffer.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/net/wscDatagramPacket.h>
#include <wcpp/wspr/wsuSingleLock.h>
#include <wcpp/lang/wscArray.h>


wscPsExchangeBuffer::wscPsExchangeBuffer(void) : m_count_packet_limit(1024) , m_packet_buffer_length(4096)
{
}


wscPsExchangeBuffer::~wscPsExchangeBuffer(void)
{
}




ws_result wscPsExchangeBuffer::AllocatePacket(wsiDatagramPacket ** ret)
{
    ws_result rlt = InternalAllocatePacket(ret);
    if (rlt==WS_RLT_SUCCESS) return rlt;

    if ( InternalCountReadyPacket() < m_count_packet_limit ) {
        ws_int len = m_packet_buffer_length;
        ws_ptr<wsiByteArray> buf;
        rlt = NewObj<wscByteArray>( &buf , len );
        return NewObj<wscDatagramPacket>( ret , buf , len );
    }
    else {
        return WS_RLT_FAILED;
    }
}


ws_int wscPsExchangeBuffer::InternalCountReadyPacket(void)
{
    wsuSingleLock lock( & m_mutex );
    return static_cast<ws_int>( m_ready_list.size() );
}


ws_result wscPsExchangeBuffer::InternalAllocatePacket(wsiDatagramPacket ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    WS_ASSERT( (*ret)==WS_NULL );

    wsuSingleLock lock( & m_mutex );
    if (m_free_list.size() <= 0) {
        return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    }
    else {
        (*ret) = m_free_list.front();
        m_free_list.pop_front();
        return WS_RLT_SUCCESS;
    }
}


ws_result wscPsExchangeBuffer::PushPacket(wsiDatagramPacket *  packet)
{
    if (packet==WS_NULL) return WS_RLT_NULL_POINTER;
    packet->AddRef();

    wsuSingleLock lock( & m_mutex );
    m_ready_list.push_back( packet );
    return WS_RLT_SUCCESS;
}


ws_result wscPsExchangeBuffer::PopPacket(wsiDatagramPacket ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    WS_ASSERT( (*ret)==WS_NULL );

    wsuSingleLock lock( & m_mutex );
    if (m_ready_list.size() <= 0) {
        return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS;
    }
    else {
        (*ret) = m_ready_list.front();
        m_ready_list.pop_front();
        return WS_RLT_SUCCESS;
    }
}


ws_result wscPsExchangeBuffer::RecyclePacket(wsiDatagramPacket *  packet)
{
    if (packet==WS_NULL) return WS_RLT_NULL_POINTER;
    packet->AddRef();

    wsuSingleLock lock( & m_mutex );
    m_free_list.push_back( packet );
    return WS_RLT_SUCCESS;
}

