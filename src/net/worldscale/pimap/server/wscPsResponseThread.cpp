#include "wscPsResponseThread.h"
#include <wcpp/net/wsiDatagramPacket.h>
#include "wsiPsExchangeBuffer.h"
#include "TransactionContext.h"
#include <net/worldscale/pimap/wscPimapCoder.h>
#include <net/worldscale/pimap/wscPimapDecoder.h>
#include <net/worldscale/pimap/wscPimapPacket.h>
#include "wscMethodExecutor.h"
#include <wcpp/net/wscDatagramPacket.h>
#include <wcpp/net/wsiDatagramSocket.h>
#include "wscPimapServerConfig.h"
#include <wcpp/lang/wscArray.h>


/*
ws_result wscPsResponseThread::OnReceive(wsiPsWorkingContext * wkContext, wsiDatagramPacket * packet)
{
    if ((wkContext==WS_NULL) || (packet==WS_NULL)) return WS_RLT_NULL_POINTER;
}
*/


wscPsResponseThread::wscPsResponseThread(wsiPsWorkingContext * pWorkingContext)
{
    m_WorkingContext.Set( pWorkingContext );
}


wscPsResponseThread::~wscPsResponseThread(void)
{
}


ws_result wscPsResponseThread::Run(void)
{
    // get working context
    ws_ptr<wsiPsWorkingContext> wkContext;
    m_WorkingContext.Get( &wkContext );

    // get exchange buffer
    ws_ptr<wsiPsExchangeBuffer> exbuf;
    ws_result rlt = wkContext->GetExchangeBuffer( &exbuf );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // get datagram socket
    ws_ptr<wsiDatagramSocket> dgSock;
    rlt = wkContext->GetDatagramSocket( &dgSock );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create request pimap
    ws_ptr<wsiPimapPacket> pimapReq;
    rlt = NewObj<wscPimapPacket>(&pimapReq);
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create response pimap
    ws_ptr<wsiPimapPacket> pimapResp;
    rlt = NewObj<wscPimapPacket>(&pimapResp);
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create response datagram
    const ws_int buflen = wscPimapServerConfig::MAX_PACKET_SIZE;
    ws_ptr<wsiByteArray> buf;
    rlt = NewObj<wscByteArray>(&buf,buflen);
    if (rlt!=WS_RLT_SUCCESS) return rlt;
    ws_ptr<wsiDatagramPacket> dgResp;
    rlt = NewObj<wscDatagramPacket>( &dgResp, buf, buflen );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create executor
    ws_ptr<wsiMethodExecutor> executor;
    rlt = NewObj<wscMethodExecutor>( & executor );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create coder
    ws_ptr<wsiPimapCoder> coder;
    rlt = NewObj<wscPimapCoder>( & coder );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create decoder
    ws_ptr<wsiPimapDecoder> decoder;
    rlt = NewObj<wscPimapDecoder>( & decoder );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    while ( ! wkContext->GetStopFlag() ) {
        ws_ptr<wsiDatagramPacket> packet;
        packet.Release();
        rlt = exbuf->PopPacket( &packet );
        if (rlt!=WS_RLT_SUCCESS) {
            Sleep( 100 );
            continue;
        }
        TransactionContext tc;
        tc.m_coder      = coder;
        tc.m_decoder    = decoder;
        tc.m_dgSocket   = dgSock;
        tc.m_dgRequest  = packet;
        tc.m_dgResponse = dgResp;
        tc.m_pmRequest  = pimapReq;
        tc.m_pmResponse = pimapResp;
        executor->Execute( tc );
        exbuf->RecyclePacket( packet );
    }

    return WS_RLT_SUCCESS;
}

