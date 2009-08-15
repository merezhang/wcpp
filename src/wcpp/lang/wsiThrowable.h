// wsiThrowable.h
#ifndef __wsiThrowable_h__
#define __wsiThrowable_h__

#include "wsiObject.h"


class wsiVString;


#ifdef GetMessage
    #undef GetMessage
#endif



#define WS_IID_OF_wsiThrowable      \
    { 0x7f32b740, 0x8007, 0x412d, { 0xb2, 0x80, 0x83, 0xd3, 0xc2, 0x5d, 0x5, 0xb4 } }
// {7F32B740-8007-412d-B280-83D3C25D05B4}


class wsiThrowable : public wsiObject
{
public:
	static const ws_iid sIID;

	WS_METHOD( ws_result , GetMessage      )(wsiString ** rString) = 0;
	WS_METHOD( ws_result , PrintStackTrace )(void) = 0;
	WS_METHOD( ws_result , ToString        )(wsiString ** rString) = 0;

};




#endif // __wsiThrowable_h__
