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

    static void CopyValueOf(ws_char * data, wsiString ** ret);                             // ����ָ�������б�ʾ���ַ����е� String�� 
    static void CopyValueOf(ws_char * data, ws_int count, wsiString ** ret);               // ����ָ�������б�ʾ���ַ����е� String�� 
    ////
    static void Format(wsiString ** ret, wsiLocale * l, wsiString * format, ... );         // ʹ��ָ�������Ի�������ʽ�ַ����Ͳ�������һ����ʽ���ַ����� 
    static void Format(wsiString ** ret, wsiString * format, ... );                        // ʹ��ָ���ĸ�ʽ�ַ����Ͳ�������һ����ʽ���ַ����� 
    ////
    static void ValueOf(ws_boolean b, wsiString ** ret);                                   // ���� boolean �������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_char c, wsiString ** ret);                                      // ���� char �������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_char * data, wsiString ** ret);                                 // ���� char ����������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_char * data, ws_int offset, ws_int count, wsiString ** ret);    // ���� char ����������ض���������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_double d, wsiString ** ret);                                    // ���� double �������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_float f, wsiString ** ret);                                     // ���� float �������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_int i, wsiString ** ret);                                       // ���� int �������ַ�����ʾ��ʽ�� 
    static void ValueOf(ws_long l, wsiString ** ret);                                      // ���� long �������ַ�����ʾ��ʽ�� 
    static void ValueOf(wsiObject * obj, wsiString ** ret);                                // ���� Object �������ַ�����ʾ��ʽ�� 

protected:  // implements wsiString

    WS_METHOD( ws_char    , CharAt              )(ws_int index) const;                                           // ����ָ���������� ws_char ֵ�� 
    WS_METHOD( ws_int     , CodePointAt         )(ws_int index) const;                                           // ����ָ�����������ַ���Unicode ����㣩�� 
    WS_METHOD( ws_int     , CodePointBefore     )(ws_int index) const;                                           // ����ָ������֮ǰ���ַ���Unicode ����㣩�� 
    WS_METHOD( ws_int     , CodePointCount      )(ws_int beginIndex, ws_int endIndex) const;                     // ���ش� String ��ָ���ı���Χ�е� Unicode ��������� 
    WS_METHOD( ws_int     , CompareTo           )(wsiString * anotherString) const;                              // ���ֵ�˳��Ƚ������ַ����� 
    WS_METHOD( ws_int     , CompareToIgnoreCase )(wsiString * str) const;                                        // ���ֵ�˳��Ƚ������ַ����������Ǵ�Сд�� 
    WS_METHOD( ws_result  , Concat              )(wsiString ** ret, wsiString * str) const;                      // ��ָ���ַ������ӵ����ַ����Ľ�β�� 
    WS_METHOD( ws_boolean , Contains            )(wsiCharSequence * s) const;                                    // ���ҽ������ַ�������ָ���� ws_char ֵ����ʱ������ true�� 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiCharSequence * cs) const;                                   // �����ַ�����ָ���� CharSequence �Ƚϡ� 
    WS_METHOD( ws_boolean , ContentEquals       )(wsiStringBuffer * sb) const;                                   // �����ַ�����ָ���� StringBuffer �Ƚϡ� 
    WS_METHOD( ws_boolean , EndsWith            )(wsiString * suffix) const;                                     // ���Դ��ַ����Ƿ���ָ���ĺ�׺������ 
    WS_METHOD( ws_boolean , Equals              )(wsiObject * anObject) const;                                   // �����ַ�����ָ���Ķ���Ƚϡ� 
    WS_METHOD( ws_boolean , EqualsIgnoreCase    )(wsiString * anotherString) const;                              // ���� wsiString * ����һ�� wsiString * �Ƚϣ������Ǵ�Сд�� 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret) const;                                    // ʹ��ƽ̨��Ĭ���ַ������� wsiString * ����Ϊ byte ���У���������洢��һ���µ� byte �����С� 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiCharset * charset) const;              // ʹ�ø����� charset ���� wsiString * ���뵽 byte ���У���������洢���µ� byte ���顣 
    WS_METHOD( ws_result  , GetBytes            )(wsiByteArray ** ret, wsiString * charsetName) const;           // ʹ��ָ�����ַ������� wsiString * ����Ϊ byte ���У���������洢��һ���µ� byte �����С� 
    WS_METHOD( ws_result  , GetChars            )(ws_int srcBegin, ws_int srcEnd, ws_char * dst, ws_int dstSize) const;    // ���ַ��Ӵ��ַ������Ƶ�Ŀ���ַ����顣 
    WS_METHOD( ws_int     , HashCode            )(void) const;                                                   // ���ش��ַ����Ĺ�ϣ�롣 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch) const;                                              // ����ָ���ַ��ڴ��ַ����е�һ�γ��ִ��������� 
    WS_METHOD( ws_int     , IndexOf             )(ws_int ch, ws_int fromIndex) const;                            // �����ڴ��ַ����е�һ�γ���ָ���ַ�������������ָ����������ʼ������ 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str) const;                                        // ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ��������� 
    WS_METHOD( ws_int     , IndexOf             )(wsiString * str, ws_int fromIndex) const;                      // ����ָ�����ַ����ڴ��ַ����е�һ�γ��ִ�����������ָ����������ʼ�� 
    WS_METHOD( ws_result  , Intern              )(wsiString ** ret) const;                                       // �����ַ�������Ĺ淶����ʾ��ʽ�� 
    WS_METHOD( ws_boolean , IsEmpty             )(void) const;                                                   // ���ҽ��� length() Ϊ 0 ʱ���� true�� 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch) const;                                              // ����ָ���ַ��ڴ��ַ��������һ�γ��ִ��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(ws_int ch, ws_int fromIndex) const;                            // ����ָ���ַ��ڴ��ַ��������һ�γ��ִ�����������ָ������������ʼ���з��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str) const;                                        // ����ָ�����ַ����ڴ��ַ��������ұ߳��ִ��������� 
    WS_METHOD( ws_int     , LastIndexOf         )(wsiString * str, ws_int fromIndex) const;                      // ����ָ�����ַ����ڴ��ַ��������һ�γ��ִ�����������ָ����������ʼ���������� 
    WS_METHOD( ws_int     , Length              )(void) const;                                                   // ���ش��ַ����ĳ��ȡ� 
    WS_METHOD( ws_boolean , Matches             )(wsiString * regex) const;                                      // ��֪���ַ����Ƿ�ƥ�������������ʽ�� 
    WS_METHOD( ws_int     , OffsetByCodePoints  )(ws_int index, ws_int codePointOffset) const;                   // ���ش� wsiString * �дӸ����� index ��ƫ�� codePointOffset �������������� 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_boolean ignoreCase, ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const;    // ���������ַ��������Ƿ���ȡ� 
    WS_METHOD( ws_boolean , RegionMatches       )(ws_int toffset, wsiString * other, ws_int ooffset, ws_int len) const;                           // ���������ַ��������Ƿ���ȡ� 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, ws_char oldChar, ws_char newChar) const;                                      // ����һ���µ��ַ���������ͨ���� newChar �滻���ַ����г��ֵ����� oldChar �õ��ġ� 
    WS_METHOD( ws_result  , Replace             )(wsiString ** ret, wsiCharSequence * target, wsiCharSequence * replacement) const;               // ʹ��ָ��������ֵ�滻�����滻���ַ�������ƥ������ֵĿ�����е����ַ����� 
    WS_METHOD( ws_result  , ReplaceAll          )(wsiString ** ret, wsiString * regex, wsiString * replacement) const;                            // ʹ�ø����� replacement �滻���ַ�������ƥ�������������ʽ�����ַ����� 
    WS_METHOD( ws_result  , ReplaceFirst        )(wsiString ** ret, wsiString * regex, wsiString * replacement) const;       // ʹ�ø����� replacement �滻���ַ���ƥ�������������ʽ�ĵ�һ�����ַ����� 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex) const;                           // ���ݸ���������ʽ��ƥ���ִ��ַ����� 
    WS_METHOD( ws_result  , Split               )(wsiStringArray ** ret, wsiString * regex, ws_int limit) const;             // ����ƥ�������������ʽ����ִ��ַ����� 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix) const;                                                 // ���Դ��ַ����Ƿ���ָ����ǰ׺��ʼ�� 
    WS_METHOD( ws_boolean , StartsWith          )(wsiString * prefix, ws_int toffset) const;                                 // ���Դ��ַ�����ָ��������ʼ�����ַ����Ƿ���ָ��ǰ׺��ʼ�� 
    WS_METHOD( ws_result  , SubSequence         )(wsiCharSequence ** ret, ws_int beginIndex, ws_int endIndex) const;         // ����һ���µ��ַ����У����Ǵ����е�һ�������С� 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex) const;                                // ����һ���µ��ַ��������Ǵ��ַ�����һ�����ַ����� 
    WS_METHOD( ws_result  , Substring           )(wsiString ** ret, ws_int beginIndex, ws_int endIndex) const;               // ����һ�����ַ��������Ǵ��ַ�����һ�����ַ����� 
    WS_METHOD( ws_result  , ToCharArray         )(wsiCharArray ** ret) const;                                                // �����ַ���ת��Ϊһ���µ��ַ����顣 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret) const;                                                   // ʹ��Ĭ�����Ի����Ĺ��򽫴� wsiString * �е������ַ���ת��ΪСд�� 
    WS_METHOD( ws_result  , ToLowerCase         )(wsiString ** ret, wsiLocale * locale) const;                               // ʹ�ø��� Locale �Ĺ��򽫴� wsiString * �е������ַ���ת��ΪСд�� 
    WS_METHOD( ws_result  , ToString            )(wsiString ** ret) const;                                                   // ���ش˶��������Ѿ���һ���ַ��������� 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret) const;                                                   // ʹ��Ĭ�����Ի����Ĺ��򽫴� wsiString * �е������ַ���ת��Ϊ��д�� 
    WS_METHOD( ws_result  , ToUpperCase         )(wsiString ** ret, wsiLocale * locale) const;                               // ʹ�ø��� Locale �Ĺ��򽫴� wsiString * �е������ַ���ת��Ϊ��д�� 
    WS_METHOD( ws_result  , Trim                )(wsiString ** ret) const;                                                   // �����ַ����ĸ���������ǰ���հ׺�β���հס� 

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

