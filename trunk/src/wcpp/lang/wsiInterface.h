// wsiInterface.h

#ifndef __wsiInterface_h__
#define __wsiInterface_h__

#include <wcpp/wspr/ws_id.h>


class wsiInterface
{
public:

    WS_VIRTUAL_DESTRUCTOR( wsiInterface ){}

	WS_METHOD( ws_int    , AddRef         )(void) = 0;
	WS_METHOD( ws_result , QueryInterface )(const ws_iid & iid, void ** ret) = 0;
	WS_METHOD( ws_int    , Release        )(void) = 0;

};


#endif // __wsiInterface_h__
