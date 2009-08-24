#include "wscPsResponseThread.h"


wscPsResponseThread::wscPsResponseThread(wsiPsWorkingContext * pWorkingContext)
{
    m_WorkingContext.Set( pWorkingContext );
}


wscPsResponseThread::~wscPsResponseThread(void)
{
}


ws_result wscPsResponseThread::Run(void)
{
    ws_ptr<wsiPsWorkingContext> wkContext;
    m_WorkingContext.Get( &wkContext );

    while ( ! wkContext->GetStopFlag() ) {
        Sleep( 100 );
    }

    return WS_RLT_SUCCESS;
}

