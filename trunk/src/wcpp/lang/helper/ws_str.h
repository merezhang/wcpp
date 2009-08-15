#pragma once

#include "ws_ptr.h"
#include <wcpp/lang/wsiString.h>


class ws_str
{
private:

    ws_ptr<wsiString> m_pstr;

public:

    ws_str(void);
    ws_str(wsiString * src);
    ws_str(const ws_char * const src);
    ws_str(const ws_char * const src, ws_int len);
    ws_str(const ws_str & src);
    ~ws_str(void);

public:

    const ws_str & operator = (const ws_str & src);

    operator wsiString * (void);
//    operator const ws_char * const (void) const;

    ws_boolean operator == (const ws_str & other) const;
    ws_boolean operator == (wsiString * other) const;
    ws_boolean operator == (const ws_char * const other) const;

    ws_boolean operator != (const ws_str & other) const;
    ws_boolean operator != (wsiString * other) const;
    ws_boolean operator != (const ws_char * const other) const;

    const ws_str & operator += (const ws_char * const add);
    const ws_str & operator += (const ws_str & add);
    const ws_str & operator += (const ws_char add);
    const ws_str & operator += (wsiString * add);

public:

    void CopyTo(wsiString ** ret);

    void SetString(const ws_char * const buf, ws_int len);
    ws_result Trim(wsiString ** ret);

};

