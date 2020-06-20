// CheckMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "CheckMessageDlg.h"
#include "ADOConn.h"
#include "SendReplyMessageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCheckMessageDlg dialog


CCheckMessageDlg::CCheckMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheckMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCheckMessageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCheckMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCheckMessageDlg)
	DDX_Control(pDX, IDC_LIST_CHECKMESSAGE, m_checkmessagelist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCheckMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CCheckMessageDlg)
	ON_BN_CLICKED(IDC_BUTTON_REPLY, OnButtonReply)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCheckMessageDlg message handlers

BOOL CCheckMessageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_checkmessagelist.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);

	m_checkmessagelist.InsertColumn(0,"用户名",LVCFMT_LEFT,100,0);         //为列表加入两列：用户名，留言
	m_checkmessagelist.InsertColumn(1,"留言",LVCFMT_LEFT,100,1);

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	CString str;
	str.Format("select * from message"); 

	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。

	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_checkmessagelist.InsertItem(0,"");
		 m_checkmessagelist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("username"));
		 m_checkmessagelist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));

		 m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCheckMessageDlg::OnButtonReply() 
{
	// TODO: Add your control notification handler code here
	CSendReplyMessageDlg dlg;//定义一个新对话框的对象
	dlg.DoModal();//弹出对话框

}
