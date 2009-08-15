#pragma once
#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiServiceManager		\
	{ 0x7cc65860, 0xbc40, 0x43d9, { 0x83, 0xd0, 0xdb, 0x63, 0xea, 0x13, 0xff, 0x8c } }
// {7CC65860-BC40-43d9-83D0-DB63EA13FF8C}


class wsiServiceManager : public wsiObject
{
public:
	static const ws_iid sIID;

	WS_METHOD( ws_result  , GetService                        )(const ws_cid & aClass,    const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_result  , GetServiceByContractID            )(wsiString * aContractID, const ws_iid & aIID, void ** ret) = 0;
	WS_METHOD( ws_boolean , IsServiceInstantiated             )(const ws_cid & aClass,    const ws_iid & aIID) = 0;
	WS_METHOD( ws_boolean , IsServiceInstantiatedByContractID )(wsiString * aContractID, const ws_iid & aIID) = 0;

};

