#include "wscAddressImplFactory_win32.h"
#include <wcpp/lang/wscThrowable.h>
#include "wscInet4Address_win32.h"
#if (WS_PLATFORM == WS_PLATFORM_WIN32) // (win32 platform begin)
#include <windows.h>


ws_result wscAddressImplFactory_win32::NameToAddress(wsiInetAddress ** ret, const ws_char * const name)
{
    hostent * pHostEnt = gethostbyname( name );
    if (pHostEnt == 0) {
        return WS_RLT_FAILED;
    }

    if ((pHostEnt->h_addrtype==2) && (pHostEnt->h_length==4)) {
        sockaddr_in addr;
        addr.sin_family  = AF_INET;
        addr.sin_port    = 0;
        addr.sin_zero[0] = 0;
        addr.sin_zero[1] = 0;
        addr.sin_zero[2] = 0;
        addr.sin_zero[3] = 0;
        addr.sin_zero[4] = 0;
        addr.sin_zero[5] = 0;
        addr.sin_zero[6] = 0;
        addr.sin_zero[7] = 0;
        char * pchr = pHostEnt->h_addr_list[0];
        addr.sin_addr.S_un.S_un_b.s_b1 = pchr[0];
        addr.sin_addr.S_un.S_un_b.s_b2 = pchr[1];
        addr.sin_addr.S_un.S_un_b.s_b3 = pchr[2];
        addr.sin_addr.S_un.S_un_b.s_b4 = pchr[3];
        wsiInet4Address * pinet4addr = WS_NULL;
        ws_result rlt = NewObj<wscInet4Address_win32>( & pinet4addr , addr );
        if (rlt != WS_RLT_SUCCESS) return rlt;
        *ret = pinet4addr;
        return WS_RLT_SUCCESS;
    }
    else {
        WS_THROW( wseUnsupportedOperationException , "" );
    }
}


ws_result wscAddressImplFactory_win32::GetByAddress(wsiInetAddress ** ret, const ws_byte * buf, ws_int cb)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    if (buf==WS_NULL) return WS_RLT_NULL_POINTER;
    if (cb == sizeof(sockaddr_in)) {
        sockaddr_in   i4addr;
        wspr::ws_memcpy( &i4addr , buf , sizeof(i4addr) );
        wsiInet4Address * pnew = WS_NULL;
        ws_result rlt = NewObj<wscInet4Address_win32>( &pnew , i4addr );
        *ret = pnew;
        return rlt;
    }
    else {
        return WS_RLT_FAILED;
    }
}


ws_result wscAddressImplFactory_win32::GetByName(wsiInetAddress ** ret, wsiString * host)
{
    if ((host==WS_NULL) || (ret==WS_NULL)) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    return NameToAddress( ret , host->GetBuffer() );
}


ws_result wscAddressImplFactory_win32::GetLocalHost(wsiInetAddress ** ret)
{
    if (ret==WS_NULL) return WS_RLT_NULL_POINTER;
    if (*ret) return WS_RLT_NULL_POINTER;
    return NameToAddress( ret , "localhost" );
}


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
