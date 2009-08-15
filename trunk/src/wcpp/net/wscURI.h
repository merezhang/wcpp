#pragma once

#include "wsiURI.h"
#include <wcpp/lang/wscObject.h>


class wscURI : public wscObject , public wsiURI
{
public:

    wscURI( wsiString * str );

    wscURI( wsiString * scheme,
            wsiString * ssp,
            wsiString * fragment );

    wscURI( wsiString * scheme,
            wsiString * userInfo,
            wsiString * host,
            ws_int port,
            wsiString * path,
            wsiString * query,
            wsiString * fragment );

    wscURI( wsiString * scheme,
            wsiString * host,
            wsiString * path,
            wsiString * fragment );

    wscURI( wsiString * scheme,
            wsiString * authority,
            wsiString * path,
            wsiString * query,
            wsiString * fragment );

};

