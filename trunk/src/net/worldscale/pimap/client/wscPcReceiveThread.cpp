#include "wscPcReceiveThread.h"
#include "wsiPcWorkingContext.h"
#include <wcpp/net/wscDatagramPacket.h>
#include <wcpp/net/wsiDatagramSocket.h>
#include <wcpp/lang/wscArray.h>
#include "wscPimapClientConfig.h"
#include "wsiPcEventDispatcher.h"


wscPcReceiveThread::wscPcReceiveThread(wsiPcWorkingContext * wc)
{
    m_WorkingContext.Set( wc );
}


wscPcReceiveThread::~wscPcReceiveThread(void)
{
}


ws_result wscPcReceiveThread::Run(void)
{
    ws_ptr<wsiPcWorkingContext> wkContext;
    m_WorkingContext.Get( & wkContext );
    if (!wkContext) return WS_RLT_ILLEGAL_STATE;

    ws_ptr<wsiDatagramSocket> dgSock;
    ws_result rlt = wkContext->GetDatagramSocket( &dgSock );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiByteArray> buf;
    const ws_int buflen = wscPimapClientConfig::MAX_PACKET_SIZE;
    rlt = NewObj<wscByteArray>( &buf , buflen );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiDatagramPacket> dgPack;
    rlt = NewObj<wscDatagramPacket>( &dgPack , buf , buflen );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    while ( ! wkContext->GetStopFlag() ) {
        rlt = dgSock->Receive( dgPack );
        if (rlt==WS_RLT_SUCCESS) {
            // dgPack ... ;
        }
    }

    return WS_RLT_SUCCESS;
}

