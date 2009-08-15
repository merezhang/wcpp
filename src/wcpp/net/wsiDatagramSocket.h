#pragma once
#include <wcpp/lang/wsiobject.h>


#define WS_IID_OF_wsiDatagramSocket		\
	{ 0xb8508ed7, 0x1c00, 0x4495, { 0x85, 0x23, 0x17, 0x33, 0x74, 0xac, 0x4d, 0xa2 } }
// {B8508ED7-1C00-4495-8523-173374AC4DA2}


class wsiDatagramSocket : public wsiObject
{
public:
    static const ws_iid sIID;
};

