#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiDirectoryServiceProvider : public wsiObject
{
public:
	static const ws_iid sIID;
public:
    WS_METHOD( ws_boolean , GetFile )(wsiString * prop, wsiFile ** ret) = 0;
};

