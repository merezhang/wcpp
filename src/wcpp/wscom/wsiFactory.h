#pragma once
#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiFactory        \
    { 0x286033f0, 0x64ab, 0x4290, { 0x88, 0xd3, 0xa3, 0x96, 0x99, 0xd2, 0x25, 0xe1 } }
// {286033F0-64AB-4290-88D3-A39699D225E1}


class wsiFactory : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result , CreateInstance )(wsiObject * aOuter, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result , LockFactory    )(ws_boolean aLock) = 0;
};

