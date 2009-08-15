#pragma once


template <typename T_indicator_ , typename T_super_>
class wscThrowableRoot : public T_super_
{
public:

    typedef T_super_            t_super_class;
    typedef wscThrowableTempl   t_this_class;

//    static const ws_char* const sSTR;
    static const ws_char * const s_class_name;

private:

	wscThrowableTempl(const wscThrowableTempl & src);
	const wscThrowableTempl & operator = (const wscThrowableTempl & src);

public:

protected:

    wscThrowableTempl(void)
    {
    }

    ~wscThrowableTempl(void)
    {
    }

};

