// test.utest.win32Doc.h : Ctestutestwin32Doc ��Ľӿ�
//


#pragma once


class Ctestutestwin32Doc : public CDocument
{
protected: // �������л�����
	Ctestutestwin32Doc();
	DECLARE_DYNCREATE(Ctestutestwin32Doc)

// ����
public:

// ����
public:

// ��д
public:
	WS_VIRTUAL BOOL OnNewDocument();
	WS_VIRTUAL void Serialize(CArchive& ar);

// ʵ��
public:
	WS_VIRTUAL_DESTRUCTOR( Ctestutestwin32Doc );
#ifdef _DEBUG
	WS_VIRTUAL void AssertValid() const;
	WS_VIRTUAL void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


