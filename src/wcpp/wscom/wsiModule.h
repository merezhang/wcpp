#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiComponentManager;
class wsiFile;
class wsiCString;


#define WS_IID_OF_wsiModule     \
    { 0x3dccf5d0, 0x9a7, 0x42cf, { 0xa9, 0x73, 0x1, 0xbc, 0x62, 0x61, 0x74, 0x24 } }
// {3DCCF5D0-09A7-42cf-A973-01BC62617424}


class wsiModule : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result,  GetClassObject )(wsiComponentManager * aCompMgr, const ws_cid & aCID, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result,  RegisterSelf   )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr, wsiString * aType) = 0;
	WS_METHOD( ws_result,  UnregisterSelf )(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr) = 0;
	WS_METHOD( ws_boolean, CanUnload      )(wsiComponentManager * aCompMgr) = 0;
};

