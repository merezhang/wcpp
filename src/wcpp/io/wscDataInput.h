#ifndef __wscDataInput_h__
#define __wscDataInput_h__

#include <wcpp/lang/wscObject.h>
#include "wsiDataInput.h"


class wscDataInput : public wscObject , public wsiDataInput
{
public:
	static const ws_iid sIID;
};


#endif // __wsIDataInput_h__
