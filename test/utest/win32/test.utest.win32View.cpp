// test.utest.win32View.cpp : Ctestutestwin32View ���ʵ��
//

#include "stdafx.h"
#include "test.utest.win32.h"

#include "test.utest.win32Doc.h"
#include "test.utest.win32View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestutestwin32View

IMPLEMENT_DYNCREATE(Ctestutestwin32View, CView)

BEGIN_MESSAGE_MAP(Ctestutestwin32View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ctestutestwin32View ����/����

Ctestutestwin32View::Ctestutestwin32View()
{
	// TODO: �ڴ˴���ӹ������

}

Ctestutestwin32View::~Ctestutestwin32View()
{
}

BOOL Ctestutestwin32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ctestutestwin32View ����

void Ctestutestwin32View::OnDraw(CDC* /*pDC*/)
{
	Ctestutestwin32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ctestutestwin32View ��ӡ

BOOL Ctestutestwin32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ctestutestwin32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ctestutestwin32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Ctestutestwin32View ���

#ifdef _DEBUG
void Ctestutestwin32View::AssertValid() const
{
	CView::AssertValid();
}

void Ctestutestwin32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ctestutestwin32Doc* Ctestutestwin32View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ctestutestwin32Doc)));
	return (Ctestutestwin32Doc*)m_pDocument;
}
#endif //_DEBUG


// Ctestutestwin32View ��Ϣ�������
