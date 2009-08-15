#pragma once
#include <wcpp\lang\wsiobject.h>




class wsiModule;
class wsiComponentManager;
class wsiFile;


#define WS_IID_OF_wsiModuleHolder		\
	{ 0x7d477d08, 0x5936, 0x47b9, { 0x8a, 0xff, 0xc8, 0x44, 0xd2, 0xdc, 0xae, 0xb1 } }
// {7D477D08-5936-47b9-8AFF-C844D2DCAEB1}




class wsiModuleHolder : public wsiObject
{
public:

	static const ws_iid sIID;

	WS_METHOD(ws_result,GetModule)  (wsiModule ** ret) = 0;
	WS_METHOD(ws_result,GetBinFile) (wsiFile ** ret) = 0;
	WS_METHOD(ws_result,Unload)     (void) = 0;

};



