#pragma once

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiPsUser       \
    { 0x2b67adba, 0x67f, 0x4758, { 0xb1, 0xd7, 0x7, 0x25, 0xee, 0x44, 0x46, 0xa6 } }
// {2B67ADBA-067F-4758-B1D7-0725EE4446A6}


class wsiPsUser : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_uint32 , GetUserId )(void) = 0;
};

