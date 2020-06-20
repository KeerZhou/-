// AddSubjectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "AddSubjectDlg.h"
#include "ADOConn.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg dialog


CAddSubjectDlg::CAddSubjectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSubjectDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSubjectDlg)
	m_classtitle = _T("");
	m_classdatetime = _T("");
	m_classcontent = _T("");
	m_class_id = _T("");
	m_class_fee = _T("");
	//}}AFX_DATA_INIT
}


void CAddSubjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSubjectDlg)
	DDX_Text(pDX, IDC_EDIT_CLASSTITLE, m_classtitle);
	DDX_Text(pDX, IDC_EDIT_CLASSDATETIME, m_classdatetime);
	DDX_Text(pDX, IDC_EDIT_CLASSCONTENT, m_classcontent);
	DDX_Text(pDX, IDC_EDIT_CLASSID, m_class_id);
	DDX_Text(pDX, IDC_EDIT_CLASSFEE, m_class_fee);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSubjectDlg, CDialog)
	//{{AFX_MSG_MAP(CAddSubjectDlg)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, OnButtonSearch)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg message handlers

void CAddSubjectDlg::OnButtonSearch() 
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

}

void CAddSubjectDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	CString class_id;
	_variant_t var;
	CString classtitle;
	CString classdatetime;
	CString classcontent;
	CString classfee;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //�����ݿ�����

//	class_id.Format(m_classid);
//	classtitle.Format(m_classtitle);
//	classdatetime.Format(m_classdatetime);
//	classfee.Format(m_classfee);

	GetDlgItemText(IDC_EDIT_CLASSID, class_id);
	GetDlgItemText(IDC_EDIT_CLASSTITLE, classtitle);
	GetDlgItemText(IDC_EDIT_CLASSDATETIME, classdatetime);
	GetDlgItemText(IDC_EDIT_CLASSCONTENT, classcontent);
	GetDlgItemText(IDC_EDIT_CLASSFEE, classfee);
	CString str;
	str.Format("select * from schedule where class_id='%s' and username='%s'",class_id,login_name);
	_RecordsetPtr m_pRecordset;                                 //������¼������
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //���sql�������õļ�¼����
	if(class_id.GetLength()<=0){
		MessageBox("������γ�id");
	}else{
		if(!m_AdoConn.m_pRecordset->adoEOF1){
			AfxMessageBox("������Ӹÿγ�");
		}
		else{
			CString str1;
			str1.Format("select * from news where class_id='%s'",class_id);   //ʹ��str����SQL������Ϊschedule
			_RecordsetPtr m_pRecordset1;                                 //������¼������
			m_pRecordset1 = m_AdoConn.GetRecordSet((_bstr_t)str1);        //���sql�������õļ�¼����

			var =  (_bstr_t)m_pRecordset1->GetCollect(_T("totalnumber"));
			CString totalnumber1 = (LPCSTR)_bstr_t(var);
			int totalnumber = atoi(totalnumber1);                     //��ȡ������

			var =  (_bstr_t)m_pRecordset1->GetCollect(_T("currentnumber"));
			CString currentnumber1 = (LPCSTR)_bstr_t(var);
			int currentnumber = atoi(currentnumber1);                //��ȡ������

			if(currentnumber>=totalnumber){
				AfxMessageBox("�ÿγ�����������");
			}else{
				currentnumber = currentnumber + 1;
				CString sql;
				CString sql1;
				sql.Format("insert into schedule(class_id,title,datetime,content,fee,\
				username)values('%s','%s','%s','%s','%s',\
				'%s')",class_id,classtitle,classdatetime,classcontent,classfee,login_name);
				sql1.Format("update news set currentnumber=%d where class_id='%s'",currentnumber,class_id);
			
				m_AdoConn.ExecuteSQL((_bstr_t)sql);
				m_AdoConn.ExecuteSQL((_bstr_t)sql1);
				m_AdoConn.ExitConnect();
				AfxMessageBox("��ӳɹ�");
			}
		}
	}

}
