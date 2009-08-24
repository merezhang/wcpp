// wscDatagramSocketImpl_win32.cpp

#include "wscDatagramSocketImpl_win32.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/net/wscInetAddress.h>
#include <wcpp/net/wsiDatagramPacket.h>
#if (WS_PLATFORM == WS_PLATFORM_WIN32)


const ws_char * const wscDatagramSocketImpl_win32::s_class_name = "wcpp.net.impl.wscDatagramSocketImpl_win32";


wscDatagramSocketImpl_win32::wscDatagramSocketImpl_win32(void) : m_socket(INVALID_SOCKET)
{
}


wscDatagramSocketImpl_win32::~wscDatagramSocketImpl_win32(void)
{
}




ws_result wscDatagramSocketImpl_win32::GetOption(wsiObject ** ret , ws_int optID)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscDatagramSocketImpl_win32::SetOption(ws_int optID , wsiObject * value)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}




ws_result  wscDatagramSocketImpl_win32::Bind(ws_int lport , wsiInetAddress * laddr)
{
    if (laddr==WS_NULL) return WS_RLT_NULL_POINTER;

    ws_ptr<wsiByteArray> ba;
    ws_result rlt = laddr->GetAddress(&ba);
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    int           namelen    = ba->Length();
    sockaddr_in * name       =(sockaddr_in *) ba->Data();
    if (name) name->sin_port =(u_short) lport;

    int rlt2 = bind( m_socket, (sockaddr*) name, namelen );
    return ((rlt2==0) ? WS_RLT_SUCCESS : WS_RLT_FAILED );
}


ws_result  wscDatagramSocketImpl_win32::Close(void)
{
    int rlt = closesocket( m_socket );
    m_socket = INVALID_SOCKET;
    return ( (rlt==0) ? WS_RLT_SUCCESS : WS_RLT_FAILED );
}


ws_result  wscDatagramSocketImpl_win32::Connect(wsiInetAddress * address , ws_int port)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::Create(void)
{
    if (m_socket != INVALID_SOCKET) {
        WS_THROW( wseIllegalStateException , "" );
    }
    m_socket = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
    if (m_socket == INVALID_SOCKET) return WS_RLT_FAILED;
    return WS_RLT_SUCCESS;
}


ws_result  wscDatagramSocketImpl_win32::Disconnect(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::GetFileDescriptor(wsiFileDescriptor ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int     wscDatagramSocketImpl_win32::GetLocalPort(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int     wscDatagramSocketImpl_win32::GetTimeToLive(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::Join(wsiInetAddress * inetaddr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::JoinGroup(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::Leave(wsiInetAddress * inetaddr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::LeaveGroup(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int     wscDatagramSocketImpl_win32::Peek(wsiInetAddress * i)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int     wscDatagramSocketImpl_win32::PeekData(wsiDatagramPacket * p)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::Receive(wsiDatagramPacket * p)
{
    if (p==WS_NULL) return WS_RLT_NULL_POINTER;
    if (m_socket==INVALID_SOCKET) return WS_RLT_ILLEGAL_STATE;

    ws_ptr<wsiByteArray> theData;
    ws_result rlt = p->GetData( &theData );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    char * buf =(char*) theData->Data();
    int len = theData->Length();

    sockaddr_in addr;
    int addrlen = sizeof(addr);

    int rlt2 = recvfrom( m_socket , buf , len , 0 , (SOCKADDR *)&addr, &addrlen );

    if (rlt2==0) return WS_RLT_FAILED;
    if (rlt2==SOCKET_ERROR) return WS_RLT_FAILED;
    if (rlt2<0) {
        WS_THROW( wseIllegalStateException , "" );
    }
    p->SetLength( rlt2 );

    ws_ptr<wsiInetAddress> inetAddr;
    rlt = wscInetAddress::GetByAddress( &inetAddr , (ws_byte*)(&addr) , sizeof(addr) );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    p->SetAddress( inetAddr );
    p->SetPort( addr.sin_port );

    return WS_RLT_SUCCESS;
}


ws_result  wscDatagramSocketImpl_win32::Send(wsiDatagramPacket * p)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result  wscDatagramSocketImpl_win32::SetTimeToLive(ws_int ttl)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
