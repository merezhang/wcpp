#pragma once

#include "wscObject.h"
#include "wsiString.h"
#include "wscClass.h"
#include "wsiLangService.h"


#define WS_ClassName_OF_wscString       "wcpp.lang.wscString"


class wscString : public wscObject , public wsiStringRW
{
    WS_IMPL_QUERY_INTERFACE_BEGIN( wscString )
        WS_IMPL_QUERY_INTERFACE_BODY( wsiString )       // unsupported any of QI
    WS_IMPL_QUERY_INTERFACE_END()

public:     // profile

    typedef wscString      t_this_class;
    typedef wscObject      t_super_class;
    static const ws_char * const s_class_name;

protected:  // string service

    static void    GetStringService(wsiStringService ** ret);

public:     // static New(xxx)

    static void New(wsiString ** ret);
    static void New(wsiString ** ret, const ws_char * const src);
    static void New(wsiString ** ret, const ws_char * const buf, ws_int len);
    static void New(wsiStringRW ** ret, ws_int aSize, const ws_char * const buf, ws_int len);

    static void Allocate(wsiString ** ret);
    static void Allocate(wsiString ** ret, const ws_char * const src);
    static void Allocate(wsiString ** ret, const ws_char * const buf, ws_int len);
    static ws_int Allocate(wsiStringRW ** ret, ws_int aSize, const ws_char * const buf, ws_int len);

public:     // static functions

    static void CopyValueOf(ws_char * data, wsiString ** ret);                             // 返回指定数组中表示该字符序列的 String。 
    static void CopyValueOf(ws_char * data, ws_int count, wsiString ** ret);               // 返回指定数组中表示该字符序列的 String。 
    ////
    static void Format(wsiString ** ret, wsiLocale * l, wsiString * format, ... );         // 使用指定的语言环境、格式字符串和参数返回一个格式化字符串。 
    static void Format(wsiString ** ret, wsiString * format, ... );                        // 使用指定的格式字符串和参数返回一个格式化字符串。 
    ////
    static void ValueOf(ws_boolean b, wsiString ** ret);                                   // 返回 boolean 参数的字符串表示形式。 
    static void ValueOf(ws_char c, wsiString ** ret);                                      // 返回 char 参数的字符串表示形式。 
    static void ValueOf(ws_char * data, wsiString ** ret);                                 // 返回 char 数组参数的字符串表示形式。 
    static void ValueOf(ws_char * data, ws_int offset, ws_int count, wsiString ** ret);    // 返回 char 数组参数的特定子数组的字符串表示形式。 
    static void ValueOf(ws_double d, wsiString ** ret);                                    // 返回 double 参数的字符串表示形式。 
    static void ValueOf(ws_float f, wsiString ** ret);                                     // 返回 float 参数的字符串表示形式。 
    static void ValueOf(ws_int i, wsiString ** ret);                                       // 返回 int 参数的字符串表示形式。 
    static void ValueOf(ws_long l, wsiString ** ret);                                      // 返回 long 参数的字符串表示形式。 
    static void ValueOf(wsiObject * obj, wsiString ** ret);                                // 返回 Object 参数的字符串表示形式。 

protected:  // implements wsiString

    WS_METHOD( ws_char    , CharAt              )(ws_int index) const;                                           // 返回指定索引处的 ws_char 值。 
    WS_METHOD( ws_int     , CodePointAt         )(ws_int index) const;                                           // 返回指定索引处的字符（Unicode 代码点）。 
    WS_METHOD( ws_int     , CodePointBefore     )(ws_int index) const;                                           // 返回指定索引之前的字符（Unicode 代码点）。 
    WS_METHOD( ws_int     , CodePointCount      )(ws_int beginIndex, ws_int endIndex) const;                     // 返回此 String 的指定文本范围中的 Unicode 代码点数。 
    WS_METHOD( ws_int     , CompareTo           )(wsiString * anotherString) const;                              // 按字典顺序比较两个字符串。 
    WS_METHOD( ws_int     , CompareToIgnoreCase )(wsiString * str) const;                                        // 按字典顺序比较两个字符串，不考虑大小写。 
    WS_METHOD( ws_result  , Concat              )(wsiString ** ret, wsiString * str) const;                      // 将指定字符串连接到此字符串的结尾。 
    WS_METHOD( ws_boolean , Contains            )(wsiCharSequence * s) const;                                    // 当且仅当此字符串包含指定的 ws_char 值序列时，返回 true。 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiCharSequence * cs) const;                                   // 将此字符串与指定的 CharSequence 比较。 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiStringBuffer * sb) const;                                   // 将此字符串与指定的 StringBuffer 比较。 
    WS_METHOD( ws_boolean , EndsWith            )(wsiString * suffix) const;                                     // 测试此字符串是否以指定的后缀结束。 
    WS_METHOD( ws_boolean , Equals              )(wsiObject * anObject) const;                                   // 将此字符串与指定的对象比较。 
    WS_METHOD( ws_boolean , EqualsIgnoreCase    )(wsiString * anotherString) const;                              // 将此 wsiString * 与另一个 wsiString * 比较，不考虑大小写。 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret) const;                                    // 使用平台的默认字符集将此 wsiString * 编码为 byte 序列，并将结果存储到一个新的 byte 数组中。 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiCharset * charset) const;              // 使用给定的 charset 将此 wsiString * 编码到 byte 序列，并将结果存储到新的 byte 数组。 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiString * charsetName) const;           // 使用指定的字符集将此 wsiString * 编码为 byte 序列，并将结果存储到一个新的 byte 数组中。 
    WS_METHOD( ws_result  , GetChars            )(ws_int srcBegin, ws_int srcEnd, ws_char * dst, ws_int dstSize) const;    // 将字符从此字符串复制到目标字符数组。 
    WS_METHOD( ws_int     , HashCode            )(void) const;                                                   // 返回此字符串的哈希码。 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch) const;                                              // 返回指定字符在此字符串中第一次出现处的索引。 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch, ws_int fromIndex) const;                            // 返回在此字符串中第一次出现指定字符处的索引，从指定的索引开始搜索。 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str) const;                                        // 返回指定子字符串在此字符串中第一次出现处的索引。 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str, ws_int fromIndex) const;                      // 返回指定子字符串在此字符串中第一次出现处的索引，从指定的索引开始。 
    WS_METHOD( ws_result  , Intern              )(wsiString ** ret) const;                                       // 返回字符串对象的规范化表示形式。 
    WS_METHOD( ws_boolean , IsEmpty             )(void) const;                                                   // 当且仅当 length() 为 0 时返回 true。 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch) const;                                              // 返回指定字符在此字符串中最后一次出现处的索引。 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch, ws_int fromIndex) const;                            // 返回指定字符在此字符串中最后一次出现处的索引，从指定的索引处开始进行反向搜索。 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str) const;                                        // 返回指定子字符串在此字符串中最右边出现处的索引。 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str, ws_int fromIndex) const;                      // 返回指定子字符串在此字符串中最后一次出现处的索引，从指定的索引开始反向搜索。 
    WS_METHOD( ws_int     , Length              )(void) const;                                                   // 返回此字符串的长度。 
    WS_METHOD( ws_boolean , Matches             )(wsiString * regex) const;                                      // 告知此字符串是否匹配给定的正则表达式。 
    WS_METHOD( ws_int     , OffsetByCodePoints  )(ws_int index, ws_int codePointOffset) const;                   // 返回此 wsiString * 中从给定的 index 处偏移 codePointOffset 个代码点的索引。 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_boolean ignoreCase, ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const;    // 测试两个字符串区域是否相等。 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const;                           // 测试两个字符串区域是否相等。 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, ws_char oldChar, ws_char newChar) const;                                      // 返回一个新的字符串，它是通过用 newChar 替换此字符串中出现的所有 oldChar 得到的。 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, wsiCharSequence * target, wsiCharSequence * replacement) const;               // 使用指定的字面值替换序列替换此字符串所有匹配字面值目标序列的子字符串。 
    WS_METHOD( ws_result  , ReplaceAll          )(wsiString ** ret, wsiString * regex, wsiString * replacement) const;                            // 使用给定的 replacement 替换此字符串所有匹配给定的正则表达式的子字符串。 
    WS_METHOD( ws_result  , ReplaceFirst        )(wsiString ** ret, wsiString * regex, wsiString * replacement) const;       // 使用给定的 replacement 替换此字符串匹配给定的正则表达式的第一个子字符串。 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex) const;                           // 根据给定正则表达式的匹配拆分此字符串。 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex, ws_int limit) const;             // 根据匹配给定的正则表达式来拆分此字符串。 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix) const;                                                 // 测试此字符串是否以指定的前缀开始。 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix, ws_int toffset) const;                                 // 测试此字符串从指定索引开始的子字符串是否以指定前缀开始。 
    WS_METHOD( ws_result  , SubSequence         )(wsiCharSequence ** ret, ws_int beginIndex, ws_int endIndex) const;         // 返回一个新的字符序列，它是此序列的一个子序列。 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex) const;                                // 返回一个新的字符串，它是此字符串的一个子字符串。 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex, ws_int endIndex) const;               // 返回一个新字符串，它是此字符串的一个子字符串。 
    WS_METHOD( ws_result  , ToCharArray         )(wsiCharArray ** ret) const;                                                // 将此字符串转换为一个新的字符数组。 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret) const;                                                   // 使用默认语言环境的规则将此 wsiString * 中的所有字符都转换为小写。 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret, wsiLocale * locale) const;                               // 使用给定 Locale 的规则将此 wsiString * 中的所有字符都转换为小写。 
    WS_METHOD( ws_result  , ToString            )(wsiString ** ret) const;                                                   // 返回此对象本身（它已经是一个字符串！）。 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret) const;                                                   // 使用默认语言环境的规则将此 wsiString * 中的所有字符都转换为大写。 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret, wsiLocale * locale) const;                               // 使用给定 Locale 的规则将此 wsiString * 中的所有字符都转换为大写。 
    WS_METHOD( ws_result  , Trim                )(wsiString ** ret) const;                                                   // 返回字符串的副本，忽略前导空白和尾部空白。 

    // extends for wsiString
    WS_METHOD( const ws_char * const , GetBuffer )(void) const;
    WS_METHOD( ws_int                , GetLength )(void) const;

protected:  // implements wsiStringRW

    WS_METHOD( ws_char * , GetBufferRW   )(void);
    WS_METHOD( ws_int    , GetBufferSize )(void) const;
    WS_METHOD( ws_int    , SetLength     )(ws_int newLength);
    WS_METHOD( ws_int    , SetString     )(const ws_char * const buf, ws_int newLength);

protected:      // constructor / destructor / operator=

    wscString(void);
    wscString(const wscString & src);
    ~wscString(void);
    const wscString & operator=(const wscString & src);

protected:      // internal functions

    ws_int InternalHashCode(void);

private:    // data member

    struct _data_block
    {
        ws_byte * addr;
        ws_int    cap;
        ws_int    len;
        ws_char   buf[8];
    };

    _data_block *             m_pdb;
    ws_ptr<wsiStringService>  m_pStrServ;

    void InternalInit(wsiStringService * aStrServ, ws_int aSize);

};

