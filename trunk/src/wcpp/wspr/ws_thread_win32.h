#include "ws_thread.h"
#include <windows.h>


class ws_thread_win32 : public ws_thread
{
public:
    ws_thread_win32(HANDLE hThread, DWORD dwThreadId);
    ~ws_thread_win32(void);

	WS_VFUNC(ws_int,GetPriority)(void);

private:
    HANDLE m_hThread;
    DWORD  m_dwThreadId;
};

