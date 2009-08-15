#pragma once
#include <wcpp/lang/wsiobject.h>


class wsiDatagramSocket;


#define WS_IID_OF_wsiNetwork		\
	{ 0x3d9aefc0, 0x5aac, 0x4596, { 0x8e, 0xaa, 0x15, 0x2b, 0xab, 0x97, 0xa7, 0x7d } }
// {3D9AEFC0-5AAC-4596-8EAA-152BAB97A77D}


class wsiNetwork : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , CreateDatagramSocket )(wsiDatagramSocket ** ret) = 0;
};



