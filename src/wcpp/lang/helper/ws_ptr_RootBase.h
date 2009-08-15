#pragma once

#include <wcpp/wspr/ws_id.h>
#include <wcpp/wspr/wspr.h>


class wsiString;
class wsiObject;


class ws_ptr_RootBase
{
protected:
    ws_ptr_RootBase(void);
    ~ws_ptr_RootBase(void);

private:
    ws_ptr_RootBase(const ws_ptr_RootBase & src);
    const ws_ptr_RootBase & operator = (const ws_ptr_RootBase & src);

protected:

    static void ThrowNullPointerException(const ws_char * const msg, const ws_char * const file, ws_int line);

};

