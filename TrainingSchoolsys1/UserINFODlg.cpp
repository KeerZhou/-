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
	m_userlist.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);

	m_userlist.InsertColumn(0,"�û�id",LVCFMT_LEFT,100,0);         //Ϊ�б�������У��γ�id���γ����ƣ��γ����ڣ��γ����ݣ�����
	m_userlist.InsertColumn(1,"�û���",LVCFMT_LEFT,100,1);
	m_userlist.InsertColumn(2,"��ʵ����",LVCFMT_LEFT,100,2); 
	m_userlist.InsertColumn(3,"����",LVCFMT_LEFT,100,3); 
	m_userlist.InsertColumn(4,"�Ա�",LVCFMT_LEFT,100,4); 
	m_userlist.InsertColumn(5,"��ϵ��ʽ",LVCFMT_LEFT,100,5); 
	m_userlist.InsertColumn(6,"��ַ",LVCFMT_LEFT,100,6);

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

	CString str;
	str.Format("select * from student_information order by user_id desc");  
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
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
