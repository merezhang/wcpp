#include "wscDatagramPacket.h"
#include <wcpp/lang/wscThrowable.h>


wscDatagramPacket::wscDatagramPacket(wsiByteArray * buf , ws_int length) : m_length(length)
{
    m_buffer.Set( buf );
}


wscDatagramPacket::~wscDatagramPacket(void)
{
}




ws_result wscDatagramPacket::GetAddress(wsiInetAddress ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::GetData(wsiByteArray ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_buffer.Get( ret );
    if ((*ret)==WS_NULL) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_int wscDatagramPacket::GetLength(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscDatagramPacket::GetOffset(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscDatagramPacket::GetPort(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::GetSocketAddress(wsiSocketAddress ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetAddress(wsiInetAddress * iaddr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetData(wsiByteArray * buf)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetData(wsiByteArray * buf , ws_int offset , ws_int length)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetLength(ws_int length)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetPort(ws_int iport)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetSocketAddress(wsiSocketAddress * address)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



