#pragma once
#include <wcpp/lang/wsiObject.h>


class wsiFactory;
class wsiSimpleEnumerator;
class wsiFile;


#define WS_IID_OF_wsiComponentRegistrar		\
	{ 0xa0a78ab1, 0x2b37, 0x4829, { 0x80, 0x46, 0x72, 0x48, 0x74, 0x68, 0x24, 0xeb } }
// {A0A78AB1-2B37-4829-8046-7248746824EB}


class wsiComponentRegistrar : public wsiObject
{
public:
	static const ws_iid sIID;

public:

    WS_METHOD( ws_result,   AutoRegister               )( wsiFile * aSpec ) = 0;
    WS_METHOD( ws_result,   AutoUnregister             )( wsiFile * aSpec ) = 0;
    WS_METHOD( ws_result,   RegisterFactory            )( const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFactory * aFactory ) = 0;
    WS_METHOD( ws_result,   UnregisterFactory          )( const ws_cid & aClass, wsiFactory * aFactory ) = 0;
    WS_METHOD( ws_result,   RegisterFactoryLocation    )( const ws_cid & aClass, wsiString * aClassName, wsiString * aContractID, wsiFile * aFile, wsiString * aLoaderStr, wsiString * aType) = 0;
    WS_METHOD( ws_result,   UnregisterFactoryLocation  )( const ws_cid & aClass, wsiFile * aFile ) = 0;
    WS_METHOD( ws_boolean,  IsCIDRegistered            )( const ws_cid & aClass ) = 0;
    WS_METHOD( ws_boolean,  IsContractIDRegistered     )( wsiString * aContractID ) = 0;
    WS_METHOD( ws_result,   EnumerateCIDs              )( wsiSimpleEnumerator ** rEnum ) = 0;
    WS_METHOD( ws_result,   EnumerateContractIDs       )( wsiSimpleEnumerator ** rEnum ) = 0;
    WS_METHOD( ws_result,   CIDToContractID            )( const ws_cid & aClass, wsiString ** rContractID ) = 0;
    WS_METHOD( ws_result,   ContractIDToCID            )( wsiString * aContractID, ws_cid & rClass ) = 0;

};

