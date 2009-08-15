#pragma once
#include "wsiObject.h"
#include "wsiRunnable.h"


#define WS_IID_OF_wsiThread     \
    { 0x6434b576, 0xb8f4, 0x41ad, { 0xbf, 0x7a, 0x74, 0x9, 0x44, 0x99, 0xf7, 0x7 } }
// {6434B576-B8F4-41ad-BF7A-74094499F707}


class wsiThread : public wsiRunnable
{
public:
	static const ws_iid sIID;
public:
	enum _priority
	{
		WS_MAX_PRIORITY  = 15,
		WS_NORM_PRIORITY = 0,
		WS_MIN_PRIORITY  = -15,
	};
public:
	WS_METHOD( ws_result  , GetName     )(wsiString ** rName) = 0;
	WS_METHOD( ws_int     , GetPriority )(void) = 0;
	WS_METHOD( ws_result  , Interrupt   )(void) = 0;
	WS_METHOD( ws_boolean , IsAlive     )(void) = 0;
	WS_METHOD( ws_result  , Join        )(void) = 0;
	WS_METHOD( ws_result  , Run         )(void) = 0;
	WS_METHOD( ws_result  , SetPriority )(ws_int newPriority) = 0;
	WS_METHOD( ws_result  , Start       )(void) = 0;
	WS_METHOD( ws_result  , ToString    )(wsiString ** rString) = 0;
};

