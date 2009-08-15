#pragma once
#include <wcpp/lang/wscObject.h>
#include <wcpp/wscom/wsiMemory.h>


#define WS_CID_OF_wscMemory		\
	{ 0x9b99e318, 0x1213, 0x42de, { 0xab, 0x86, 0xa, 0xb8, 0x74, 0x57, 0xe6, 0xa5 } }
// {9B99E318-1213-42de-AB86-0AB87457E6A5}




class wscMemory : public wsiMemory
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscMemory )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiMemory )
    WS_IMPL_QUERY_INTERFACE_END()
public:

    static const ws_char * const s_class_name;

public:

	wscMemory(void);
	~wscMemory(void);

protected:

	WS_METHOD( void * ,     Alloc         )(ws_int size);
	WS_METHOD( void * ,     Realloc       )(void * ptr, ws_int newSize);
	WS_METHOD( void ,       Free          )(void * ptr);
	WS_METHOD( void ,       HeapMinimize  )(ws_boolean immediate);
	WS_METHOD( ws_boolean , IsLowMemory   )(void);

    void _StartMemoryManager(void);
    void _StopMemoryManager(void);

private:
    ws_boolean m_started;
    ws_boolean m_stopped;

};

