#ifndef __wscDataOutput_h__
#define __wscDataOutput_h__

#include <wcpp/lang/wscObject.h>
#include "wsiDataOutput.h"


class wscDataOutput : public wscObject, public wsiDataOutput
{
public:
	static const ws_iid sIID;
};


#endif // __wsIDataOutput_h__
