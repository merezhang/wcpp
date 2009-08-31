#include "wscPimapClient.h"
#include <wcpp/lang/wscThrowable.h>
#include "wscPcWorkingContext.h"
#include <wcpp/lang/wscThread.h>
#include "wscPcWorkingThread.h"
#include <wcpp/net/wscInetSocketAddress.h>
#include "wscPimapClientConfig.h"
#include <wcpp/net/wscDatagramPacket.h>
#include <wcpp/net/wsiDatagramSocket.h>
#include <wcpp/lang/wscArray.h>
#include <wcpp/net/wscInetAddress.h>
#include <wcpp/net/wscDatagramSocket.h>
#include "wscPcUpPacket.h"
#include "wscPcExchangeBuffer.h"
#include "wsiPcTransmitter.h"
#include "wscPcUser.h"


wscPimapClient::wscPimapClient(void)
{
    ws_result rlt(0);

    // create working context
    ws_ptr<wsiPcWorkingContext> wkCon;
    rlt = NewObj<wscPcWorkingContext>( &wkCon );
    if (rlt != WS_RLT_SUCCESS) return;

    // create working thread
    ws_ptr<wsiThread> wkThd;
    rlt = NewObj<wscPcWorkingThread>( &wkThd , wkCon );
    if (rlt != WS_RLT_SUCCESS) return;

    m_WorkingContext.Set( wkCon );
    m_WorkingThread.Set( wkThd );

    // start working thread
    wkThd->Start();
}


wscPimapClient::~wscPimapClient(void)
{
    InternalClose();
}


ws_result wscPimapClient::InternalPost(wsiPimapMethodsUp * method)
{
    if (method == WS_NULL) return WS_RLT_NULL_POINTER;
    ws_ptr<wsiPimapPacket> packet;
    ws_result rlt = method->QueryInterface( packet.GetIID() , (void**)(&packet) );
    if ( rlt != WS_RLT_SUCCESS ) return rlt;

    // get working context
    ws_ptr<wsiPcWorkingContext> wkContext;
    m_WorkingContext.Get( &wkContext );
    if (!wkContext) return WS_RLT_ILLEGAL_STATE;

    // get transmitter
    ws_ptr<wsiPcTransmitter> trans;
    rlt = wkContext->GetTransmitter( &trans );
    if (rlt!=WS_RLT_SUCCESS) return WS_RLT_ILLEGAL_STATE;

    return trans->SendRequest( packet , WS_NULL );
}


ws_result wscPimapClient::Login(wsiString *aUserName, wsiString *aPassword, wsiString *aServerAddr, ws_int aPort)
{
    ws_result rlt(0);

    // get context
    ws_ptr<wsiPcWorkingContext> wkContext;
    m_WorkingContext.Get( & wkContext );
    if (!wkContext) return WS_RLT_ILLEGAL_STATE;

    // create master address
    ws_ptr<wsiInetSocketAddress> addr;
    rlt = NewObj<wscInetSocketAddress>( &addr , aServerAddr , aPort );
    if (rlt!=WS_RLT_SUCCESS) return rlt;
   
    // create user
    ws_ptr<wsiPcUser> user;
    rlt = NewObj<wscPcUser>(&user);
    if (rlt!=WS_RLT_SUCCESS) return rlt;
    user->SetServerAddress( addr );
    wkContext->SetUser( user );

    // create methods
    ws_ptr<wsiPimapMethodsUp> methods;
    rlt = NewObj<wscPcUpPacket>(&methods);
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    rlt = methods->Login( aUserName , aPassword );
    if (rlt!=WS_RLT_SUCCESS) return rlt;

    return InternalPost( methods );
}


ws_result wscPimapClient::Logout(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPimapClient::InternalClose(void)
{
    ws_ptr<wsiPcWorkingContext> wkCon;
    m_WorkingContext.Get( & wkCon );
    m_WorkingContext.Set( WS_NULL );
    if (!(!wkCon)) {
        ws_ptr<wsiDatagramSocket> dgSock;
        wkCon->GetDatagramSocket( &dgSock );
        wkCon->SetStopFlag();
        if (!(!dgSock)) dgSock->Close();
    }

    ws_ptr<wsiThread> wkThd;
    m_WorkingThread.Get( & wkThd );
    m_WorkingThread.Set( WS_NULL );
    if (!(!wkThd)) wkThd->Join();

    return WS_RLT_SUCCESS;
}


ws_result wscPimapClient::Close(void)
{
    return InternalClose();
}

