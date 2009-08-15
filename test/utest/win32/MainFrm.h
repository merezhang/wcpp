// MainFrm.h : CMainFrame 类的接口
//


#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 仅从序列化创建
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 属性
public:

// 操作
public:

// 重写
public:
	WS_VFUNC( BOOL , PreCreateWindow )(CREATESTRUCT& cs);

// 实现
public:
	WS_VIRTUAL_DESTRUCTOR( CMainFrame );
#ifdef _DEBUG
	WS_VFUNC( void , AssertValid )() const;
	WS_VFUNC( void , Dump )(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;

    TestSession m_TestSession;

// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
};


