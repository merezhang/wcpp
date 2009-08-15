#pragma once

#include <wcpp/lang/wsiObject.h>


class wsiFile;
class wsiDirectoryServiceProvider;
class wsiModuleManager;


#define WS_IID_OF_wsiGlobalManager      \
    { 0xaafd0987, 0xca5f, 0x4178, { 0x86, 0xcc, 0xd9, 0x52, 0xe3, 0xe9, 0xff, 0x8e } }
// {AAFD0987-CA5F-4178-86CC-D952E3E9FF8E}


class wsiGlobalManager : public wsiObject
{
public:

    static const ws_iid sIID;

public:

    WS_METHOD( ws_result , GetServiceManager     )(wsiServiceManager     ** ret) = 0;
    WS_METHOD( ws_result , GetComponentManager   )(wsiComponentManager   ** ret) = 0;
    WS_METHOD( ws_result , GetComponentRegistrar )(wsiComponentRegistrar ** ret) = 0;
    WS_METHOD( ws_result , GetMemoryManager      )(wsiMemory             ** ret) = 0;
    WS_METHOD( ws_result , GetModuleManager      )(wsiModuleManager      ** ret) = 0;

    WS_METHOD( ws_result , StartGM )(wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider) = 0;
    WS_METHOD( ws_result , StopGM  )(void) = 0;

};

