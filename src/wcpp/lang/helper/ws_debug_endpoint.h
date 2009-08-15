#pragma once


class ws_debug_probe;
class wsiObject;


class ws_debug_endpoint
{
private:
    ws_debug_probe * m_probe;
public:
    ws_debug_endpoint(void);
    ~ws_debug_endpoint(void);
    wsiObject * SelectTarget(wsiObject *);
};

