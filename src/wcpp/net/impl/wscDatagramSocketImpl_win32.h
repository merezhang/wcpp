#pragma once

#include <wcpp/net/wscDatagramSocketImpl.h>
#if (WS_PLATFORM == WS_PLATFORM_WIN32)
#include <windows.h>


class wscDatagramSocketImpl_win32 : public wscDatagramSocketImpl
{
public:
    static const ws_char * const s_class_name;
public:
    wscDatagramSocketImpl_win32(void);
    ~wscDatagramSocketImpl_win32(void);

private:
    SOCKET m_socket;

protected:      // impl wsiSocketOpetions
    WS_METHOD( ws_result , GetOption )(wsiObject ** ret , ws_int optID);
    WS_METHOD( ws_result , SetOption )(ws_int optID , wsiObject * value);

protected:      // impl wsiDatagramSocketImpl
    WS_METHOD( ws_result , Bind              )(ws_int lport , wsiInetAddress * laddr);
    WS_METHOD( ws_result , Close             )(void);
    WS_METHOD( ws_result , Connect           )(wsiInetAddress * address , ws_int port);
    WS_METHOD( ws_result , Create            )(void);
    WS_METHOD( ws_result , Disconnect        )(void);
    WS_METHOD( ws_result , GetFileDescriptor )(wsiFileDescriptor ** ret);
    WS_METHOD( ws_int    , GetLocalPort      )(void);
    WS_METHOD( ws_int    , GetTimeToLive     )(void);
    WS_METHOD( ws_result , Join              )(wsiInetAddress * inetaddr);
    WS_METHOD( ws_result , JoinGroup         )(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf);
    WS_METHOD( ws_result , Leave             )(wsiInetAddress * inetaddr);
    WS_METHOD( ws_result , LeaveGroup        )(wsiSocketAddress * mcastaddr , wsiNetworkInterface * netIf);
    WS_METHOD( ws_int    , Peek              )(wsiInetAddress * i);
    WS_METHOD( ws_int    , PeekData          )(wsiDatagramPacket * p);
    WS_METHOD( ws_result , Receive           )(wsiDatagramPacket * p);
    WS_METHOD( ws_result , Send              )(wsiDatagramPacket * p);
    WS_METHOD( ws_result , SetTimeToLive     )(ws_int ttl);

};


#endif // (WS_PLATFORM == WS_PLATFORM_WIN32)
