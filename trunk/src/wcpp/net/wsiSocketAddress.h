#pragma once

#include <wcpp/io/wsiSerializable.h>


#define WS_IID_OF_wsiSocketAddress      \
    { 0xcd5b4e4c, 0xdcb2, 0x40db, { 0x88, 0x8a, 0x59, 0xe7, 0x30, 0xe1, 0x34, 0xe0 } }
// {CD5B4E4C-DCB2-40db-888A-59E730E134E0}


class wsiSocketAddress : /* public wsiObject , */ public wsiSerializable
{
public:
    static const ws_iid sIID;
public:
};

