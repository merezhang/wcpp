// test.utest.win32Doc.cpp : Ctestutestwin32Doc ���ʵ��
//

#include "stdafx.h"
#include "test.utest.win32.h"

#include "test.utest.win32Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestutestwin32Doc

IMPLEMENT_DYNCREATE(Ctestutestwin32Doc, CDocument)

BEGIN_MESSAGE_MAP(Ctestutestwin32Doc, CDocument)
END_MESSAGE_MAP()


// Ctestutestwin32Doc ����/����

Ctestutestwin32Doc::Ctestutestwin32Doc()
{
	// TODO: �ڴ����һ���Թ������

}

Ctestutestwin32Doc::~Ctestutestwin32Doc()
{
}

BOOL Ctestutestwin32Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Ctestutestwin32Doc ���л�

void Ctestutestwin32Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// Ctestutestwin32Doc ���

#ifdef _DEBUG
void Ctestutestwin32Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ctestutestwin32Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ctestutestwin32Doc ����
