#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiCallsParamList;


class wsiCallsHandler : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result, OnMethod)( wsiString * method, wsiCallsParamList * aParamList ) = 0;
};

