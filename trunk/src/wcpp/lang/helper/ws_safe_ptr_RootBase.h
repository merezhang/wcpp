#pragma once

#include <wcpp/wspr/ws_type.h>
#include <wcpp/wspr/wsuMutex.h>


class wsiInterface;


class ws_safe_ptr_RootBase
{
private:        // copy disable
    ws_safe_ptr_RootBase(const ws_safe_ptr_RootBase &);
    const ws_safe_ptr_RootBase & operator=(const ws_safe_ptr_RootBase & );

protected:      // create by extends classes
    ws_safe_ptr_RootBase(void);
    ~ws_safe_ptr_RootBase(void);

protected:      // called by extends classes

    static void ThrowNullPointerException(const ws_char * const msg, const ws_char * const file, ws_int line);
    static void SwapPtr(void ** pp1 , void ** pp2);

};

