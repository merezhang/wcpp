#include "wscPcExchangeBuffer.h"
#include <wcpp/lang/wscThrowable.h>
#include <net/worldscale/pimap/wsiPimapPacket.h>


WS_IMPL_ClassName_OF( wscPcExchangeBuffer )


wscPcExchangeBuffer::wscPcExchangeBuffer(void)
{
}


wscPcExchangeBuffer::~wscPcExchangeBuffer(void)
{
}


ws_result wscPcExchangeBuffer::OnReceive(wsiPimapPacket ** ret)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscPcExchangeBuffer::OnSend(wsiPimapPacket * packet)
{
    m_waitResponse.Set( packet );
    return WS_RLT_SUCCESS;
}

