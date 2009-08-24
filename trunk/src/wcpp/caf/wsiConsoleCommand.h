#pragma once

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiConsoleCommand     \
    { 0x3f278bf3, 0x46a2, 0x4cbf, { 0xa1, 0x62, 0xa0, 0xb9, 0x1a, 0xd1, 0xb7, 0xd9 } }
// {3F278BF3-46A2-4cbf-A162-A0B91AD1B7D9}


class wsiConsoleCommand : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetName          )(wsiString ** ret) = 0;
    WS_METHOD( ws_result , GetCommandString )(wsiString ** ret) = 0;
};

