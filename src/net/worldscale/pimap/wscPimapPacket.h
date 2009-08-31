#pragma once

#include "wsiPimapPacket.h"
#include <wcpp/lang/wscObject.h>


#define WS_ClassName_OF_wscPimapPacket      "net.worldscale.pimap.wscPimapPacket"


class wscPimapPacket : public wscObject , public wsiPimapPacket
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscPimapPacket )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiPimapPacket )
    WS_IMPL_QUERY_INTERFACE_END()
public:
    static const ws_char * const s_class_name;
private:

    struct t_pimap_head
    {
        ws_uint8  version;
        ws_uint8  flag;
        ws_uint8  xor;
        ws_uint8  transId;

        ws_uint32 userId;
        ws_uint32 key;

        ws_uint16 func;
        ws_uint16 addlen;
    };
    t_pimap_head  m_head;

    static const int MAX_PARAM_NUMBER = 32;
    struct t_pimap_param
    {
        ws_uint8  type;
        ws_uint32 value;
        ws_safe_ptr<wsiString> string;
    };
    t_pimap_param m_param[ MAX_PARAM_NUMBER ];

public:
    wscPimapPacket(void);
    ~wscPimapPacket(void);
protected:

    WS_METHOD( ws_uint8  , GetVersion  )(void);
    WS_METHOD( ws_uint8  , GetFlag     )(void);
    WS_METHOD( ws_uint8  , GetXOR      )(void);
    WS_METHOD( ws_uint8  , GetTransID  )(void);
    WS_METHOD( ws_uint32 , GetUserID   )(void);
    WS_METHOD( ws_uint32 , GetKey      )(void);
    WS_METHOD( ws_uint16 , GetFunction )(void);
    WS_METHOD( ws_uint16 , GetAddLen   )(void);

    WS_METHOD( void  , SetVersion  )(ws_uint8  value);
    WS_METHOD( void  , SetFlag     )(ws_uint8  value);
    WS_METHOD( void  , SetXOR      )(ws_uint8  value);
    WS_METHOD( void  , SetTransID  )(ws_uint8  value);
    WS_METHOD( void  , SetUserID   )(ws_uint32 value);
    WS_METHOD( void  , SetKey      )(ws_uint32 value);
    WS_METHOD( void  , SetFunction )(ws_uint16 value);
    WS_METHOD( void  , SetAddLen   )(ws_uint16 value);

    WS_METHOD( void  , PutParam    )(ws_uint8 id, ws_uint8 type, ws_uint32 value);
    WS_METHOD( void  , PutParam    )(ws_uint8 id, ws_uint8 type, wsiString * str);
    WS_METHOD( ws_result, GetParam )(ws_uint8 id, ws_uint8 & type, ws_uint32 & value, wsiString ** str);

};

