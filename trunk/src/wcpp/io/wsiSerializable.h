#pragma once

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiSerializable       \
    { 0xf7aeb2f0, 0xac87, 0x43c2, { 0x95, 0xf0, 0x61, 0x9d, 0x63, 0x34, 0x71, 0x73 } }
// {F7AEB2F0-AC87-43c2-95F0-619D63347173}


class wsiSerializable : public wsiObject
{
public:
    static const ws_iid sIID;
};

