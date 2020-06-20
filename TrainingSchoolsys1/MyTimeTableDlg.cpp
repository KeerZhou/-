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

	m_timetable.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);
	m_timetable.InsertColumn(0,"�γ�id",LVCFMT_LEFT,100,0);         //Ϊ�б�������У��γ�id���γ����ƣ��γ����ڣ��γ����ݣ�����
	m_timetable.InsertColumn(1,"�γ�����",LVCFMT_LEFT,100,1);
	m_timetable.InsertColumn(2,"�γ�����",LVCFMT_LEFT,100,2); 
	m_timetable.InsertColumn(3,"�γ�����",LVCFMT_LEFT,100,3); 
	m_timetable.InsertColumn(4,"�γ̷���",LVCFMT_LEFT,100,4);
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select * from schedule where username='"+login_name+"' order by class_id desc");   //ʹ��str����SQL������Ϊnews��ͨ���С�class_id�����������У�asc�������������У�desc��
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
	{
		 m_timetable.InsertItem(0,"");
		 m_timetable.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_timetable.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_timetable.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_timetable.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_timetable.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_pRecordset->MoveNext();
		 ((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);//���ð�ť
		 ((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(TRUE);//���ð�ť
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
	((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(FALSE);//�رհ�ť
	((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(FALSE);//�رհ�ť
	m_timetable.DeleteAllItems();
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select * from schedule where username='"+login_name+"' order by class_id desc");   //ʹ��str����SQL������Ϊnews��ͨ���С�class_id�����������У�asc�������������У�desc��
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
	{
		 m_timetable.InsertItem(0,"");
		 m_timetable.SetItemText(0,0,(char*)(_bstr_t)m_pRecordset->GetCollect("class_id"));
		 m_timetable.SetItemText(0,1,(char*)(_bstr_t)m_pRecordset->GetCollect("title"));
		 m_timetable.SetItemText(0,2,(char*)(_bstr_t)m_pRecordset->GetCollect("datetime"));
		 m_timetable.SetItemText(0,3,(char*)(_bstr_t)m_pRecordset->GetCollect("content"));
		 m_timetable.SetItemText(0,4,(char*)(_bstr_t)m_pRecordset->GetCollect("fee"));
		 m_pRecordset->MoveNext();
		 ((CButton*)GetDlgItem(IDC_BUTTON_DELETE))->EnableWindow(TRUE);//���ð�ť
		 ((CButton*)GetDlgItem(IDC_BUTTON_PAY))->EnableWindow(TRUE);//���ð�ť
	}
	m_AdoConn.ExitConnect();
}

void CMyTimeTableDlg::OnButtonPay() 
{
	// TODO: Add your control notification handler code here
	CPay dlg;
	dlg.DoModal();
}
