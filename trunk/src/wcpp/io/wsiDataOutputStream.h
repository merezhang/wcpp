#ifndef __wsiDataOutputStream_h__
#define __wsiDataOutputStream_h__

#include "wsiOutputStream.h"
#include "wsiDataOutput.h"




class wsiDataOutputStream : public wsiOutputStream, public wsiDataOutput
{
public:
	static const ws_iid sIID;
};




#endif // __wsDataOutputStream_h__
