#pragma once

#include "wscObjectFinal.h"



template <typename T_indicator_ , typename T_super_>
class wscThrowableExTempl : public T_super_
{
public:

    typedef T_super_              t_super_class;
    typedef wscThrowableExTempl   t_this_class;

    static const ws_char * const s_class_name;

private:

	wscThrowableExTempl(const wscThrowableExTempl & src);
	const wscThrowableExTempl & operator = (const wscThrowableExTempl & src);

public:

    static wsiThrowable * New(const ws_char * const msg, const ws_char * const file, ws_int line)
    {
        return wscObjectFinal<wscThrowableExTempl>::NewForThrow(msg,file,line);
    }

    static ws_result Throw(const ws_char * const msg, const ws_char * const file, ws_int line)
    {
        return ThrowThrowable( new wscObjectFinal<t_this_class>(msg,file,line) );
    }

protected:

    wscThrowableExTempl(const ws_char * const msg, const ws_char * const file, ws_int line)
        : t_super_class(msg,file,line)
    {
    }

    ~wscThrowableExTempl(void)
    {
    }

};

