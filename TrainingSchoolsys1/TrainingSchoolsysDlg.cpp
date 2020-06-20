// TrainingSchoolsysDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TrainingSchoolsys.h"
#include "TrainingSchoolsysDlg.h"
#include "Dlg_login.h"
#include "RegisterDlg.h"
#include "PersonalINFODlg.h"
#include "LeaveMessageDlg.h"
#include "ReplyMessageDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainingSchoolsysDlg dialog

CTrainingSchoolsysDlg::CTrainingSchoolsysDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrainingSchoolsysDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrainingSchoolsysDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainingSchoolsysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrainingSchoolsysDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrainingSchoolsysDlg, CDialog)
	//{{AFX_MSG_MAP(CTrainingSchoolsysDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_DLG_LOGIN, OnDlgLogin)
	ON_COMMAND(ID_DLG_REGISTER, OnDlgRegister)
	ON_COMMAND(ID_MENU_PERSONALINFO, OnMenuPersonalinfo)
	ON_COMMAND(ID_MENU_MESSAGE, OnMenuMessage)
	ON_COMMAND(ID_MENU_REPLYMESSAGE, OnMenuReplymessage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainingSchoolsysDlg message handlers

BOOL CTrainingSchoolsysDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_Menu.LoadMenu(IDR_MENU);  
	SetMenu(&m_Menu); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrainingSchoolsysDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrainingSchoolsysDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrainingSchoolsysDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTrainingSchoolsysDlg::OnDlgLogin() 
{
	// TODO: Add your command handler code here
	CDlg_login dlg;
	dlg.DoModal();
}

void CTrainingSchoolsysDlg::OnDlgRegister() 
{
	// TODO: Add your command handler code here
	CRegisterDlg dlg;
	dlg.DoModal();
}

void CTrainingSchoolsysDlg::OnMenuPersonalinfo() 
{
	// TODO: Add your command handler code here
	CPersonalINFODlg dlg;
	dlg.DoModal();
}

void CTrainingSchoolsysDlg::OnMenuMessage() 
{
	// TODO: Add your command handler code here
	CLeaveMessageDlg dlg;
	dlg.DoModal();
}

void CTrainingSchoolsysDlg::OnMenuReplymessage() 
{
	// TODO: Add your command handler code here
	CReplyMessageDlg dlg;
	dlg.DoModal();
}
