// AddSubjectDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "trainingschoolsys.h"
#include "AddSubjectDlg1.h"
#include "ADOConn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg1 dialog


CAddSubjectDlg1::CAddSubjectDlg1(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSubjectDlg1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddSubjectDlg1)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAddSubjectDlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddSubjectDlg1)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddSubjectDlg1, CDialog)
	//{{AFX_MSG_MAP(CAddSubjectDlg1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg1 message handlers

void CAddSubjectDlg1::OnOK() 
{
	// TODO: Add extra validation here
	CString class_id;
	_variant_t var;
	CString classtitle;
	CString classdatetime;
	CString classcontent;
	CString classfee;
	CString totalnumber;
	CString currentnumber;

	CADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();                               //打开数据库连接

	GetDlgItemText(IDC_EDIT_CLASSID, class_id);
	GetDlgItemText(IDC_EDIT_CLASSTITLE, classtitle);
	GetDlgItemText(IDC_EDIT_CLASSDATETIME, classdatetime);
	GetDlgItemText(IDC_EDIT_CLASSCONTENT, classcontent);
	GetDlgItemText(IDC_EDIT_CLASSFEE, classfee);
	GetDlgItemText(IDC_EDIT_TOTALNUMBER, totalnumber);
	GetDlgItemText(IDC_EDIT_CURRENTNUMBER, currentnumber);

	CString str;
	str.Format("select * from news where class_id='%s'",class_id);
	_RecordsetPtr m_pRecordset;                                 //声明记录集对象
	m_pRecordset = m_AdoConn.GetRecordSet((_bstr_t)str);        //获得sql语句检索得的记录集。

	if(!m_AdoConn.m_pRecordset->adoEOF1){
		AfxMessageBox("课程id已存在");
	}else{
		if(classtitle.GetLength()<=0||classdatetime.GetLength()<=0||classcontent.GetLength()<=0||classfee.GetLength()<=0||totalnumber.GetLength()<=0||currentnumber.GetLength()<=0){
			AfxMessageBox("内容不能为空");
		}else{
			CString sql;	
			sql.Format("insert into news(class_id,title,datetime,content,fee,\
				totalnumber,currentnumber)values('%s','%s','%s','%s','%s',\
				'%s','%s')",class_id,classtitle,classdatetime,classcontent,classfee,totalnumber,currentnumber);
			m_AdoConn.ExecuteSQL((_bstr_t)sql);
			m_AdoConn.ExitConnect();
			AfxMessageBox("添加成功");


		}
	}

}
