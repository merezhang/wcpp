#pragma once

#include "wsiObject.h"


#define WS_IID_OF_wsiRuntime        \
    { 0xad84ffc9, 0x3bbb, 0x4f03, { 0xbe, 0xba, 0xfb, 0x5, 0x78, 0xac, 0x83, 0x27 } }
// {AD84FFC9-3BBB-4f03-BEBA-FB0578AC8327}


class wsiRuntime : public wsiObject
{
public:

	static const ws_iid sIID;

	WS_METHOD( ws_result , Exit        )(ws_int status) = 0;
	WS_METHOD( ws_long   , FreeMemory  )(void) = 0;
	WS_METHOD( ws_result , Gc          )(void) = 0;
	WS_METHOD( ws_long   , TotalMemory )(void) = 0;

};



