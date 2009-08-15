// wsiInputStream.h
#ifndef __wsiInputStream_h__
#define __wsiInputStream_h__

#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiInputStream    \
    { 0xb6d731f5, 0x8bb, 0x43f7, { 0x93, 0x87, 0x30, 0x7b, 0xe1, 0x52, 0x57, 0x7f } }
// {B6D731F5-08BB-43f7-9387-307BE152577F}


class wsiInputStream : public wsiObject
{
public:
    static const ws_iid sIID;

	WS_METHOD( ws_int     , Available     )(void)                 = 0;
	WS_METHOD( ws_result  , Close         )(void)                 = 0;
	WS_METHOD( ws_result  , Mark          )(ws_int readlimit)     = 0;
	WS_METHOD( ws_boolean , MarkSupported )(void)                 = 0;
	WS_METHOD( ws_int     , Read          )(void)                 = 0;	// abstract
	WS_METHOD( ws_int     , Read          )(void * b, ws_int len) = 0;
	WS_METHOD( ws_result  , Reset         )(void)                 = 0;
	WS_METHOD( ws_long    , Skip          )(ws_long n)            = 0;
};




#endif // __wsInputStream_h__
