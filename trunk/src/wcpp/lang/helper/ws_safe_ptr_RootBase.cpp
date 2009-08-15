#include "ws_safe_ptr_RootBase.h"
#include <wcpp/wspr/ws_type.h>
#include <wcpp/lang/wsiInterface.h>
#include <wcpp/lang/wscThrowable.h>
#include "ws_runtime.h"


void ws_safe_ptr_RootBase::ThrowNullPointerException(const ws_char * const msg, const ws_char * const file, ws_int line)
{
    throw wseNullPointerException::Throw( msg , file , line );
}


ws_safe_ptr_RootBase::ws_safe_ptr_RootBase(void)
{
}


ws_safe_ptr_RootBase::~ws_safe_ptr_RootBase(void)
{
}


void ws_safe_ptr_RootBase::SwapPtr(void ** pp1 , void ** pp2)
{
    ws_runtime::getRuntime()->SwapPtr( pp1 , pp2 );
}

