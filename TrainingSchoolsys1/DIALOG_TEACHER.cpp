// DIALOG_TEACHER.cpp : implementation file
//

#include "stdafx.h"
#include "TrainingSchoolsys.h"
#include "DIALOG_TEACHER.h"
#include "ShowAllSubjectDlg1.h"
#include "UserINFODlg.h"
#include "CheckMessageDlg.h"
#include "CurrentSituationDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_TEACHER dialog


CDIALOG_TEACHER::CDIALOG_TEACHER(CWnd* pParent /*=NULL*/)
	: CDialog(CDIALOG_TEACHER::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDIALOG_TEACHER)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDIALOG_TEACHER::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDIALOG_TEACHER)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDIALOG_TEACHER, CDialog)
	//{{AFX_MSG_MAP(CDIALOG_TEACHER)
	ON_COMMAND(ID_MENU_ALLSUBJECT, OnMenuAllsubject)
	ON_COMMAND(ID_MENU_ALLSTUDENTINFO, OnMenuAllstudentinfo)
	ON_COMMAND(ID_MENU_MESSAGE1, OnMenuMessage1)
	ON_COMMAND(ID_MENU_ENROLLINFO, OnMenuEnrollinfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_TEACHER message handlers

void CDIALOG_TEACHER::OnMenuAllsubject() 
{
	// TODO: Add your command handler code here
	CShowAllSubjectDlg1 dlg;
	dlg.DoModal();
}

void CDIALOG_TEACHER::OnMenuAllstudentinfo() 
{
	// TODO: Add your command handler code here
	CUserINFODlg dlg;
	dlg.DoModal();
}

void CDIALOG_TEACHER::OnMenuMessage1() 
{
	// TODO: Add your command handler code here
	CCheckMessageDlg dlg;
	dlg.DoModal();
}

void CDIALOG_TEACHER::OnMenuEnrollinfo() 
{
	// TODO: Add your command handler code here
	CCurrentSituationDlg dlg;
	dlg.DoModal();
}
