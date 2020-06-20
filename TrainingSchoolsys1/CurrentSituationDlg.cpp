// CurrentSituationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "CurrentSituationDlg.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCurrentSituationDlg dialog


CCurrentSituationDlg::CCurrentSituationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCurrentSituationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCurrentSituationDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCurrentSituationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCurrentSituationDlg)
	DDX_Control(pDX, IDC_LIST_CURRENTSITUATION, m_currentsituationlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCurrentSituationDlg, CDialog)
	//{{AFX_MSG_MAP(CCurrentSituationDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCurrentSituationDlg message handlers

BOOL CCurrentSituationDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_currentsituationlist.SetExtendedStyle(LVS_EX_FLATSB          //初始化列表
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);

	m_currentsituationlist.InsertColumn(0,"课程id",LVCFMT_LEFT,100,0);
	m_currentsituationlist.InsertColumn(1,"课程名称",LVCFMT_LEFT,100,1);
	m_currentsituationlist.InsertColumn(2,"已报名人数",LVCFMT_LEFT,100,2); 

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	CString str;
	str.Format("select * from news order by class_id desc");   //使用str代表SQL语句表名为news。通过列"class_id"按升序排列（asc），按降序排列（desc）

	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。

	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_currentsituationlist.InsertItem(0,"");
		 m_currentsituationlist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_currentsituationlist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_currentsituationlist.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("currentnumber"));

		 m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CCurrentSituationDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here


	int class_id = GetDlgItemInt(IDC_EDIT_CLASSID);
	if(class_id==NULL){
		MessageBox("请输入课程id");
	}else{
	m_currentsituationlist.DeleteAllItems();
	for(int nIndex=0;nIndex<7;nIndex++)   
		m_currentsituationlist.DeleteColumn(0);   

	m_currentsituationlist.InsertColumn(0,"用户id",LVCFMT_LEFT,100,0);
	m_currentsituationlist.InsertColumn(1,"用户名",LVCFMT_LEFT,100,1);
	m_currentsituationlist.InsertColumn(2,"学生姓名",LVCFMT_LEFT,100,2);
	m_currentsituationlist.InsertColumn(3,"年龄",LVCFMT_LEFT,100,3); 
	m_currentsituationlist.InsertColumn(4,"性别",LVCFMT_LEFT,100,4); 
	m_currentsituationlist.InsertColumn(5,"联系方式",LVCFMT_LEFT,100,5); 
	m_currentsituationlist.InsertColumn(6,"地址",LVCFMT_LEFT,100,6); 


	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	CString str;
	str.Format("SELECT * FROM student_information WHERE username IN (SELECT username FROM schedule WHERE class_id=%d)order by user_id desc",class_id);   //使用str代表SQL语句表名为news。通过列"class_id"按升序排列（asc），按降序排列（desc）

	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。

	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //如果未检索到记录集最后一行，就为列表行添加检索到的数据。遍历记录集。
	{
		 m_currentsituationlist.InsertItem(0,"");
		 m_currentsituationlist.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("user_id"));
		 m_currentsituationlist.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("username"));
		 m_currentsituationlist.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("student_name"));
		 m_currentsituationlist.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("old"));
		 m_currentsituationlist.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("sex"));
		 m_currentsituationlist.SetItemText(0,5,(char*)(_bstr_t)m_pRecordset->GetCollect("tel"));
		 m_currentsituationlist.SetItemText(0,6,(char*)(_bstr_t)m_pRecordset->GetCollect("addr"));


		 m_pRecordset->MoveNext();
	}
	m_AdoConn.ExitConnect();
	}
}
