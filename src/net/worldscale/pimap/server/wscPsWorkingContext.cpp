#include "wscPsWorkingContext.h"
#include "wscPsExchangeBuffer.h"
#include <wcpp/net/wsiDatagramSocket.h>
#include "wscPsUserTable.h"


wscPsWorkingContext::wscPsWorkingContext(ws_int nPort) : m_StopFlag( WS_FALSE ) , m_nListeningPort(nPort)
{
    ws_ptr<wsiPsExchangeBuffer> exbuf;
    NewObj<wscPsExchangeBuffer>( & exbuf );
    WS_ASSERT( !(!exbuf) );
    m_ExchangeBuffer.Set( exbuf );

    ws_ptr<wsiPsUserTable> usertab;
    NewObj<wscPsUserTable>(&usertab);
    WS_ASSERT( !(!usertab) );
    m_UserTable.Set( usertab );
}


wscPsWorkingContext::~wscPsWorkingContext(void)
{
}


ws_boolean wscPsWorkingContext::GetStopFlag(void)
{
    return m_StopFlag;
}


ws_result wscPsWorkingContext::SetStopFlag(void)
{
    m_StopFlag = WS_TRUE;
    return WS_RLT_SUCCESS;
}


ws_int wscPsWorkingContext::GetListeningPort(void)
{
    return m_nListeningPort;
}


ws_result wscPsWorkingContext::GetExchangeBuffer(wsiPsExchangeBuffer ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_ExchangeBuffer.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPsWorkingContext::SetDatagramSocket(wsiDatagramSocket *aDatagramSocket)
{
    m_DatagramSocket.Set( aDatagramSocket );
    return WS_RLT_SUCCESS;
}


ws_result wscPsWorkingContext::GetDatagramSocket(wsiDatagramSocket **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_DatagramSocket.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPsWorkingContext::GetUserTable(wsiPsUserTable ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_UserTable.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}

