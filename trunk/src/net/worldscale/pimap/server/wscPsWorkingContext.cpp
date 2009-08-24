#include "wscPsWorkingContext.h"
#include "wscPsExchangeBuffer.h"
#include <wcpp/net/wsiDatagramSocket.h>


wscPsWorkingContext::wscPsWorkingContext(void) : m_StopFlag( WS_FALSE ) , m_nListeningPort(8888)
{
    ws_ptr<wsiPsExchangeBuffer> exbuf;
    NewObj<wscPsExchangeBuffer>( & exbuf );
    WS_ASSERT( !(!exbuf) );
    m_ExchangeBuffer.Set( exbuf );
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
    m_ExchangeBuffer.Get( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscPsWorkingContext::SetDatagramSocket(wsiDatagramSocket *aDatagramSocket)
{
    m_DatagramSocket.Set( aDatagramSocket );
    return WS_RLT_SUCCESS;
}


ws_result wscPsWorkingContext::GetDatagramSocket(wsiDatagramSocket **ret)
{
    m_DatagramSocket.Get( ret );
    return WS_RLT_SUCCESS;
}

