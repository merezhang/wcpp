#pragma once
#include <wcpp/net/wscNetworkLibrary.h>


class wscNetworkLibraryImpl : public wscNetworkLibrary
{
public:
    class t_factory : public wscFactory
    {
    public:
        t_factory(void);
        ~t_factory(void);
        static const ws_char * const s_class_name;
    	WS_METHOD( ws_result , CreateInstance )(wsiObject * aOuter, const ws_iid & aIID, void ** ret);
    };

protected:
    
    wscNetworkLibraryImpl(void);
    ~wscNetworkLibraryImpl(void);

};

