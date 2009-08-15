#pragma once
#include <wcpp/wscom/WSCOM.h>


class wsiDirectoryServiceProvider;


class WSCOM_main : public WSCOM
{
private:
	WSCOM_main(void);
	~WSCOM_main(void);

public:
    static ws_result Init     (wsiServiceManager ** result, wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider);
	static ws_result Shutdown (wsiServiceManager * servMgr);
;
};

