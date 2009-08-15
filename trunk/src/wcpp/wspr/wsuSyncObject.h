// wsuSyncObject.h
#ifndef __wsuSyncObject_h__
#define __wsuSyncObject_h__

#include "ws_type.h"


class wsuSyncObject
{
protected:
    explicit wsuSyncObject(void);
    explicit wsuSyncObject(const wsuSyncObject & init);
    WS_VIRTUAL_DESTRUCTOR( wsuSyncObject );
    const wsuSyncObject & operator=(const wsuSyncObject & src);
public:
    WS_VFUNC( void, Lock   )(void) = 0;
    WS_VFUNC( void, Unlock )(void) = 0;
};


#endif // __wsuSyncObject_h__
