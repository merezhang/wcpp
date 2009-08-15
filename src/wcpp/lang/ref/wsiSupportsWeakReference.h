#pragma once
#include <wcpp/lang/wsiObject.h>
#include "wsiWeakReference.h"


#define WS_IID_OF_wsiSupportsWeakReference      \
    { 0x87833ca2, 0xbebf, 0x4b27, { 0xb2, 0xe, 0x15, 0xaf, 0x7b, 0x77, 0x2a, 0x7b } }
// {87833CA2-BEBF-4b27-B20E-15AF7B772A7B}


class wsiSupportsWeakReference : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result , GetWeakReference )(wsiWeakReference ** ret) = 0;
};

