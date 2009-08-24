#pragma once

#include <wcpp/lang/wsiObject.h>
#include <wcpp/io/wsiSerializable.h>
#include <wcpp/lang/wsiArray.h>


class wsiNetworkInterface;


#define WS_IID_OF_wsiInetAddress        \
    { 0x19f2e923, 0x92aa, 0x49d2, { 0x89, 0x42, 0xbf, 0x2a, 0x3d, 0x80, 0x29, 0x4a } }
// {19F2E923-92AA-49d2-8942-BF2A3D80294A}


class wsiInetAddress : /* public wsiObject ,*/ public wsiSerializable
{
public:

    static const ws_iid sIID;

public:

    WS_METHOD( ws_boolean , Equals               )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetAddress           )(wsiByteArray ** ret) = 0;
    WS_METHOD( ws_result  , GetCanonicalHostName )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , GetHostAddress       )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , GetHostName          )(wsiString ** ret) = 0;
    WS_METHOD( ws_int     , HashCode             )(void) = 0;

    WS_METHOD( ws_boolean , IsAnyLocalAddress    )(void) = 0;
    WS_METHOD( ws_boolean , IsLinkLocalAddress   )(void) = 0;
    WS_METHOD( ws_boolean , IsLoopbackAddress    )(void) = 0;
    WS_METHOD( ws_boolean , IsMCGlobal           )(void) = 0;
    WS_METHOD( ws_boolean , IsMCLinkLocal        )(void) = 0;
    WS_METHOD( ws_boolean , IsMCNodeLocal        )(void) = 0;
    WS_METHOD( ws_boolean , IsMCOrgLocal         )(void) = 0;
    WS_METHOD( ws_boolean , IsMCSiteLocal        )(void) = 0;
    WS_METHOD( ws_boolean , IsMulticastAddress   )(void) = 0;
    WS_METHOD( ws_boolean , IsReachable          )(ws_int timeout) = 0;
    WS_METHOD( ws_boolean , IsReachable          )(wsiNetworkInterface * netif, ws_int ttl, ws_int timeout) = 0;
    WS_METHOD( ws_boolean , IsSiteLocalAddress   )(void) = 0;
    WS_METHOD( ws_result  , ToString             )(wsiString ** ret) = 0;

};




/*  methods of NetworkInterface
    WS_METHOD( ws_boolean , Equals                )(wsiObject * obj) = 0;
    WS_METHOD( ws_result  , GetDisplayName        )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , GetHardwareAddress    )(wsiByteArray ** ret) = 0;
    WS_METHOD( ws_result  , GetInetAddresses      )(wsiEnumeration<wsiInetAddress> ** ret) = 0;
    WS_METHOD( ws_result  , GetInterfaceAddresses )(wsiList<wsiInterfaceAddress> ** ret) = 0;
    WS_METHOD( ws_int     , GetMTU                )(void) = 0;
    WS_METHOD( ws_result  , GetName               )(wsiString ** ret) = 0;
    WS_METHOD( ws_result  , GetParent             )(wsiNetworkInterface ** ret) = 0;
    WS_METHOD( ws_result  , GetSubInterfaces      )(wsiEnumeration<wsiNetworkInterface> ** ret) = 0;
    WS_METHOD( ws_int     , HashCode              )(void) = 0;
    WS_METHOD( ws_boolean , IsLoopback            )(void) = 0;
    WS_METHOD( ws_boolean , IsPointToPoint        )(void) = 0;
    WS_METHOD( ws_boolean , IsUp                  )(void) = 0;
    WS_METHOD( ws_boolean , IsVirtual             )(void) = 0;
    WS_METHOD( ws_boolean , SupportsMulticast     )(void) = 0;
    WS_METHOD( ws_result  , ToString              )(wsiString ** ret) = 0;

    static  ws_result   GetByInetAddress     (wsiNetworkInterface ** ret , wsiInetAddress * addr);
    static  ws_result   GetByName            (wsiNetworkInterface ** ret , wsiString * name);
    static  ws_result   GetNetworkInterfaces (wsiEnumeration<wsiNetworkInterface> ** ret);

*/

