#pragma once
#include <wcpp/lang/wscObject.h>
#include "wsiComponentRegistrarEx.h"


class wsiDirectoryServiceProvider;


class wscComponentRegistrar : public wsiComponentRegistrar
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscComponentRegistrar )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiComponentRegistrar )
    WS_IMPL_QUERY_INTERFACE_END()
public:

    static const ws_char * const s_class_name;

public:

	wscComponentRegistrar(void);
	~wscComponentRegistrar(void);

protected:

    WS_METHOD( ws_result,   AutoRegister               )( wsiFile * aSpec );
    WS_METHOD( ws_result,   AutoUnregister             )( wsiFile * aSpec );
    WS_METHOD( ws_result,   RegisterFactory            )( const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFactory * aFactory );
    WS_METHOD( ws_result,   UnregisterFactory          )( const ws_cid & aClass, wsiFactory * aFactory );
    WS_METHOD( ws_result,   RegisterFactoryLocation    )( const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFile * aFile, wsiString * aLoaderStr, wsiString * aType);
    WS_METHOD( ws_result,   UnregisterFactoryLocation  )( const ws_cid & aClass, wsiFile * aFile );
    WS_METHOD( ws_boolean,  IsCIDRegistered            )( const ws_cid & aClass );
    WS_METHOD( ws_boolean,  IsContractIDRegistered     )( wsiString * aContractID );
    WS_METHOD( ws_result,   EnumerateCIDs              )( wsiSimpleEnumerator ** rEnum );
    WS_METHOD( ws_result,   EnumerateContractIDs       )( wsiSimpleEnumerator ** rEnum );
    WS_METHOD( ws_result,   CIDToContractID            )( const ws_cid & aClass, wsiString ** rContractID );
    WS_METHOD( ws_result,   ContractIDToCID            )( wsiString * aContractID, ws_cid & rClass );


    void _StartComponentRegistrar(void);
    void _StopComponentRegistrar(void);

private:
    ws_result AutoRegisterDir( wsiFile * aSpec );
    ws_result AutoRegisterFile( wsiFile * aSpec );

private:
    ws_boolean m_started;
    ws_boolean m_stopped;

};

