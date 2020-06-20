// ReplyMessageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "ReplyMessageDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReplyMessageDlg dialog


CReplyMessageDlg::CReplyMessageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReplyMessageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReplyMessageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CReplyMessageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReplyMessageDlg)
	DDX_Control(pDX, IDC_LIST_REPLYMESSAGE, m_messagelist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReplyMessageDlg, CDialog)
	//{{AFX_MSG_MAP(CReplyMessageDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReplyMessageDlg message handlers

BOOL CReplyMessageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_messagelist.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);
	m_messagelist.InsertColumn(0,"回复",LVCFMT_LEFT,100,0);
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接
	CString str;
	str.Format("select * from replymessage where username='%s'",login_name);
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。

	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		m_messagelist.InsertItem(0,"");
		m_messagelist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();




	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
