#ifndef __wsiDataInputStream_h__
#define __wsiDataInputStream_h__

#include "wsiInputStream.h"
#include "wsiDataInput.h"




class wsiDataInputStream : public wsiInputStream, public wsiDataInput
{
public:
	static const ws_iid sIID;
};




#endif // __wsDataInputStream_h__
