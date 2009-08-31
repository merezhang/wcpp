#include "wscPimapServer.h"
#include <wcpp/lang/wscThrowable.h>
#include "wscPsWorkingThread.h"
#include "wscPsWorkingContext.h"
#include <wcpp/net/wsiDatagramSocket.h>


wscPimapServer::wscPimapServer(void)
{
}


wscPimapServer::~wscPimapServer(void)
{
}


ws_result wscPimapServer::Start(ws_int nPort)
{
    ws_ptr<wsiThread> servThd;
    m_ServerThread.Get( &servThd );
    if (!(!servThd)) {
        return WS_RLT_ILLEGAL_STATE;
    }

    ws_ptr<wsiPsWorkingContext> wc;
    ws_result rlt = NewObj<wscPsWorkingContext>( &wc , nPort );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    rlt = NewObj<wscPsWorkingThread>( &servThd , wc );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    rlt = servThd->Start();
    if (rlt != WS_RLT_SUCCESS) return rlt;

    m_WorkingContext.Set( wc );
    m_ServerThread.Set( servThd );
    return WS_RLT_SUCCESS;
}


ws_result wscPimapServer::Stop(void)
{
    ws_ptr<wsiThread> servThd;
    m_ServerThread.Get( &servThd );
    m_ServerThread.Set( WS_NULL );
    if (!servThd) {
        return WS_RLT_ILLEGAL_STATE;
    }

    // do sth to cancel the working thread here ...
    ws_ptr<wsiPsWorkingContext> wc;
    m_WorkingContext.Get( &wc );
    m_WorkingContext.Set( WS_NULL );
    if (!(!wc)) {
        wc->SetStopFlag();

        ws_ptr<wsiDatagramSocket> dgSock;
        wc->GetDatagramSocket(&dgSock);
        if (!(!dgSock)) dgSock->Close();
    }

    return servThd->Join();
}

