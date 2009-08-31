#include "wscPcWorkingContext.h"
#include <wcpp/net/wsiDatagramSocket.h>
#include "wsiPcExchangeBuffer.h"
#include "wsiPcTransmitter.h"
#include "wsiPcEventDispatcher.h"
#include "wsiPcUser.h"


wscPcWorkingContext::wscPcWorkingContext(void) : m_StopFlag( WS_FALSE )
{
}


wscPcWorkingContext::~wscPcWorkingContext(void)
{
}


ws_result wscPcWorkingContext::SetStopFlag(void)
{
    m_StopFlag = WS_TRUE;
    m_DatagramSocket.Set( WS_NULL );
    m_ExchangeBuffer.Set( WS_NULL );
    m_Transmitter.Set( WS_NULL );
    m_EventDispatcher.Set( WS_NULL );
    return WS_RLT_SUCCESS;
}


ws_boolean wscPcWorkingContext::GetStopFlag(void)
{
    return m_StopFlag;
}


ws_result wscPcWorkingContext::GetDatagramSocket(wsiDatagramSocket **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_DatagramSocket.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPcWorkingContext::SetDatagramSocket(wsiDatagramSocket *aDatagramSocket)
{
    m_DatagramSocket.Set( aDatagramSocket );
    return WS_RLT_SUCCESS;
}


ws_result wscPcWorkingContext::GetExchangeBuffer(wsiPcExchangeBuffer ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_ExchangeBuffer.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPcWorkingContext::SetExchangeBuffer(wsiPcExchangeBuffer * exbuf)
{
    m_ExchangeBuffer.Set( exbuf );
    return WS_RLT_SUCCESS;
}


ws_result wscPcWorkingContext::GetTransmitter(wsiPcTransmitter **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_Transmitter.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPcWorkingContext::GetEventDispatcher(wsiPcEventDispatcher **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_EventDispatcher.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}


ws_result wscPcWorkingContext::SetTransmitter(wsiPcTransmitter *p)
{
    m_Transmitter.Set( p );
    return WS_RLT_SUCCESS;
}


ws_result wscPcWorkingContext::SetEventDispatcher(wsiPcEventDispatcher *p)
{
    m_EventDispatcher.Set( p );
    return WS_RLT_SUCCESS;
}


ws_result wscPcWorkingContext::SetUser(wsiPcUser *addr)
{
    m_User.Set( addr );
    return WS_RLT_SUCCESS;
}


ws_result wscPcWorkingContext::GetUser(wsiPcUser **ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    m_User.Get( ret );
    if (*ret) return WS_RLT_SUCCESS;
    return WS_RLT_FAILED;
}

