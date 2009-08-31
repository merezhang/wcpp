#pragma once

#include <wcpp/lang/wsiObject.h>


class TransactionContext;


#define WS_IID_OF_wsiMethodExecutor     \
    { 0x58ed27, 0xcc6c, 0x4e66, { 0xbd, 0x29, 0x9d, 0xcf, 0x7a, 0x96, 0xc, 0xcd } }
// {0058ED27-CC6C-4e66-BD29-9DCF7A960CCD}


class wsiMethodExecutor : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Execute )( TransactionContext & tc ) = 0;
};

