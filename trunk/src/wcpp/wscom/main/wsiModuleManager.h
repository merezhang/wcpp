#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiClassRecord;
class wsiModuleHolder;
class wsiFile;
class wsiDirectoryServiceProvider;


#define WS_IID_OF_wsiModuleManager        \
    { 0xbdb13fed, 0x9e48, 0x4f75, { 0x83, 0xab, 0x60, 0x24, 0xec, 0x98, 0xd, 0x7f } }
// {BDB13FED-9E48-4f75-83AB-6024EC980D7F}


class wsiModuleManager : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , GetClassRecord   )(wsiClassRecord ** ret , const ws_cid & aClass) = 0;
    WS_METHOD( ws_result , GetClassRecord   )(wsiClassRecord ** ret , wsiString * aContractID) = 0;
    WS_METHOD( ws_result , SaveClassRecord  )(wsiClassRecord * aClassRec) = 0;
    WS_METHOD( ws_result , SaveModuleHolder )(wsiModuleHolder * aModuleHolder) = 0;

    WS_METHOD( ws_result , SaveRegInfo      )(wsiDirectoryServiceProvider * appFileLocationProvider) = 0;
    WS_METHOD( ws_result , LoadRegInfo      )(wsiDirectoryServiceProvider * appFileLocationProvider) = 0;

};



