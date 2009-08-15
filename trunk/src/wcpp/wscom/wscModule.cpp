#include "wscModule.h"
#include "wsiFactory.h"
#include "wsiClassInfo.h"
#include "wsiComponentRegistrar.h"
#include "wsiComponentManager.h"


wscModule::wscModule(void)
{
}


wscModule::~wscModule(void)
{
}


void wscModule::GetCurrentModule(wsiModule ** ret)
{
    NewCurrentModule(ret);
}



	
ws_result wscModule::GetClassObject(wsiComponentManager * aCompMgr, const ws_cid & aCID, const ws_iid & aIID, void ** ret)
{
    ws_ptr<wsiFactory> fac;
    ws_result rlt = NewClassFactory( &fac , aCID );
    if (rlt != WS_RLT_SUCCESS) return rlt;
    return fac->QueryInterface( aIID , ret );
}


ws_result wscModule::RegisterSelf(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr, wsiString * aType)
{
    if (aCompMgr==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    ws_result rlt(0);

    ws_ptr<wsiComponentRegistrar> compReg;
    rlt = aCompMgr->QueryInterface( compReg.GetIID() , (void**)(&compReg) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    for (ws_int i=0; i>=0; i++) {

        ws_cid cid;
        rlt = IndexToClassId( cid , i );
        if (rlt != WS_RLT_SUCCESS) return WS_RLT_SUCCESS;

        ws_ptr<wsiFactory> factory;
        rlt = GetClassObject( aCompMgr, cid, factory.GetIID(), (void**)(&factory) );
        if (rlt==WS_RLT_SUCCESS) {

            ws_ptr<wsiClassInfo> clsInfo;
            rlt = factory.QueryInterface2( &clsInfo );
            if (rlt==WS_RLT_SUCCESS) {

                ws_ptr<wsiString> clsName;
                ws_ptr<wsiString> contractId;

                clsInfo->GetContractID( &contractId );
                clsInfo->GetClassDescription( &clsName );

                compReg->RegisterFactory( cid , clsName , contractId , factory );
                compReg->RegisterFactoryLocation( cid , clsName , contractId , aLocation , aLoaderStr , aType );
            }
        }
    }

    return WS_RLT_SUCCESS;
}


ws_result wscModule::UnregisterSelf(wsiComponentManager * aCompMgr, wsiFile * aLocation, wsiString * aLoaderStr)
{
    if (aCompMgr==WS_NULL) {
        return WS_RLT_NULL_POINTER;
    }

    ws_result rlt(0);

    ws_ptr<wsiComponentRegistrar> compReg;
    rlt = aCompMgr->QueryInterface( compReg.GetIID() , (void**)(&compReg) );
    if (rlt != WS_RLT_SUCCESS) return rlt;

    for (ws_int i=0; i>=0; i++) {

        ws_cid cid;
        rlt = IndexToClassId( cid , i );
        if (rlt != WS_RLT_SUCCESS) return WS_RLT_SUCCESS;

        ws_ptr<wsiFactory> factory;
        rlt = GetClassObject( aCompMgr, cid, factory.GetIID(), (void**)(&factory) );
        if (rlt==WS_RLT_SUCCESS) {

            ws_ptr<wsiClassInfo> clsInfo;
            rlt = factory.QueryInterface2( &clsInfo );
            if (rlt==WS_RLT_SUCCESS) {

                ws_ptr<wsiString> clsName;
                ws_ptr<wsiString> contractId;

                clsInfo->GetContractID( &contractId );
                clsInfo->GetClassDescription( &clsName );

                compReg->UnregisterFactory( cid , factory );
                compReg->UnregisterFactoryLocation( cid , aLocation );
            }
        }
    }

    return WS_RLT_SUCCESS;
}


ws_boolean wscModule::CanUnload(wsiComponentManager * aCompMgr)
{
    WS_THROW( wseUnsupportedOperationException , "" );
}



