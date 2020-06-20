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
	m_checkmessagelist.SetExtendedStyle(LVS_EX_FLATSB          //��ʼ���б�
	|LVS_EX_FULLROWSELECT
	|LVS_EX_HEADERDRAGDROP
	|LVS_EX_ONECLICKACTIVATE
	|LVS_EX_GRIDLINES);

	m_checkmessagelist.InsertColumn(0,"�û���",LVCFMT_LEFT,100,0);         //Ϊ�б�������У��û���������
	m_checkmessagelist.InsertColumn(1,"����",LVCFMT_LEFT,100,1);

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

	CString str;
	str.Format("select * from message"); 

	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����

	while(m_AdoConn.m_pRecordset->adoEOF1==0)                   //���δ��������¼�����һ�У���Ϊ�б�����Ӽ����������ݡ�������¼����
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
	CSendReplyMessageDlg dlg;//����һ���¶Ի���Ķ���
	dlg.DoModal();//�����Ի���

}
