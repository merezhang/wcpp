#pragma once

#include <wcpp/lang/wscThread.h>
#include "wsiPsWorkingContext.h"


class wscPsResponseThread : public wscThread
{
private:
    ws_safe_ptr<wsiPsWorkingContext> m_WorkingContext;
protected:
    wscPsResponseThread(wsiPsWorkingContext * pWorkingContext);
    ~wscPsResponseThread();
    WS_METHOD( ws_result , Run )(void);
};

