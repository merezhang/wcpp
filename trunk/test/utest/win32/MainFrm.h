// MainFrm.h : CMainFrame ��Ľӿ�
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	WS_VFUNC( BOOL , PreCreateWindow )(CREATESTRUCT& cs);

// ʵ��
public:
	WS_VIRTUAL_DESTRUCTOR( CMainFrame );
#ifdef _DEBUG
	WS_VFUNC( void , AssertValid )() const;
	WS_VFUNC( void , Dump )(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

    TestSession m_TestSession;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};


