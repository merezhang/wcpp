#pragma once

#include <wcpp/wscom/wsiServiceManager.h>
#include <wcpp/lang/wscObject.h>


class TestSession
{
public:
    TestSession(void);
    ~TestSession(void);

private:
    ws_safe_ptr<wsiServiceManager> m_ServMgr;
};


