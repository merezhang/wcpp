#pragma once

#include "wsuSyncObject.h"


class ws_mutex;


class wsuMutex : public wsuSyncObject
{
private:
    ws_mutex * m_pMutex;
private:
    const wsuMutex & operator=(const wsuMutex & src);
    explicit wsuMutex(const wsuMutex & init);
public:
    explicit wsuMutex(void);
    ~wsuMutex(void);
public:
    WS_VFUNC( void, Lock   )(void);
    WS_VFUNC( void, Unlock )(void);
};

