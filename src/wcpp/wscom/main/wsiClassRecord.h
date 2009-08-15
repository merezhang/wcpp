#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiFile;
class wsiModule;
class wsiFactory;


#define WS_IID_OF_wsiClassRecord        \
    { 0xbd5ba5d7, 0x8338, 0x432f, { 0x9c, 0xb1, 0xb5, 0xa, 0x54, 0x36, 0xf0, 0x4a } }
// {BD5BA5D7-8338-432f-9CB1-B50A5436F04A}


class wsiClassRecord : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetClassID    )(ws_cid &      ret) = 0;
    WS_METHOD( ws_result , GetContractID )(wsiString  ** ret) = 0;
    WS_METHOD( ws_result , GetBinFile    )(wsiFile    ** ret) = 0;
    WS_METHOD( ws_result , GetFactory    )(wsiFactory ** ret) = 0;
    WS_METHOD( ws_result , GetClassName  )(wsiString  ** ret) = 0;

    WS_METHOD( ws_result , SetBinFile    )(wsiFile    * aBinFile    ) = 0;
    WS_METHOD( ws_result , SetClassName  )(wsiString  * aClassName  ) = 0;
    WS_METHOD( ws_result , SetContractID )(wsiString  * aContractID ) = 0;
    WS_METHOD( ws_result , SetFactory    )(wsiFactory * aFactory    ) = 0;
};

