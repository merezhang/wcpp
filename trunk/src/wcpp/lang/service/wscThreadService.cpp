#include "wscThreadService.h"
#include <wcpp/lang/wscThread.h>
#include <wcpp/wspr/ws_thread.h>


const ws_char * const wscThreadService::s_class_name = "wcpp.lang.service.wscThreadService";


wscThreadService::wscThreadService(void)
{
}


wscThreadService::~wscThreadService(void)
{
}


ws_result wscThreadService::NewThread(wsiRunnable * target, wsiString * name, wsiThread ** ret)
{
    wscThread::New(ret,target,name);
    return ws_result( WS_RLT_SUCCESS );
}


ws_result wscThreadService::Sleep(ws_long millis)
{
    ws_thread::Sleep( millis );
    return ws_result( WS_RLT_SUCCESS );
}

