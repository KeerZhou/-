// DeleteSubjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "DeleteSubjectDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteSubjectDlg dialog


CDeleteSubjectDlg::CDeleteSubjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteSubjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteSubjectDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDeleteSubjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteSubjectDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteSubjectDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteSubjectDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteSubjectDlg message handlers

void CDeleteSubjectDlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	int class_id;
	_variant_t var;
	CString classtitle;
	CString classdatetime;
	CString classfee;
	CString classcontent;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����
	class_id = GetDlgItemInt(IDC_EDIT_CLASSID);
	CString str;
	str.Format("select * from news where class_id=%d",class_id);   //ʹ��str����SQL������Ϊschedule
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����

	if(!m_AdoConn.m_pRecordset->adoEOF1){
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("title"));
		classtitle = (LPCSTR)_bstr_t(var);                         //��ȡ�γ�����
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("datetime"));
		classdatetime = (LPCSTR)_bstr_t(var);                      //��ȡ�γ�����
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("content"));
		classcontent = (LPCSTR)_bstr_t(var);                      //��ȡ�γ�����
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("fee"));
		classfee = (LPCSTR)_bstr_t(var);                           //��ȡ����
		SetDlgItemText(IDC_EDIT_CLASSTITLE,classtitle);
		SetDlgItemText(IDC_EDIT_CLASSDATETIME,classdatetime);
		SetDlgItemText(IDC_EDIT_CLASSCONTENT,classcontent);
		SetDlgItemText(IDC_EDIT_CLASSFEE,classfee);
	}else{
		MessageBox("û��Ҫ��ѯ�Ŀγ�id");
	}
	m_AdoConn.ExitConnect();
}


void CDeleteSubjectDlg::OnButtonDelete() 
{
	// TODO: Add your control notification handler code here
	CString class_id;
	_variant_t var;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

//	class_id.Format(m_classid);
//	classtitle.Format(m_classtitle);
//	classdatetime.Format(m_classdatetime);
//	classfee.Format(m_classfee);

	GetDlgItemText(IDC_EDIT_CLASSID, class_id);

	if(class_id.GetLength()<=0){
		MessageBox("������γ�id");
	}else{
		CString sql;
		sql.Format("delete from news where class_id='%s'",class_id);

		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.ExitConnect();
		AfxMessageBox("ɾ���ɹ�");
	}
}

