#pragma once

#include "ws_ptr.h"
#include <wcpp/lang/wsiString.h>


class ws_str_buffer
{
private:

    ws_ptr<wsiStringRW> m_pstr;

public:
    ws_str_buffer(void);
    ~ws_str_buffer(void);

public:
    const ws_str_buffer & operator += (wsiString * src);
    const ws_str_buffer & operator += (const ws_char * const src);
    const ws_str_buffer & operator += (ws_char chr);
    operator const ws_char * const (void);
    operator wsiStringRW * (void);
    bool operator != (const ws_char * const str) const;

public:

    ws_int            SetLength(ws_int newLength);
    ws_int            ExtendBufferSize(ws_int newSize);
    ws_int            GetBufferSize(void) const;
    ws_char *         GetBufferRW(void);
    const ws_char *   GetBuffer(void) const;
    ws_int            GetLength(void) const;

private:

    void AddString(const ws_char * const buf, ws_int len);
};


