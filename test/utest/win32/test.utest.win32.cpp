// test.utest.win32.cpp : ����Ӧ�ó��������Ϊ��
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
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// ��׼��ӡ��������
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
    ON_COMMAND(ID_TEST_RUNUNITTEST, &Ctestutestwin32App::OnTestRununittest)
END_MESSAGE_MAP()


// Ctestutestwin32App ����

Ctestutestwin32App::Ctestutestwin32App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��

//    utOutputStream::Init();

}


// Ψһ��һ�� Ctestutestwin32App ����

Ctestutestwin32App theApp;


// Ctestutestwin32App ��ʼ��

BOOL Ctestutestwin32App::InitInstance()
{


	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ��(���� MRU)
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Ctestutestwin32Doc),
		RUNTIME_CLASS(CMainFrame),       // �� SDI ��ܴ���
		RUNTIME_CLASS(Ctestutestwin32View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);



	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);


	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// Ψһ��һ�������ѳ�ʼ���������ʾ����������и���
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� SDI Ӧ�ó����У���Ӧ�� ProcessShellCommand  ֮����
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	WS_VIRTUAL void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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

// �������жԻ����Ӧ�ó�������
void Ctestutestwin32App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// Ctestutestwin32App ��Ϣ�������


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

