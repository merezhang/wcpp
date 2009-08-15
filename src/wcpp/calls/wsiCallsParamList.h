#pragma once
#include <wcpp/lang/wsiObject.h>
#include <wcpp/lang/wsiString.h>


class wsiCallsParamList : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_int ,   CountParam)(void) = 0;
    WS_METHOD( ws_result, GetParam  )(ws_int index, wsiString ** rParamString) = 0;
};

