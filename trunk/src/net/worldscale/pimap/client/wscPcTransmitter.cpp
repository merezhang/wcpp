#include "wscPcTransmitter.h"
#include "wsiPcWorkingContext.h"
#include <net/worldscale/pimap/wscPimapCoder.h>
#include <wcpp/net/wscDatagramPacket.h>
#include <wcpp/net/wscDatagramSocket.h>
#include "wsiPcExchangeBuffer.h"
#include "wscPimapClientConfig.h"
#include <wcpp/lang/wscArray.h>
#include <wcpp/net/wsiInetSocketAddress.h>
#include <wcpp/net/wsiInetAddress.h>
#include "wsiPcUser.h"


WS_IMPL_ClassName_OF( wscPcTransmitter )


wscPcTransmitter::wscPcTransmitter(wsiPcWorkingContext * wc)
{
    m_wkContext.Set( wc );
}


wscPcTransmitter::~wscPcTransmitter(void)
{
}


ws_result wscPcTransmitter::SendRequest(wsiPimapPacket *packet, wsiInetSocketAddress * sockAddr)
{
    if (packet==WS_NULL) return WS_RLT_NULL_POINTER;

    // get working context
    ws_ptr<wsiPcWorkingContext> wc;
    m_wkContext.Get(&wc);
    if (!wc) return WS_RLT_ILLEGAL_STATE;

    ws_result rlt(0);

    // get socket
    ws_ptr<wsiDatagramSocket> sock;
    rlt = wc->GetDatagramSocket( &sock );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // get exchange buffer
    ws_ptr<wsiPcExchangeBuffer> exbuf;
    rlt = wc->GetExchangeBuffer( &exbuf );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create pimap coder
    ws_ptr<wsiPimapCoder> coder;
    rlt = NewObj<wscPimapCoder>(&coder);
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create datagram
    // create buf
    const ws_int buflen = wscPimapClientConfig::MAX_PACKET_SIZE;
    ws_ptr<wsiByteArray> bArray;
    rlt = NewObj<wscByteArray>( &bArray , buflen );
    if (rlt!=WS_RLT_SUCCESS) return rlt;
    // create datagram
    ws_ptr<wsiDatagramPacket> datagram;
    rlt = NewObj<wscDatagramPacket>( &datagram, bArray , buflen );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // code
    rlt = coder->Code( packet , datagram );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // reg to exbuf
    rlt = exbuf->OnSend( packet );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // set addr & port
    ws_ptr<wsiInetAddress> addr;
    ws_int port = 0;
    if (sockAddr) {
        sockAddr->GetAddress( &addr );
        port = sockAddr->GetPort();
    }
    else {
        ws_ptr<wsiPcUser> user;
        rlt = wc->GetUser( &user );
        if (rlt==WS_RLT_SUCCESS) {
            ws_ptr<wsiInetSocketAddress> sockAddr2;
            rlt = user->GetServerAddress( & sockAddr2 );
            if (rlt==WS_RLT_SUCCESS) {
                sockAddr2->GetAddress( &addr );
                port = sockAddr2->GetPort();
            }
        }
    }
    datagram->SetAddress( addr );
    datagram->SetPort( port );

    return sock->Send( datagram );
}

