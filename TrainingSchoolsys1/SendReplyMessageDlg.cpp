// SendReplyMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "SendReplyMessageDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSendReplyMessageDlg dialog


CSendReplyMessageDlg::CSendReplyMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSendReplyMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSendReplyMessageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSendReplyMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSendReplyMessageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSendReplyMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CSendReplyMessageDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSendReplyMessageDlg message handlers

void CSendReplyMessageDlg::OnOK() 
{
	// TODO: Add extra validation here
	_variant_t var;
	CString message;
	CString username;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	GetDlgItemText(IDC_EDIT_USERNAME, username);
	GetDlgItemText(IDC_EDIT_MESSAGE, message);

	if(message.GetLength()<=0||username.GetLength()<=0){
		MessageBox("发送内容不能为空");
	}else{
		CString sql;
		sql.Format("insert into replymessage(username,content\
				)values('%s','%s'\
				)",username,message);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);

		AfxMessageBox("发送成功");
		m_AdoConn.ExitConnect();
	}
	CDialog::OnOK();
}
