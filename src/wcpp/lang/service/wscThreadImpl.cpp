#include "wscThreadImpl.h"
#include <wcpp/lang/wscThrowable.h>


wscThreadImpl::wscThreadImpl(wsiRunnable * target, wsiString * name) : m_thread( WS_NULL )
{
    m_target = target;
    m_name = name;
}


wscThreadImpl::~wscThreadImpl(void)
{
    ws_thread * thd = m_thread;
    m_thread = WS_NULL;
    if (thd) delete thd;
}


ws_result wscThreadImpl::GetName(wsiString ** rName)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_int wscThreadImpl::GetPriority(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscThreadImpl::Interrupt(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_boolean wscThreadImpl::IsAlive(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscThreadImpl::Join(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscThreadImpl::Run(void)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscThreadImpl::SetPriority(ws_int newPriority)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}


ws_result wscThreadImpl::Start(void)
{
    ws_thread * thd = m_thread;
    if (thd == WS_NULL) {
        thd = ws_thread::StartThread( this );
        m_thread = thd;
        if (thd==WS_NULL) {
            WS_THROW( wseIllegalThreadStateException , "" );
        }
        return ws_result( WS_RLT_SUCCESS );
    }
    else {
        WS_THROW( wseIllegalThreadStateException , "" );
    }
}


ws_result wscThreadImpl::ThreadProc(void)
{
    return m_target->Run();
}

