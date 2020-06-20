// ShowAllSubjectDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "ShowAllSubjectDlg1.h"
#include "ADOConn.h"
#include "AddSubjectDlg1.h"
#include "DeleteSubjectDlg.h"
#include "SubjectINFODlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg1 dialog


CShowAllSubjectDlg1::CShowAllSubjectDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CShowAllSubjectDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowAllSubjectDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowAllSubjectDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowAllSubjectDlg1)
	DDX_Control(pDX, IDC_LIST_ALLSUBJECT, m_subjectlist);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowAllSubjectDlg1, CDialog)
	//{{AFX_MSG_MAP(CShowAllSubjectDlg1)
	ON_BN_CLICKED(IDC_BUTTON_ADDSUBJECT, OnButtonAddsubject)
	ON_BN_CLICKED(IDC_BUTTON_DELETESUBJECT, OnButtonDeletesubject)
	ON_BN_CLICKED(IDC_BUTTON_UPDATESUBJECT, OnButtonUpdatesubject)
	ON_BN_CLICKED(IDC_BUTTON_REFRESH, OnButtonRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg1 message handlers

BOOL CShowAllSubjectDlg1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_subjectlist.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);
	m_subjectlist.InsertColumn(0,"�γ�id",LVCFMT_LEFT,100,0);         //Ϊ�б�������У��γ�id���γ����ƣ��γ����ڣ��γ����ݣ�����
	m_subjectlist.InsertColumn(1,"�γ�����",LVCFMT_LEFT,100,1);
	m_subjectlist.InsertColumn(2,"�γ�ʱ��",LVCFMT_LEFT,100,2); 
	m_subjectlist.InsertColumn(3,"�γ�����",LVCFMT_LEFT,100,3); 
	m_subjectlist.InsertColumn(4,"����",LVCFMT_LEFT,100,4); 
	m_subjectlist.InsertColumn(5,"������",LVCFMT_LEFT,100,5); 
	m_subjectlist.InsertColumn(6,"������",LVCFMT_LEFT,100,6); 
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select * from news order by class_id desc");   //ʹ��str����SQL������Ϊnews��ͨ���С�class_id�����������У�asc�������������У�desc��
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
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

void CShowAllSubjectDlg1::OnButtonAddsubject() 
{
	// TODO: Add your control notification handler code here
	CAddSubjectDlg1 dlg;//����һ���¶Ի���Ķ���
	dlg.DoModal();//�����Ի���

}


void CShowAllSubjectDlg1::OnButtonDeletesubject() 
{
	// TODO: Add your control notification handler code here
	CDeleteSubjectDlg dlg;//����һ���¶Ի���Ķ���
	dlg.DoModal();//�����Ի���
}

void CShowAllSubjectDlg1::OnButtonUpdatesubject() 
{
	// TODO: Add your control notification handler code here
	CSubjectINFODlg dlg;
	dlg.DoModal();
}

void CShowAllSubjectDlg1::OnButtonRefresh() 
{
	// TODO: Add your control notification handler code here
	m_subjectlist.DeleteAllItems();
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select * from news order by class_id desc");   //ʹ��str����SQL������Ϊnews��ͨ���С�class_id�����������У�asc�������������У�desc��
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
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
