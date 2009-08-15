#ifndef __wscMainModule_h__
#define __wscMainModule_h__

#include <wcpp/wscom/wscModule.h>


class wscMainModule : public wscModule
{
public:
    static const ws_char * const s_class_name;
public:
	wscMainModule(void);
	~wscMainModule(void);

protected:

    WS_VFUNC( ws_result , IndexToClassId  )(ws_cid & ret , ws_int index);
    WS_VFUNC( ws_result , NewClassFactory )(wsiFactory ** ret , const ws_cid & aClass);

};


#endif // __wscMainModule_h__
