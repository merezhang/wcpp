#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiInputStream;


#define WS_IID_OF_wsiCallsParser        \
    { 0x7cef95c, 0xb22a, 0x424f, { 0xb2, 0xbf, 0xb2, 0x19, 0x2f, 0x27, 0x9b, 0x63 } }
// {07CEF95C-B22A-424f-B2BF-B2192F279B63}


class wsiCallsParser : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , parse)(wsiInputStream * is) = 0;
};

