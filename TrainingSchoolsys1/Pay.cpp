// Pay.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "Pay.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPay dialog


CPay::CPay(CWnd* pParent /*=NULL*/)
	: CDialog(CPay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPay)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPay)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPay, CDialog)
	//{{AFX_MSG_MAP(CPay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPay message handlers

BOOL CPay::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString fee;
	_variant_t var;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	CString str;
	str.Format("select sum(fee) as allfee from schedule where username='"+login_name+"'");   //ʹ��str����SQL������Ϊnews��ͨ���С�class_id�����������У�asc�������������У�desc��
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	if(!m_AdoConn.m_pRecordset->adoEOF1){
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("allfee"));
		fee = (LPCSTR)_bstr_t(var);  
	}else{
		MessageBox("��ѡ��γ�");
	}
	SetDlgItemText(IDC_EDIT_ALLEXPEND,fee);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
