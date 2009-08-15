#include "wsuMutex.h"
#include "ws_mutex.h"


wsuMutex::wsuMutex(void) : m_pMutex(WS_NULL)
{
    m_pMutex = ws_mutex::New();
}


wsuMutex::~wsuMutex(void)
{
    ws_mutex * pdel = m_pMutex;
    m_pMutex = WS_NULL;
    if (pdel) delete pdel;
}


void wsuMutex::Lock(void)
{
    ws_mutex * p = m_pMutex;
	if (p) p->Lock();
}


void wsuMutex::Unlock(void)
{
    ws_mutex * p = m_pMutex;
	if (p) p->Unlock();
}

