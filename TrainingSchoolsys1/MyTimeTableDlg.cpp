// MyTimeTableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "MyTimeTableDlg.h"
#include "ADOConn.h"
#include "Dlg_login.h"
#include "DeleteMySubjectDlg.h"
#include "Pay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTimeTableDlg dialog


CMyTimeTableDlg::CMyTimeTableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyTimeTableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyTimeTableDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CMyTimeTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyTimeTableDlg)
	DDX_Control(pDX, IDC_LIST_TIMETABLE, m_timetable);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMyTimeTableDlg, CDialog)
	//{{AFX_MSG_MAP(CMyTimeTableDlg)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
	ON_BN_CLICKED(IDC_BUTTON_PAY, OnButtonPay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTimeTableDlg message handlers

BOOL CMyTimeTableDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	m_timetable.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);
	m_timetable.InsertColumn(0,"课程id",LVCFMT_LEFT,100,0);         //为列表加入四列：课程id，课程名称，课程日期，课程内容，费用
	m_timetable.InsertColumn(1,"课程名称",LVCFMT_LEFT,100,1);
	m_timetable.InsertColumn(2,"课程日期",LVCFMT_LEFT,100,2); 
	m_timetable.InsertColumn(3,"课程内容",LVCFMT_LEFT,100,3); 
	m_timetable.InsertColumn(4,"课程费用",LVCFMT_LEFT,100,4);
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接
	CString str;
	str.Format("select * from schedule where username='"+login_name+"' order by class_id desc");   //使用str代表SQL语句表名为news。通过列“class_id”按升序排列（asc），按降序排列（desc）
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_timetable.InsertItem(0,"");
		 m_timetable.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_timetable.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_timetable.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_timetable.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_timetable.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_pRecordset->MoveNext();
		 ((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);//启用按钮
		 ((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(TRUE);//启用按钮
	}



	m_AdoConn.ExitConnect();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMyTimeTableDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	CDeleteMySubjectDlg dlg;
	dlg.DoModal();
}

void CMyTimeTableDlg::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here
	((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(FALSE);//关闭按钮
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);//关闭按钮
	m_timetable.DeleteAllItems();
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接
	CString str;
	str.Format("select * from schedule where username='"+login_name+"' order by class_id desc");   //使用str代表SQL语句表名为news。通过列“class_id”按升序排列（asc），按降序排列（desc）
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_timetable.InsertItem(0,"");
		 m_timetable.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_timetable.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_timetable.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_timetable.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_timetable.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_pRecordset->MoveNext();
		 ((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);//启用按钮
		 ((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(TRUE);//启用按钮
	}
	m_AdoConn.ExitConnect();
}

void CMyTimeTableDlg::OnButtonPay() 
{
	// TODO: Add your control notification handler code here
	CPay dlg;
	dlg.DoModal();
}
