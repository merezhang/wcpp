// wsxSingleLock.h
#ifndef __wsxSingleLock_h__
#define __wsxSingleLock_h__

#include "ws_type.h"


class wsuSyncObject;


class wsuSingleLock
{
public:

	explicit wsuSingleLock(wsuSyncObject * pObject);
	~wsuSingleLock(void);

	void Unlock(void);
	ws_boolean IsLocked(void);

private:

	wsuSyncObject * m_pSO;

};


#endif // __wsxSingleLock_h__
