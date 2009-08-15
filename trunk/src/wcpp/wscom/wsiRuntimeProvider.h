#pragma once

#include <wcpp/lang/wsiObject.h>


class ws_runtime;


#ifdef WS_DEBUG
    #define WS_IID_OF_wsiRuntimeProvider        \
        { 0x75c22553, 0x78ed, 0x4f85, { 0xa7, 0xd5, 0xce, 0x1a, 0x3d, 0xb5, 0x81, 0x98 } }
        // {75C22553-78ED-4f85-A7D5-CE1A3DB58198}
#else
    #define WS_IID_OF_wsiRuntimeProvider        \
        { 0x75974a1f, 0xb6d3, 0x47b4, { 0xa0, 0x1d, 0x84, 0xcd, 0x8b, 0xc4, 0x49, 0x4b } }
        // {75974A1F-B6D3-47b4-A01D-84CD8BC4494B}
#endif


class wsiRuntimeProvider : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_runtime * , GetRuntime )(void) = 0;
};

