// wsiSystem.h
#ifndef __wsiSystem_h__
#define __wsiSystem_h__

#include "wsiObject.h"




class wsiPrintStream;
class wsiInputStream;




#define WS_IID_OF_wsiSystem		\
	{ 0xfac4ad98, 0x7554, 0x4561, { 0xaf, 0x17, 0x9a, 0x5a, 0xdb, 0x66, 0xad, 0x30 } }
// {FAC4AD98-7554-4561-AF17-9A5ADB66AD30}




class wsiSystem : public wsiObject
{
public:
	static const ws_iid sIID;

};




#endif // __wsiSystem_h__
