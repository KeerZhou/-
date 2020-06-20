// SubjectINFODlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "SubjectINFODlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSubjectINFODlg dialog


CSubjectINFODlg::CSubjectINFODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSubjectINFODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSubjectINFODlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSubjectINFODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSubjectINFODlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSubjectINFODlg, CDialog)
	//{{AFX_MSG_MAP(CSubjectINFODlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_UPDATE, OnButtonUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSubjectINFODlg message handlers

void CSubjectINFODlg::OnButtonSearch() 
{
	// TODO: Add your control notification handler code here
	int class_id;
	_variant_t var;
	CString classtitle;
	CString classdatetime;
	CString classfee;
	CString classcontent;
	CString totalnumber;
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
		var =  (_bstr_t)m_pRecordset->GetCollect(_T("totalnumber"));
		totalnumber = (LPCSTR)_bstr_t(var);                           //��ȡ������
		SetDlgItemText(IDC_EDIT_CLASSTITLE,classtitle);
		SetDlgItemText(IDC_EDIT_CLASSDATETIME,classdatetime);
		SetDlgItemText(IDC_EDIT_CLASSCONTENT,classcontent);
		SetDlgItemText(IDC_EDIT_CLASSFEE,classfee);
		SetDlgItemText(IDC_EDIT_TOTALNUMBER,totalnumber);
	}else{
		MessageBox("û��Ҫ��ѯ�Ŀγ�id");
	}
}

void CSubjectINFODlg::OnButtonUpdate() 
{
	// TODO: Add your control notification handler code here
	_variant_t var;
	CString classid;
	CString classtitle;
	CString classdatetime;
	CString classcontent;
	CString classfee;
	CString totalnumber;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

	GetDlgItemText(IDC_EDIT_CLASSID, classid);
	GetDlgItemText(IDC_EDIT_CLASSTITLE, classtitle);
	GetDlgItemText(IDC_EDIT_CLASSDATETIME, classdatetime);
	GetDlgItemText(IDC_EDIT_CLASSCONTENT, classcontent);
	GetDlgItemText(IDC_EDIT_CLASSFEE, classfee);
	GetDlgItemText(IDC_EDIT_TOTALNUMBER, totalnumber);

	if(classid.GetLength()<=0){
		MessageBox("������γ�id");
	}else{
		CString sql;
		sql.Format("update news set class_id='%s',title='%s',datetime='%s',content='%s',fee='%s',totalnumber='%s' where class_id='%s'",classid,classtitle,classdatetime,classcontent,classfee,totalnumber,classid);
		m_AdoConn.ExecuteSQL((_bstr_t)sql);
		m_AdoConn.ExitConnect();
		AfxMessageBox("�޸ĳɹ�");
	}

}
