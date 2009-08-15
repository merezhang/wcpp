#include "ws_ptr_RootBase.h"
#include <wcpp/lang/wscThrowable.h>


ws_ptr_RootBase::ws_ptr_RootBase(void)
{
}


ws_ptr_RootBase::~ws_ptr_RootBase(void)
{
}


void ws_ptr_RootBase::ThrowNullPointerException(const ws_char * const msg , const ws_char * const file , ws_int line)
{
    throw wseNullPointerException::Throw( msg , file , line );
}

