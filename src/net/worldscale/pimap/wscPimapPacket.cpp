#include "wscPimapPacket.h"
#include "wscPimapConfig.h"


WS_IMPL_ClassName_OF( wscPimapPacket )


wscPimapPacket::wscPimapPacket(void)
{
    wspr::ws_memset( &m_head, 0, sizeof(m_head) );
    for (ws_int i=(MAX_PARAM_NUMBER-1) ; i>=0 ; i--) {
        m_param[i].type  = TYPE_NULL;
        m_param[i].value = 0;
    }
    m_head.version = wscPimapConfig::PIMAP_VERSION;
}


wscPimapPacket::~wscPimapPacket(void)
{
}


ws_uint8  wscPimapPacket::GetVersion  (void)
{
    return m_head.version;
}


ws_uint8  wscPimapPacket::GetFlag     (void)
{
    return m_head.flag;
}


ws_uint8  wscPimapPacket::GetXOR      (void)
{
    return m_head.xor;
}


ws_uint8  wscPimapPacket::GetTransID  (void)
{
    return m_head.transId;
}


ws_uint32 wscPimapPacket::GetUserID   (void)
{
    return m_head.userId;
}


ws_uint32 wscPimapPacket::GetKey      (void)
{
    return m_head.key;
}


ws_uint16 wscPimapPacket::GetFunction (void)
{
    return m_head.func;
}


ws_uint16 wscPimapPacket::GetAddLen   (void)
{
    return m_head.addlen;
}


void  wscPimapPacket::SetVersion  (ws_uint8  value)
{
    m_head.version = value;
}


void  wscPimapPacket::SetFlag     (ws_uint8  value)
{
    m_head.flag = value;
}


void  wscPimapPacket::SetXOR      (ws_uint8  value)
{
    m_head.xor = value;
}


void  wscPimapPacket::SetTransID  (ws_uint8  value)
{
    m_head.transId = value;
}


void  wscPimapPacket::SetUserID   (ws_uint32 value)
{
    m_head.userId = value;
}


void  wscPimapPacket::SetKey      (ws_uint32 value)
{
    m_head.key = value;
}


void  wscPimapPacket::SetFunction (ws_uint16 value)
{
    m_head.func = value;
}


void  wscPimapPacket::SetAddLen   (ws_uint16 value)
{
    m_head.addlen = value;
}


void wscPimapPacket::PutParam(ws_uint8 id, ws_uint8 type, ws_uint32 value)
{
    if (id < MAX_PARAM_NUMBER) {
        m_param[id].type  = type;
        m_param[id].value = value;
        m_param[id].string.Set( WS_NULL );
    }
}


void wscPimapPacket::PutParam(ws_uint8 id, ws_uint8 type, wsiString *str)
{
    if (id < MAX_PARAM_NUMBER) {
        m_param[id].type  = type;
        m_param[id].value = 0;
        m_param[id].string.Set( str );
    }
}


ws_result wscPimapPacket::GetParam(ws_uint8 id, ws_uint8 & type, ws_uint32 & value, wsiString ** rStr)
{
    if (id < MAX_PARAM_NUMBER) {
        type  = m_param[id].type;
        value = m_param[id].value;
        m_param[id].string.Get( rStr );
        return WS_RLT_SUCCESS ;
    }
    else {
        return WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS ;
    }
}

