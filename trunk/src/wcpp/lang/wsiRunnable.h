#pragma once
#include "wsiObject.h"


#define WS_IID_OF_wsiRunnable       \
    { 0x764fb251, 0xabf2, 0x41c6, { 0xa9, 0x44, 0x3b, 0xb2, 0x54, 0xa1, 0x4a, 0x85 } }
// {764FB251-ABF2-41c6-A944-3BB254A14A85}


class wsiRunnable : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result , Run )(void) = 0;
};

