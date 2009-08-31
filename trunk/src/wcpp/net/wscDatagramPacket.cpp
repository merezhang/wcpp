#include "wscDatagramPacket.h"
#include <wcpp/lang/wscThrowable.h>
#include "wsiInetSocketAddress.h"
#include "wsiInetAddress.h"


wscDatagramPacket::wscDatagramPacket(wsiByteArray * buf , ws_int length) : m_length(length) , m_port(0)
{
    m_buffer.Set( buf );
}


wscDatagramPacket::wscDatagramPacket(wsiByteArray * buf , ws_int length , wsiSocketAddress * address) : m_length(length) , m_port(0)
{
    m_buffer.Set( buf );
    if (address) {
        ws_ptr<wsiInetSocketAddress> isAddr;
        address->QueryInterface( isAddr.GetIID() , (void**)(&isAddr) );
        if (!(!isAddr)) {
            m_port = isAddr->GetPort();
            ws_ptr<wsiInetAddress> iAddr;
            isAddr->GetAddress( &iAddr );
            m_address.Set( iAddr );
        }
    }
}


wscDatagramPacket::~wscDatagramPacket(void)
{
}




ws_result wscDatagramPacket::GetAddress(wsiInetAddress ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_address.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
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
    return m_length;
}


ws_int wscDatagramPacket::GetOffset(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscDatagramPacket::GetPort(void)
{
    return m_port;
}


ws_result wscDatagramPacket::GetSocketAddress(wsiSocketAddress ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetAddress(wsiInetAddress * iaddr)
{
    m_address.Set( iaddr );
    return WS_RLT_SUCCESS;
}


ws_result wscDatagramPacket::SetData(wsiByteArray * buf)
{
    m_buffer.Set( buf );
    return WS_RLT_SUCCESS;
}


ws_result wscDatagramPacket::SetData(wsiByteArray * buf , ws_int offset , ws_int length)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramPacket::SetLength(ws_int length)
{
    m_length = length;
    return WS_RLT_SUCCESS;
}


ws_result wscDatagramPacket::SetPort(ws_int iport)
{
    m_port = iport;
    return WS_RLT_SUCCESS;
}


ws_result wscDatagramPacket::SetSocketAddress(wsiSocketAddress * address)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



