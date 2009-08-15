// test.utest.win32.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "test.utest.win32.h"
#include "MainFrm.h"

#include "test.utest.win32Doc.h"
#include "test.utest.win32View.h"
#include "utOutputStream.h"
#include <utest/WcppUnitTest.h>
#include <wcpp/lang/wscThrowable.h>
#include <wcpp/lang/wscSystem.h>
#include <wcpp/io/wsiPrintStream.h>
#include <wcpp/wscom/main/WSCOM_main.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ctestutestwin32App

BEGIN_MESSAGE_MAP(Ctestutestwin32App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Ctestutestwin32App::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
    ON_COMMAND(ID_TEST_RUNUNITTEST, &Ctestutestwin32App::OnTestRununittest)
END_MESSAGE_MAP()


// Ctestutestwin32App 构造

Ctestutestwin32App::Ctestutestwin32App()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中

//    utOutputStream::Init();

}


// 唯一的一个 Ctestutestwin32App 对象

Ctestutestwin32App theApp;


// Ctestutestwin32App 初始化

BOOL Ctestutestwin32App::InitInstance()
{


	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Ctestutestwin32Doc),
		RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
		RUNTIME_CLASS(Ctestutestwin32View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// 唯一的一个窗口已初始化，因此显示它并对其进行更新
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 SDI 应用程序中，这应在 ProcessShellCommand  之后发生
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	WS_VIRTUAL void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void Ctestutestwin32App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Ctestutestwin32App 消息处理程序


void Ctestutestwin32App_test_main(void)
{
//    _CrtSetBreakAlloc( 500 );


//    for (ws_long i=1; i<=1; i++) {

        /*
        ws_ptr<wsiPrintStream> ps;
        wscSystem::GetOut( & ps );
        ps->PrintLn();
        ps->PrintLn();
        ps->PrintLn( "================================================================================================================================" );
        ps->Print( "reload test_main() " );
        ps->Print( i );
        ps->PrintLn( " times." );
        ps->PrintLn();
        ps->PrintLn();
        */

        test_main();
  //  }



}


void Ctestutestwin32App::OnTestRununittest()
{
//    const ws_boolean showExceptionDialog = WS_TRUE;
    const ws_boolean showExceptionDialog = WS_FALSE;

    if (!showExceptionDialog) {
        Ctestutestwin32App_test_main();
        return;
    }

    try {
        if (showExceptionDialog) {
            Ctestutestwin32App_test_main();
            return;
        }
    }
    catch (ws_result /*e*/) {
        /*
        ws_str str, msg;
        wsiThrowable * pe = &e;
        pe->GetMessage( &msg );
        pe->ToString( &str );

        CString cstr( str->GetBuffer() , str->GetLength() );
        CString cmsg( msg->GetBuffer() , msg->GetLength() );
        CString fln( e.GetSourceFileName() );
        CString strLN;  strLN.Format( "Line:%d", e.GetLineNumber() );
        AfxMessageBox(
            cstr  + "\n\n" + 
            cmsg  + "\n\n" + 
            fln   + "\n\n" + 
            strLN + "\n\n" );
        return;
        */
    }
}

