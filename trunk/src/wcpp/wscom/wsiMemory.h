#pragma once
#include <wcpp/lang/wsiObject.h>


#define WS_IID_OF_wsiMemory		\
	{ 0xa3ce5e84, 0x4b5c, 0x4bb3, { 0x96, 0x40, 0x32, 0x3c, 0x36, 0x78, 0xef, 0xc0 } }
// {A3CE5E84-4B5C-4bb3-9640-323C3678EFC0}


class wsiMemory : public wsiObject
{
public:
	static const ws_iid sIID;
public:
	WS_METHOD( void * ,     Alloc        )(ws_int size) = 0;
	WS_METHOD( void * ,     Realloc      )(void * ptr, ws_int newSize) = 0;
	WS_METHOD( void ,       Free         )(void * ptr) = 0;
	WS_METHOD( void ,       HeapMinimize )(ws_boolean immediate) = 0;
	WS_METHOD( ws_boolean , IsLowMemory  )(void) = 0;
};

