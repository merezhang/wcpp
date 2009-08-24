// sub.network.win32.cpp : 定义 DLL 应用程序的入口点。
//

#include "stdafx.h"
#include <Winsock2.h>


#ifdef _MANAGED
#pragma managed(push, off)
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
    static bool sNoInit = true;
    if (sNoInit) {
        sNoInit = false;
        WSADATA wsaData;
        WORD wVersionRequested = MAKEWORD( 2, 2 );
        int err = WSAStartup( wVersionRequested, &wsaData );
    }

    return TRUE;
}

#ifdef _MANAGED
#pragma managed(pop)
#endif

