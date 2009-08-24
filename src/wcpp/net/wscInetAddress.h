#pragma once

#include "wsiInetAddress.h"
#include <wcpp/lang/wscObject.h>


class wscInetAddress : public wscObject , public wsiInetAddress
{
public:
    wscInetAddress(void);
    ~wscInetAddress(void);

public: // static

    static ws_result  GetAllByName (wsiArray<wsiInetAddress> ** ret, wsiString * host);
    static ws_result  GetByAddress (wsiInetAddress ** ret, wsiByteArray * host);
    static ws_result  GetByAddress (wsiInetAddress ** ret, const ws_byte * buf, ws_int cb);
    static ws_result  GetByAddress (wsiInetAddress ** ret, wsiString * host, wsiByteArray * addr);
    static ws_result  GetByName    (wsiInetAddress ** ret, wsiString * host);
    static ws_result  GetLocalHost (wsiInetAddress ** ret);

};

