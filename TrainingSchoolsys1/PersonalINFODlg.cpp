// PersonalINFODlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "PersonalINFODlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPersonalINFODlg dialog


CPersonalINFODlg::CPersonalINFODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPersonalINFODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPersonalINFODlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPersonalINFODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPersonalINFODlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPersonalINFODlg, CDialog)
	//{{AFX_MSG_MAP(CPersonalINFODlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPersonalINFODlg message handlers

BOOL CPersonalINFODlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	_variant_t var;
	CString truename;
	CString age;
	CString contact;
	CString address;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select * from student_information where username='%s'",login_name);   
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼��

	var =  (_bstr_t)m_pRecordset->GetCollect(_T("student_name"));
	truename = (LPCSTR)_bstr_t(var);                         //��ȡ��ʵ����

	var =  (_bstr_t)m_pRecordset->GetCollect(_T("old"));
	age = (LPCSTR)_bstr_t(var);                         //��ȡ����

	var =  (_bstr_t)m_pRecordset->GetCollect(_T("tel"));
	contact = (LPCSTR)_bstr_t(var);                         //��ȡ��ϵ��ʽ

	var =  (_bstr_t)m_pRecordset->GetCollect(_T("addr"));
	address = (LPCSTR)_bstr_t(var);                         //��ȡ��ַ

	SetDlgItemText(IDC_EDIT_USERNAME,login_name);
	SetDlgItemText(IDC_EDIT_TRUENAME,truename);
	SetDlgItemText(IDC_EDIT_AGE,age);
	SetDlgItemText(IDC_EDIT_CONTACT,contact);
	SetDlgItemText(IDC_EDIT_ADDRESS,address);

	m_AdoConn.ExitConnect();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPersonalINFODlg::OnOK() 
{
	// TODO: Add extra validation here
	_variant_t var;
	CString truename;
	CString age;
	CString contact;
	CString address;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

	GetDlgItemText(IDC_EDIT_TRUENAME, truename);
	GetDlgItemText(IDC_EDIT_AGE, age);
	GetDlgItemText(IDC_EDIT_CONTACT, contact);
	GetDlgItemText(IDC_EDIT_ADDRESS, address);
	
	CString sql;
	sql.Format("update student_information set student_name='%s',old='%s',tel='%s',addr='%s' where username='%s'",truename,age,contact,address,login_name);
	m_AdoConn.ExecuteSQL((_bstr_t)sql);
	m_AdoConn.ExitConnect();
	AfxMessageBox("�޸ĳɹ�");

	CDialog::OnOK();
}
