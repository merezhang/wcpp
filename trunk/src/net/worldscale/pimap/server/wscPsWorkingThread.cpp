#include "wscPsWorkingThread.h"
#include "wscPsReceiveThread.h"
#include "wscPsResponseThread.h"
#include <vector>



wscPsWorkingThread::wscPsWorkingThread(wsiPsWorkingContext * pWorkingContext)
{
    m_WorkingContext.Set( pWorkingContext );
}


wscPsWorkingThread::~wscPsWorkingThread(void)
{
}


ws_result wscPsWorkingThread::Run(void)
{
    // prepare threads list
    typedef  ws_ptr<wsiThread>  t_list_threads_item;
    typedef std::vector< t_list_threads_item > t_list_threads;
    t_list_threads   threads;

    // get working context
    ws_ptr<wsiPsWorkingContext> wc;
    m_WorkingContext.Get( &wc );

    // create response threads
    for (int i=0; i<64; i++) {
        ws_ptr<wsiThread> thd;
        if ( NewObj<wscPsResponseThread>(&thd,wc) == WS_RLT_SUCCESS ) {
            threads.push_back( thd );
            thd->Start();
        }
    }

    // create receive thread
    ws_ptr<wsiThread> thdRcv;
    if ( NewObj<wscPsReceiveThread>(&thdRcv,wc) == WS_RLT_SUCCESS ) {
        threads.push_back( thdRcv );
        thdRcv->Start();
    }

    // wait for all sub threads exit
    for ( t_list_threads::iterator iter=threads.begin() ; iter!=threads.end() ; iter++ ) {
        t_list_threads_item thd = (*iter);
        if (!(!thd)) {
            thd->Join();
        }
    }

    return WS_RLT_SUCCESS;
}

