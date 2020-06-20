// LeaveMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "LeaveMessageDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeaveMessageDlg dialog


CLeaveMessageDlg::CLeaveMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLeaveMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLeaveMessageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CLeaveMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeaveMessageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeaveMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CLeaveMessageDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeaveMessageDlg message handlers

void CLeaveMessageDlg::OnOK() 
{
	// TODO: Add extra validation here
	_variant_t var;
	CString message;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	GetDlgItemText(IDC_EDIT_MESSAGE, message);

	if(message.GetLength()<=0){
		MessageBox("发送内容不能为空");
	}else{
		CString sql;
		sql.Format("insert into message(username,content\
				)values('%s','%s'\
				)",login_name,message);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);

		AfxMessageBox("发送成功");
		m_AdoConn.ExitConnect();
	}


	CDialog::OnOK();
}
