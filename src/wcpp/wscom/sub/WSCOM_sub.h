#pragma once
#include <wcpp/wscom/WSCOM.h>


class wsiModule;


class WSCOM_sub : public WSCOM
{
private:
	WSCOM_sub(void);
	~WSCOM_sub(void);
public:
	static ws_result _real_WSGetModule(wsiComponentManager *aCompMgr, wsiFile* location, wsiModule** return_cobj);
};

