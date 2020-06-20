// DeleteMySubjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "DeleteMySubjectDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDeleteMySubjectDlg dialog


CDeleteMySubjectDlg::CDeleteMySubjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDeleteMySubjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDeleteMySubjectDlg)
	m_classtitle = _T("");
	m_classdatetime = _T("");
	m_classcontent = _T("");
	m_classid = _T("");
	m_classfee = _T("");
	//}}AFX_DATA_INIT
}


void CDeleteMySubjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDeleteMySubjectDlg)
	DDX_Text(pDX, IDC_EDIT_CLASSTITLE, m_classtitle);
	DDX_Text(pDX, IDC_EDIT_CLASSDATETIME, m_classdatetime);
	DDX_Text(pDX, IDC_EDIT_CLASSCONTENT, m_classcontent);
	DDX_Text(pDX, IDC_EDIT_CLASSID, m_classid);
	DDX_Text(pDX, IDC_EDIT_CLASSFEE, m_classfee);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDeleteMySubjectDlg, CDialog)
	//{{AFX_MSG_MAP(CDeleteMySubjectDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, OnButtonDelete)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDeleteMySubjectDlg message handlers

void CDeleteMySubjectDlg::OnButtonSearch() 
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
	str.Format("select * from schedule where class_id=%d and username='%s'",class_id,login_name);   //ʹ��str����SQL������Ϊschedule
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
}

void CDeleteMySubjectDlg::OnButtonDelete() 
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
		sql.Format("delete from schedule where class_id in(select class_id from schedule where class_id='%s' and username='%s')",class_id,login_name);


		CString str1;
		str1.Format("select * from news where class_id='%s'",class_id);   //ʹ��str����SQL������Ϊschedule
		_RecordsetPtr m_pRecordset1;                                 //������¼������
		m_pRecordset1 = m_AdoConn.GetRecordSet((_bstr_t)str1);        //���sql�������õļ�¼����

		var =  (_bstr_t)m_pRecordset1->GetCollect(_T("currentnumber"));
		CString currentnumber1 = (LPCSTR)_bstr_t(var);
		int currentnumber = atoi(currentnumber1);                //��ȡ������

		currentnumber = currentnumber - 1;
		CString sql1;
		sql1.Format("update news set currentnumber=%d where class_id='%s'",currentnumber,class_id);
		
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.ExecuteSQL((_bstr_t)sql1);
		m_AdoConn.ExitConnect();
		AfxMessageBox("ɾ���ɹ�");
	}

}
