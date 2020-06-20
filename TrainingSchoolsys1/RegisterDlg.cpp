// RegisterDlg.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "RegisterDlg.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog


CRegisterDlg::CRegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegisterDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegisterDlg)
	m_address = _T("");
	m_contact = _T("");
	m_password = _T("");
	m_truename = _T("");
	m_username = _T("");
	m_age = _T("");
	//}}AFX_DATA_INIT
}


void CRegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegisterDlg)
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_address);
	DDX_Text(pDX, IDC_EDIT_CONTACT, m_contact);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_password);
	DDX_Text(pDX, IDC_EDIT_TRUENAME, m_truename);
	DDX_Text(pDX, IDC_EDIT_USERNAME, m_username);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg message handlers

void CRegisterDlg::OnOK() 
{
	// TODO: Add extra validation here
	CString username;
	_variant_t var;
	CString password;
	CString truename;
	CString sex;
	CString age;
	CString contact;
	CString address;
	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	GetDlgItemText(IDC_EDIT_USERNAME, username);
	GetDlgItemText(IDC_EDIT_PASSWORD, password);
	GetDlgItemText(IDC_EDIT_TRUENAME, truename);
	GetDlgItemText(IDC_EDIT_AGE, age);
	GetDlgItemText(IDC_EDIT_CONTACT, contact);
	GetDlgItemText(IDC_EDIT_ADDRESS, address);

	CString sql;
	sql.Format("select * from student_information where username='%s'",username);
	_RecordsetPtr m_pRecordset;
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)sql);
	if(username.GetLength()<=0||password.GetLength()<=0||truename.GetLength()<=0||age.GetLength()<=0||contact.GetLength()<=0||address.GetLength()<=0){
		AfxMessageBox("内容不能为空");
	}else{
		if(!m_AdoConn.m_pRecordset->adoEOF1){
			AfxMessageBox("用户名已被注册");
		}else{
	
			int index;	
			index=((CComboBox*)GetDlgItem(IDC_COMBO_SEX))->GetCurSel();	
			((CComboBox*)GetDlgItem(IDC_COMBO_SEX))->GetLBText(index,sex);
			CString sql1;	
			sql1.Format("insert into student_information(student_name,old,sex,tel,addr,\
				username)values('%s','%s','%s','%s','%s',\
				'%s')",truename,age,sex,contact,address,username);
			m_AdoConn.ExecuteSQL((_bstr_t)sql1);

	
			CString sql2;	
			sql2.Format("select user_id from student_information where username='%s'",username);   //使用sql2代表SQL语句表名为student_information
			_RecordsetPtr m_pRecordset1;                                 //声明记录集对象
			m_pRecordset1 = m_AdoConn.GetRecordSet((_bstr_t)sql2);        //获得sql语句检索得的记录集。
			var =  (_bstr_t)m_pRecordset1->GetCollect(_T("user_id"));
			CString userid1 = (LPCSTR)_bstr_t(var);
			int userid = atoi(userid1);                     //获取userid



			CString sql3;
			sql3.Format("insert into users(user_id,username,password,grade\
				)values('%s','%s','%s','%s'\
				)",userid1,username,password,"1");
			m_AdoConn.ExecuteSQL((_bstr_t)sql3);

			m_AdoConn.ExitConnect();
			AfxMessageBox("注册成功");
			CDialog::OnOK();
		}
	}
}
