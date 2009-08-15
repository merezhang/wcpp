#include "wscGlobalManager.h"
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/io/wscFile.h>
#include "wscModuleManager.h"
#include "wscMainModule.h"


wsiGlobalManager * wscGlobalManager::s_Instance = WS_NULL;


ws_result wscGlobalManager::GetGlobalManager(wsiGlobalManager ** ret)
{
    ws_ptr<wsiGlobalManager> tmp(s_Instance);
    if (!tmp) {
        return WS_RLT_ILLEGAL_STATE;
    }
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


wscGlobalManager::wscGlobalManager(void)
{
    s_Instance = this;
}


wscGlobalManager::~wscGlobalManager(void)
{
    s_Instance = WS_NULL;
}



ws_result wscGlobalManager::GetComponentManager(wsiComponentManager ** ret)
{
    ws_ptr<wsiComponentManager> tmp(this);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscGlobalManager::GetComponentRegistrar(wsiComponentRegistrar ** ret)
{
    ws_ptr<wsiComponentRegistrar> tmp(this);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscGlobalManager::GetServiceManager(wsiServiceManager ** ret)
{
    ws_ptr<wsiServiceManager> tmp(this);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscGlobalManager::GetMemoryManager(wsiMemory ** ret)
{
    ws_ptr<wsiMemory> tmp(this);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


ws_result wscGlobalManager::GetModuleManager(wsiModuleManager ** ret)
{
    ws_ptr<wsiModuleManager> tmp(this);
    tmp.CopyTo( ret );
    return WS_RLT_SUCCESS;
}


void wscGlobalManager::FinalConstruct()
{
    t_super_class::FinalConstruct();
}


ws_result wscGlobalManager::StartGM(wsiFile * binDirectory, wsiDirectoryServiceProvider * appFileLocationProvider)
{
    _StartMemoryManager();
    _StartComponentRegistrar();
    _StartComponentManager();
    _StartServiceManager();

    // reg main-module self
    ws_ptr<wsiModule> mod;
    wscMainModule::GetCurrentModule( &mod );
    mod->RegisterSelf( this , WS_NULL , WS_NULL , WS_NULL );

    ws_ptr<wsiFile> pfile;
    if (binDirectory==WS_NULL) {
        ws_str path( "./" );
        wscFile::New( &pfile , path );
        binDirectory = pfile;
    }

    ws_result rlt = LoadRegInfo( appFileLocationProvider );
    if (rlt != WS_RLT_SUCCESS) {
        // 加载注册信息失败，开始执行组件搜索并注册的过程
        AutoRegister( binDirectory );
        SaveRegInfo( appFileLocationProvider );
    }

    return WS_RLT_SUCCESS;
}


ws_result wscGlobalManager::StopGM(void)
{
    _StopServiceManager();
    _StopComponentManager();
    _StopComponentRegistrar();
    _StopMemoryManager();

    return WS_RLT_SUCCESS;
}

