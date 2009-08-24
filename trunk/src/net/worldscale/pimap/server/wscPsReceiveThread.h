#pragma once

#include <wcpp/lang/wscThread.h>
#include "wsiPsWorkingContext.h"


class wscPsReceiveThread : public wscThread
{
private:
    ws_safe_ptr<wsiPsWorkingContext> m_WorkingContext;
protected:
    wscPsReceiveThread(wsiPsWorkingContext * pWorkingContext);
    ~wscPsReceiveThread();
    WS_METHOD( ws_result , Run )(void);
};

