#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiReference : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result , GetTarget )(const ws_iid & aIID, void ** ret) = 0;
};

