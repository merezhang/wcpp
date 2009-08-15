// wsiObject.h
#ifndef __wsiObject_h__
#define __wsiObject_h__

#include "wsiInterface.h"




#define WS_IID_OF_wsiObject			\
	{ 0x3f45a92b, 0xa7d5, 0x4d93, { 0x94, 0x6c, 0x37, 0x3e, 0x56, 0xa8, 0xc1, 0x7b } }
// {3F45A92B-A7D5-4d93-946C-373E56A8C17B}



class wsiClass;
class wsiString;



class wsiObject : public wsiInterface
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_boolean , Equals    )(wsiObject * obj)               = 0;
	WS_METHOD( ws_result  , GetClass  )(wsiClass ** rClass)            = 0;
	WS_METHOD( ws_int     , HashCode  )(void)                          = 0;
	WS_METHOD( ws_result  , Notify    )(void)                          = 0;
	WS_METHOD( ws_result  , NotifyAll )(void)                          = 0;
	WS_METHOD( ws_result  , ToString  )(wsiString ** rString)          = 0;
	WS_METHOD( ws_result  , Wait      )(void)                          = 0;
	WS_METHOD( ws_result  , Wait      )(ws_long timeout)               = 0;
	WS_METHOD( ws_result  , Wait      )(ws_long timeout, ws_int nanos) = 0;
protected:
	WS_METHOD( ws_result  , Clone     )(wsiObject ** ret)              = 0;
	WS_METHOD( ws_result  , Finalize  )(void)                          = 0;
};




#endif // __wsiObject_h__
