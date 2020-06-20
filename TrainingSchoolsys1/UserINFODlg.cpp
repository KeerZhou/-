// UserINFODlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "UserINFODlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserINFODlg dialog


CUserINFODlg::CUserINFODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUserINFODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUserINFODlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CUserINFODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUserINFODlg)
	DDX_Control(pDX, IDC_LIST_USER, m_userlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUserINFODlg, CDialog)
	//{{AFX_MSG_MAP(CUserINFODlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUserINFODlg message handlers

BOOL CUserINFODlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_userlist.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);

	m_userlist.InsertColumn(0,"用户id",LVCFMT_LEFT,100,0);         //为列表加入四列：课程id，课程名称，课程日期，课程内容，费用
	m_userlist.InsertColumn(1,"用户名",LVCFMT_LEFT,100,1);
	m_userlist.InsertColumn(2,"真实姓名",LVCFMT_LEFT,100,2); 
	m_userlist.InsertColumn(3,"年龄",LVCFMT_LEFT,100,3); 
	m_userlist.InsertColumn(4,"性别",LVCFMT_LEFT,100,4); 
	m_userlist.InsertColumn(5,"联系方式",LVCFMT_LEFT,100,5); 
	m_userlist.InsertColumn(6,"地址",LVCFMT_LEFT,100,6);

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	CString str;
	str.Format("select * from student_information order by user_id desc");  
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		m_userlist.InsertItem(0,"");
		m_userlist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("user_id"));
		m_userlist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("username"));
		m_userlist.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("student_name"));
		m_userlist.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("old"));
		m_userlist.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("sex"));
		m_userlist.SetItemText(0,5,(char*)(_bstr_t)m_pRecordset->GetCollect("tel"));
		m_userlist.SetItemText(0,6,(char*)(_bstr_t)m_pRecordset->GetCollect("addr"));
		m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
