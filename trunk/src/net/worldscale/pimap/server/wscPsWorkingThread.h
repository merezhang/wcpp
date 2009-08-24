#pragma once

#include <wcpp/lang/wscThread.h>
#include "wsiPsWorkingContext.h"


class wscPsWorkingThread : public wscThread
{
private:
    ws_safe_ptr<wsiPsWorkingContext> m_WorkingContext;
protected:
    wscPsWorkingThread(wsiPsWorkingContext * pWorkingContext);
    ~wscPsWorkingThread(void);

    WS_METHOD( ws_result , Run )(void);

};

