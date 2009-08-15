#pragma once

#include "ws_type.h"


class ws_file_enumerator;


class ws_file
{
public:

    enum _file_flag {
        ff_ReturnFalse  = 0xffffffff,

        ff_IsDirectory  = 0x00000002,
        ff_IsFile       = 0x00000004,
        ff_IsHidden     = 0x00000008,

        ff_Create             = 0x00000100,
        ff_SharedRead         = 0x00000200,
        ff_ExclusiveReadWrite = 0x00000800,
    };

protected:
    ws_file(void);
public:
    static ws_file * Open(void);
    static ws_file * Open(const ws_char * const filename, const ws_uint32 flag);
public:
    WS_VIRTUAL_DESTRUCTOR( ws_file );
public:
    WS_VFUNC( ws_int,     Read        )(void * const buf, const ws_int cb) = 0;
    WS_VFUNC( void,       Write       )(const void * const buf, const ws_int cb) = 0;
    WS_VFUNC( void,       Flush       )(void) = 0;
    WS_VFUNC( void,       Close       )(void) = 0;
    WS_VFUNC( ws_boolean, IsAvailable )(void) = 0;
public:
    WS_VFUNC( ws_uint32,  GetFileFlag )(const ws_char * const path , const ws_uint32 mask ) const = 0;
    WS_VFUNC( ws_file_enumerator * , EnumerateFiles )(const ws_char * const path) const = 0;
};


class ws_file_enumerator
{
public:
    WS_VIRTUAL_DESTRUCTOR( ws_file_enumerator ) {}
public:
    WS_VFUNC( ws_boolean , HasMore )(void) = 0;
    WS_VFUNC( void ,       Next    )(void) = 0;
    WS_VFUNC( ws_int ,     GetName )(ws_char * b, ws_int len) = 0;

};

