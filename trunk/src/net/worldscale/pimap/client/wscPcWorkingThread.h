#pragma once

#include <wcpp/lang/wscThread.h>


class wsiPcWorkingContext;
class wsiPcExchangeBuffer;
class wsiPcTransmitter;
class wsiPcEventDispatcher;


class wscPcWorkingThread : public wscThread
{
private:
    ws_safe_ptr<wsiPcWorkingContext>  m_WorkingContext;
public:
    wscPcWorkingThread(wsiPcWorkingContext * wkContext);
    ~wscPcWorkingThread(void);
protected:
	WS_METHOD( ws_result  , Run         )(void);
};

