// ShowAllSubjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "ShowAllSubjectDlg.h"
#include "ADOConn.h"
#include "AddSubjectDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg dialog


CShowAllSubjectDlg::CShowAllSubjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowAllSubjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowAllSubjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowAllSubjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowAllSubjectDlg)
	DDX_Control(pDX, IDC_LIST_ALLSUBJECT, m_subjectlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowAllSubjectDlg, CDialog)
	//{{AFX_MSG_MAP(CShowAllSubjectDlg)
	ON_BN_CLICKED(IDC_BUTTON_ADDSUBJECT, OnButtonAddsubject)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg message handlers
BOOL CShowAllSubjectDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_subjectlist.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);
	m_subjectlist.InsertColumn(0,"课程id",LVCFMT_LEFT,100,0);         //为列表加入七列：课程id，课程名称，课程日期，课程内容，费用
	m_subjectlist.InsertColumn(1,"课程名称",LVCFMT_LEFT,100,1);
	m_subjectlist.InsertColumn(2,"课程时间",LVCFMT_LEFT,100,2); 
	m_subjectlist.InsertColumn(3,"课程内容",LVCFMT_LEFT,100,3); 
	m_subjectlist.InsertColumn(4,"费用",LVCFMT_LEFT,100,4); 
	m_subjectlist.InsertColumn(5,"现人数",LVCFMT_LEFT,100,5); 
	m_subjectlist.InsertColumn(6,"总人数",LVCFMT_LEFT,100,6); 
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接
	CString str;
	str.Format("select * from news order by class_id desc");   //使用str代表SQL语句表名为news。通过列“class_id”按升序排列（asc），按降序排列（desc）
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_subjectlist.InsertItem(0,"");
		 m_subjectlist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_subjectlist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_subjectlist.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_subjectlist.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_subjectlist.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_subjectlist.SetItemText(0,5,(char*)(_bstr_t)m_pRecordset->GetCollect("currentnumber"));
		 m_subjectlist.SetItemText(0,6,(char*)(_bstr_t)m_pRecordset->GetCollect("totalnumber"));
		 m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowAllSubjectDlg::OnButtonAddsubject() 
{
	// TODO: Add your control notification handler code here
	CAddSubjectDlg dlg;
	dlg.DoModal();
}

void CShowAllSubjectDlg::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here
	m_subjectlist.DeleteAllItems();
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接
	CString str;
	str.Format("select * from news order by class_id desc");   //使用str代表SQL语句表名为news。通过列“class_id”按升序排列（asc），按降序排列（desc）
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。http://www.360kuai.com/pc/detail?url=http%3A%2F%2Ffawen.news.so.com%2Fd96b67057b6bd145af9988bc41bcbd9d&check=78d39914e4633e1d&sign=360_0de6261f
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_subjectlist.InsertItem(0,"");
		 m_subjectlist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_subjectlist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_subjectlist.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_subjectlist.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_subjectlist.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_subjectlist.SetItemText(0,5,(char*)(_bstr_t)m_pRecordset->GetCollect("currentnumber"));
		 m_subjectlist.SetItemText(0,6,(char*)(_bstr_t)m_pRecordset->GetCollect("totalnumber"));
		 m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();

}
