#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiCString;


#define WS_IID_OF_wsiComponentManager		\
	{ 0x791a0e1, 0xb851, 0x4179, { 0xa9, 0x2a, 0x7e, 0x55, 0xb3, 0x7d, 0x3d, 0xb } }
// {0791A0E1-B851-4179-A92A-7E55B37D3D0B}


class wsiComponentManager : public wsiObject
{
public:
	static const ws_iid sIID;

	WS_METHOD( ws_result , GetClassObject             )(const ws_cid & aCID, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result , GetClassObjectByContractID )(wsiString * aContractID, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result , CreateInstance             )(const ws_cid & aCID, wsiObject * aDelegate, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result , CreateInstanceByContractID )(wsiString * aContractID, wsiObject * aDelegate, const ws_iid & aIID, void ** ret) = 0;
};

