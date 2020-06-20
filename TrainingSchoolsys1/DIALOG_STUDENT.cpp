// DIALOG_STUDENT.cpp : implementation file
//

#include "stdafx.h"
#include "TrainingSchoolsys.h"
#include "DIALOG_STUDENT.h"
#include "ShowAllSubjectDlg.h"
#include "MyTimeTableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_STUDENT dialog


CDIALOG_STUDENT::CDIALOG_STUDENT(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_STUDENT::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOG_STUDENT)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDIALOG_STUDENT::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOG_STUDENT)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIALOG_STUDENT, CDialog)
	//{{AFX_MSG_MAP(CDIALOG_STUDENT)
	ON_COMMAND(ID_MENU_ALLSUBJECT, OnMenuAllsubject)
	ON_COMMAND(ID_MENU_TIMETABLE, OnMenuTimetable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_STUDENT message handlers

BOOL CDIALOG_STUDENT::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Menu.LoadMenu(IDR_MENU_STUDENT);
	SetMenu(&m_Menu);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CDIALOG_STUDENT::OnMenuAllsubject() 
{
	// TODO: Add your command handler code here
	CShowAllSubjectDlg *pDlg = new CShowAllSubjectDlg;
	pDlg->Create(IDD_DIALOG_SHOWALLSUBJECT);
	pDlg->ShowWindow(SW_NORMAL);


//	CShowAllSubjectDlg dlg;//定义一个新对话框的对象
//	dlg.DoModal();//弹出对话框
}

void CDIALOG_STUDENT::OnMenuTimetable() 
{
	// TODO: Add your command handler code here
	CMyTimeTableDlg dlg;//定义一个新对话框的对象
	dlg.DoModal();//弹出对话框
}
