#pragma once

#include <wcpp/lang/wscThread.h>


class wsiPcWorkingContext;
class wsiPcEventDispatcher;


class wscPcReceiveThread : public wscThread
{
private:
    ws_safe_ptr< wsiPcWorkingContext  >    m_WorkingContext;
public:
    wscPcReceiveThread(wsiPcWorkingContext * wkContext);
    ~wscPcReceiveThread(void);
protected:
	WS_METHOD( ws_result , Run )(void);
};

