// wscClass.h
#ifndef __wscClass_h__
#define __wscClass_h__

#include "wscObject.h"
#include "wsiClass.h"
#include "wsiString.h"


#define WS_ClassName_OF_wscClass        "wcpp.lang.wscClass"


class wscClass : public wscObject , public wsiClass
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( t_this_class )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiClass )
    WS_IMPL_QUERY_INTERFACE_END()

public:

    typedef wscObject     t_super_class;
    typedef wscClass      t_this_class;
    static const ws_char * const  s_class_name;

protected:

	wscClass(const ws_char* const aName);
	~wscClass(void);

protected:      // implements

    // wsiClass
	WS_METHOD( ws_result             , GetName )(wsiString ** rString);
    WS_METHOD( const ws_char * const , GetName )(void);

private:
	const ws_char* const m_name;
};





/*
typedef                   t_this_class;
typedef                   t_super_class;
static const ws_char * const     s_class_name;
static const ws_iid              sIID;
static const ws_cid              sCID;
static const ws_char * const     sContractID;
*/




#endif // __wscClass_h__
