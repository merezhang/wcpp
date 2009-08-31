#include "wscDatagramSocket.h"
#include <wcpp/lang/wscThrowable.h>
#include "wscNetworkLibrary.h"
#include <wcpp/lang/helper/ws_runtime.h>
#include "wsiDatagramSocketImplFactory.h"
#include "wscInetAddress.h"
#include "wsiInetSocketAddress.h"


wscDatagramSocket::wscDatagramSocket(void)
{
    InternalInit();
}


wscDatagramSocket::wscDatagramSocket(ws_int port)
{
    InternalInit();

    ws_ptr<wsiInetAddress> inetAddr;
    ws_result rlt = wscInetAddress::GetLocalHost( &inetAddr );
    if (rlt != WS_RLT_SUCCESS) return;

    ws_ptr<wsiDatagramSocketImpl> impl;
    m_impl.Get( &impl );
    if (!impl) return;
    impl->Bind( port , inetAddr );
}


wscDatagramSocket::~wscDatagramSocket(void)
{
}


void wscDatagramSocket::InternalInit(void)
{
    ws_ptr<wsiNetworkLibrary> netlib;
    ws_result rlt = wscNetworkLibrary::GetNetworkLibrary( &netlib );
    if (rlt != WS_RLT_SUCCESS) return;

    ws_ptr<wsiDatagramSocketImplFactory> implFac;
    rlt = netlib->GetDatagramSocketImplFactory( & implFac );
    if (rlt != WS_RLT_SUCCESS) return;

    ws_ptr<wsiDatagramSocketImpl> impl;
    rlt = implFac->CreateDatagramSocketImpl( &impl );
    if (rlt != WS_RLT_SUCCESS) return;

    rlt = impl->Create();
    if (rlt != WS_RLT_SUCCESS) return;

    m_impl.Set( impl );
}


ws_result wscDatagramSocket::Bind(wsiSocketAddress * addr)
{
    ws_int port = 0;
    ws_ptr<wsiInetAddress> address;
    if (addr) {
        ws_ptr<wsiInetSocketAddress> aISA;
        ws_result rlt = addr->QueryInterface( aISA.GetIID() , (void**)(&aISA) );
        if (rlt!=WS_RLT_SUCCESS) return WS_RLT_ILLEGAL_ARGUMENT;
        port = aISA->GetPort();
        aISA->GetAddress( &address );
    }
    else {
        return WS_RLT_NULL_POINTER;
    }

    ws_ptr<wsiDatagramSocketImpl> impl;
    m_impl.Get( &impl );
    if (!impl) return WS_RLT_ILLEGAL_STATE;

    return impl->Bind( port , address );
}


ws_result wscDatagramSocket::Close(void)
{
    ws_ptr<wsiDatagramSocketImpl> impl;
    m_impl.Get( &impl );
    if (!impl) return WS_RLT_ILLEGAL_STATE;
    return impl->Close();
}


ws_result   wscDatagramSocket::Connect                (wsiInetAddress * address , ws_int port)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::Connect                (wsiSocketAddress * addr)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::Disconnect             (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean  wscDatagramSocket::GetBroadcast           (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::GetChannel             (wsiDatagramChannel ** ret)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::GetInetAddress         (wsiInetAddress ** ret)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::GetLocalAddress        (wsiInetAddress ** ret)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetLocalPort           (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::GetLocalSocketAddress  (wsiSocketAddress ** ret)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetPort                (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetReceiveBufferSize   (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::GetRemoteSocketAddress (wsiSocketAddress ** ret)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean  wscDatagramSocket::GetReuseAddress        (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetSendBufferSize      (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetSoTimeout           (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_int      wscDatagramSocket::GetTrafficClass        (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean  wscDatagramSocket::IsBound                (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean  wscDatagramSocket::IsClosed               (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_boolean  wscDatagramSocket::IsConnected            (void)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::Receive                (wsiDatagramPacket * p)
{
    ws_ptr<wsiDatagramSocketImpl> impl;
    m_impl.Get( &impl );
    if (!impl) return WS_RLT_ILLEGAL_STATE;
    return impl->Receive(p);
}


ws_result   wscDatagramSocket::Send                   (wsiDatagramPacket * p)
{
    ws_ptr<wsiDatagramSocketImpl> impl;
    m_impl.Get( &impl );
    if (!impl) return WS_RLT_ILLEGAL_STATE;
    return impl->Send(p);
}


ws_result   wscDatagramSocket::SetBroadcast           (ws_boolean on)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::SetReceiveBufferSize   (ws_int size)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::SetReuseAddress        (ws_boolean on)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::SetSendBufferSize      (ws_int size)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::SetSoTimeout           (ws_int timeout)
{ WS_THROW( wseUnsupportedOperationException , "" ); }


ws_result   wscDatagramSocket::SetTrafficClass        (ws_int tc)
{ WS_THROW( wseUnsupportedOperationException , "" ); }



