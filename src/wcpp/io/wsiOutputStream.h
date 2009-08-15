// wsiOutputStream.h
#ifndef __wsiOutputStream_h__
#define __wsiOutputStream_h__

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiOutputStream		\
	{ 0x2f5c1070, 0xcc9c, 0x4867, { 0x93, 0x67, 0x73, 0x69, 0x6b, 0x3c, 0xe8, 0xc0 } }
// {2F5C1070-CC9C-4867-9367-73696B3CE8C0}


class wsiOutputStream : public wsiObject
{
public:
    static const ws_iid sIID;
public:
    WS_METHOD( ws_result , Close )(void) = 0;
    WS_METHOD( ws_result , Flush )(void) = 0;
    WS_METHOD( ws_result , Write )(const void * buf, ws_int len) = 0;
    WS_METHOD( ws_result , Write )(ws_int b) = 0;
};


#endif // __wsOutputStream_h__
