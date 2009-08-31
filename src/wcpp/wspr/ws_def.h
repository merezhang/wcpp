#pragma once

/*
    platform defines
*/

#define WS_PLATFORM_WIN32   1
#define WS_PLATFORM_MACOS   2
#define WS_PLATFORM_LINUX   3

#define WS_PLATFORM     WS_PLATFORM_WIN32



#define WS_DEBUG


/*
    util
*/


#define WS_MIN(a,b)         (( (a) < (b) ) ? (a) : (b) )
#define WS_MAX(a,b)         (( (a) < (b) ) ? (b) : (a) )


// define

#define WS_NULL		0
#define WS_TRUE		true
#define WS_FALSE	false

//    #define WS_CALLBACK		__cdecl
//    #define WS_EXPORT		



enum WS_RLT_x
{
    WS_RLT_SUCCESS,
    WS_RLT_FAILED,
    WS_RLT_ERROR,
    WS_RLT_EXCEPTION,

    WS_RLT_UNSUPPORTED_OPERATION,
    WS_RLT_NULL_POINTER,
    WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS,
    WS_RLT_ILLEGAL_STATE,
    WS_RLT_ILLEGAL_ARGUMENT,
    WS_RLT_CLASS_CAST,
    WS_RLT_CLASS_NOT_FOUND,
    WS_RLT_NEGATIVE_ARRAY_SIZE,
    WS_RLT_OUT_OF_MEMORY,

    WS_RLT_EOF,

};



/*
enum WS_THROW_x
{
    wseUnsupportedOperationException  = WS_RLT_UNSUPPORTED_OPERATION,
    wseNullPointerException           = WS_RLT_NULL_POINTER,
    ArrayIndexOutOfBoundsException = WS_RLT_ARRAY_INDEX_OUT_OF_BOUNDS,
    IllegalStateException          = WS_RLT_ILLEGAL_STATE,
    ClassCastException             = WS_RLT_CLASS_CAST,
    ClassNotFoundException         = WS_RLT_CLASS_NOT_FOUND,
    Error                          = WS_RLT_ERROR,
    NegativeArraySizeException     = WS_RLT_NEGATIVE_ARRAY_SIZE,
    OutOfMemoryError               = WS_RLT_OUT_OF_MEMORY,
};
*/



#define WS_METHOD( _return_type_ , _method_name_ )          virtual _return_type_  _method_name_ 


#define WS_VFUNC( _return_type_ , _method_name_ )          virtual _return_type_  _method_name_ 


#define WS_VIRTUAL_DESTRUCTOR( __class__ )              virtual ~__class__(void)


#define WS_VIRTUAL      virtual


#define WS_ASSERT( _expression_ )       if (!(_expression_)) { throw wspr::ws_assert(_expression_); }
#define NO_IMPL


