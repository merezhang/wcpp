#include "wscMemory.h"
#include <wcpp/lang/wscThrowable.h>


wscMemory::wscMemory(void)
:   m_started(WS_FALSE),
    m_stopped(WS_FALSE)
{
}


wscMemory::~wscMemory(void)
{
}


void wscMemory::_StartMemoryManager(void)
{
    m_started = WS_TRUE;
}


void wscMemory::_StopMemoryManager(void)
{
    m_stopped = WS_TRUE;
}

	
void * wscMemory::Alloc(ws_int size)
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


void * wscMemory::Realloc(void * ptr, ws_int newSize)
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


void wscMemory::Free(void * ptr)
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


void wscMemory::HeapMinimize(ws_boolean immediate)
{
	WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean wscMemory::IsLowMemory(void)
{
	WS_THROW( wseUnsupportedOperationException , "" );
}

