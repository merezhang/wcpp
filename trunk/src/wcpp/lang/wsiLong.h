// wsiLong.h

#ifndef __wsiLong_h__
#define __wsiLong_h__

#include "wsiNumber.h"


#define WS_IID_OF_wsiLong       \
    { 0xf360bdf7, 0x32b6, 0x4fa4, { 0x87, 0xcb, 0x67, 0x53, 0xbe, 0xdb, 0xa0, 0xd2 } }
// {F360BDF7-32B6-4fa4-87CB-6753BEDBA0D2}


class wsiLong : public wsiNumber
{
public:
	static const ws_iid sIID;
};


#endif // __wsiLong_h__
