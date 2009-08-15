#pragma once
#include "wsiobject.h"


#define WS_IID_OF_wsiUUID       \
    { 0xd44e9968, 0xa5b2, 0x41c1, { 0x9e, 0x49, 0x34, 0x2c, 0xfe, 0x3a, 0x6d, 0xf6 } }
// {D44E9968-A5B2-41c1-9E49-342CFE3A6DF6}


class wsiUUID : public wsiObject
{
public:
	static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetUUID )(ws_uuid & uuid) = 0;
    WS_METHOD( ws_result , SetUUID )(const ws_uuid & uuid) = 0;
};

