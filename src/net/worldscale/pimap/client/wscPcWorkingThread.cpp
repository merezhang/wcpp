#include "wscPcWorkingThread.h"
#include "wsiPcWorkingContext.h"
#include <wcpp/net/wscDatagramSocket.h>
#include <wcpp/net/wscInetAddress.h>
#include <wcpp/net/wscInetSocketAddress.h>
#include "wscPcReceiveThread.h"
#include "wscPcTransmitter.h"
#include "wscPcEventDispatcher.h"
#include "wscPcExchangeBuffer.h"


wscPcWorkingThread::wscPcWorkingThread(wsiPcWorkingContext * wc)
{
    m_WorkingContext.Set( wc );
}


wscPcWorkingThread::~wscPcWorkingThread(void)
{
}


ws_result wscPcWorkingThread::Run(void)
{
    // get working context
    ws_ptr< wsiPcWorkingContext > wkContext;
    m_WorkingContext.Get( &wkContext );
    if (!wkContext) return WS_RLT_ILLEGAL_STATE;

    ws_result rlt(0);

    // create socket
    // get address of localhost
    ws_ptr<wsiInetSocketAddress> sockAddr;
    ws_ptr<wsiInetAddress> localhost;
    rlt = wscInetAddress::GetLocalHost( &localhost );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    // create datagram socket
    ws_ptr<wsiDatagramSocket> sock;
    rlt = NewObj<wscDatagramSocket>(&sock);
    if (rlt != WS_RLT_SUCCESS) return rlt;
    // bind to a port of localhost
    for (ws_int i=1000 ; i>0 ; i--) {
        sockAddr.Release();
        rlt = NewObj< wscInetSocketAddress >( &sockAddr , localhost , 20000+i );
        if (rlt == WS_RLT_SUCCESS) {
            rlt = sock->Bind( sockAddr );
            if (rlt == WS_RLT_SUCCESS) i = 0;
        }
    }
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    // create exchange buffer
    ws_ptr<wsiPcExchangeBuffer> exbuf;
    rlt = NewObj<wscPcExchangeBuffer>( &exbuf );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    // create transmitter
    ws_ptr<wsiPcTransmitter> trans;
    rlt = NewObj<wscPcTransmitter>(&trans,wkContext);
    if (rlt != WS_RLT_SUCCESS) return rlt;

    // create event dispatcher
    ws_ptr<wsiPcEventDispatcher> evtDisp;
    rlt = NewObj<wscPcEventDispatcher>( & evtDisp , wkContext );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    // create receive thread
    ws_ptr<wsiThread> rcvThd;
    rlt = NewObj<wscPcReceiveThread>( &rcvThd , wkContext );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    wkContext->SetDatagramSocket( sock );
    wkContext->SetEventDispatcher( evtDisp );
    wkContext->SetExchangeBuffer( exbuf );
    wkContext->SetTransmitter( trans );

    // start receive thread
    rcvThd->Start();

    // join sub thread(s)
    return rcvThd->Join();
}

