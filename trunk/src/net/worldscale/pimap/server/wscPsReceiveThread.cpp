#include "wscPsReceiveThread.h"
#include <wcpp/net/wscDatagramSocket.h>
#include "wsiPsExchangeBuffer.h"
#include <wcpp/net/wsiDatagramPacket.h>


wscPsReceiveThread::wscPsReceiveThread(wsiPsWorkingContext * pWorkingContext)
{
    m_WorkingContext.Set( pWorkingContext );
}


wscPsReceiveThread::~wscPsReceiveThread(void)
{
}


ws_result wscPsReceiveThread::Run(void)
{
    // get working context
    ws_ptr<wsiPsWorkingContext> wkContext;
    m_WorkingContext.Get( &wkContext );
    if (!wkContext) return WS_RLT_FAILED;

    // get exchange buffer
    ws_ptr<wsiPsExchangeBuffer> exbuf;
    wkContext->GetExchangeBuffer( & exbuf );
    if (!exbuf) return WS_RLT_FAILED;

    // get udp listener
    ws_ptr<wsiDatagramSocket> dgSock;
    ws_result rlt = wkContext->GetDatagramSocket( &dgSock );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    ws_ptr<wsiDatagramPacket> packet;
    while ( ! wkContext->GetStopFlag() ) {
        packet.Release();
        rlt = exbuf->AllocatePacket( &packet );
        if (rlt==WS_RLT_SUCCESS) {
            rlt = dgSock->Receive( packet );
            if (rlt==WS_RLT_SUCCESS) {
                exbuf->PushPacket( packet );
            }
            else {
                exbuf->RecyclePacket( packet );
            }
        }
        else {
            Sleep( 10 );
        }
    }

    return WS_RLT_SUCCESS;
}

