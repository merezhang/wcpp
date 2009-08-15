// wsiClass.h
#ifndef __wsiClass_h__
#define __wsiClass_h__

#include "wsiObject.h"


class wsiString;


#define WS_IID_OF_wsiClass      \
    { 0x87af473a, 0xedfe, 0x40d2, { 0x9a, 0x34, 0xea, 0x52, 0x53, 0x5d, 0xf0, 0x15 } }
// {87AF473A-EDFE-40d2-9A34-EA52535DF015}




class wsiClass : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( ws_result             , GetName )(wsiString ** rString) = 0;
	WS_METHOD( const ws_char * const , GetName )(void) = 0;
};


#endif // __wsiClass_h__
