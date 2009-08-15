// wsuSingleLock.cpp
#include "wsuSingleLock.h"
#include "wsuSyncObject.h"


wsuSingleLock::wsuSingleLock(wsuSyncObject * pObject) : m_pSO( pObject )
{
    if (pObject) pObject->Lock();
}


wsuSingleLock::~wsuSingleLock(void)
{
    Unlock();
}


void wsuSingleLock::Unlock(void)
{
    wsuSyncObject * pObject = m_pSO;
    m_pSO = WS_NULL;
    if (pObject) pObject->Unlock();
}


ws_boolean wsuSingleLock::IsLocked(void)
{
    return ((m_pSO) ? WS_TRUE : WS_FALSE);
}

