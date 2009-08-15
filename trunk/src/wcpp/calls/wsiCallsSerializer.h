#pragma once
#include "wsiCallsHandler.h"


#define WS_IID_OF_wsiCallsSerializer        \
    { 0xb07c8090, 0xc028, 0x4054, { 0x9e, 0xe0, 0xf5, 0x45, 0x91, 0x33, 0x41, 0xd1 } }
// {B07C8090-C028-4054-9EE0-F545913341D1}


class wsiCallsSerializer : public wsiCallsHandler
{
public:
    static const ws_iid sIID;
public:
};

