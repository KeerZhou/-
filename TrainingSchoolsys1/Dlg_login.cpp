// Dlg_login.cpp : implementation file
//

#include "stdafx.h"
#include "TrainingSchoolsys.h"
#include "Dlg_login.h"
#include "DIALOG_TEACHER.h"
#include "DIALOG_STUDENT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg_login dialog


CDlg_login::CDlg_login(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_login::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg_login)
	m_login_name = _T("");
	m_login_pwd = _T("");
	//}}AFX_DATA_INIT
}


void CDlg_login::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg_login)
	DDX_Text(pDX, IDC_EDIT_NAME, m_login_name);
	DDX_Text(pDX, IDC_EDIT_PWD, m_login_pwd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg_login, CDialog)
	//{{AFX_MSG_MAP(CDlg_login)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg_login message handlers

void CDlg_login::OnOK() 
{
	// TODO: Add extra validation here
	_variant_t var;
    CString strtext;
	this->UpdateData(true);
	::CoInitialize(NULL); 
	this->m_pConnection.CreateInstance(__uuidof(Connection));
	this->m_pRecordset.CreateInstance(__uuidof(Recordset));
	this->m_pConnection->Open("driver={SQL Server};Server=DESKTOP-BFKN1C8;Database=TrainingSchoolSystem;uid=sa;pwd=shenjianyi123;","","",0);
	//数据库连接语句
	CString str;
	str.Format("select * from users where username='%s' and password='%s'",this->m_login_name,this->m_login_pwd);
	//获取用户名和密码

	login_name.Format(m_login_name);

	BSTR bstrSQL=str.AllocSysString();
	this->m_pRecordset->Open(bstrSQL,(IDispatch*)this->m_pConnection,adOpenDynamic,adLockOptimistic,adCmdText);
	if(!this->m_pRecordset->adoEOF1){
		var =   (_bstr_t)m_pRecordset->GetCollect(_T("grade"));
        strtext = (LPCSTR)_bstr_t(var);
		//获取权限
		if(strtext == "1"){
			CDIALOG_STUDENT Dlg;
			Dlg.DoModal();
		}else{
			CDIALOG_TEACHER Dlg;
			Dlg.DoModal();
		}
		//CDialog::OnOK();
	}
	else{
		MessageBox("用户名或密码错误");
	}
	this->m_pRecordset->Close();
	this->m_pConnection->Close();
}
