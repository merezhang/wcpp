#pragma once

#include <wcpp/wspr/wspr.h>


class wsiObject;


class wsuKey
{
private:
    wsiObject * m_object;
private:
public:
    wsuKey(const wsuKey & src);
    wsuKey(wsiObject * src);
    ~wsuKey(void);

    const wsuKey & operator = (const wsuKey & src);
    bool operator == (const wsuKey & other) const;
    operator long (void) const;
};


class wsuValue
{
private:
    wsiObject * m_object;
public:
    wsuValue(wsiObject * src);
    wsuValue(const wsuValue & src);
    ~wsuValue(void);
    const wsuValue & operator = (const wsuValue & src);
    ws_result CopyTo(wsiObject ** ret);
};

