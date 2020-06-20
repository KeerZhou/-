#if !defined(AFX_DLG_LOGIN_H__6DFECFB8_4DD8_4EE7_8379_DB2E4DA83EE6__INCLUDED_)
#define AFX_DLG_LOGIN_H__6DFECFB8_4DD8_4EE7_8379_DB2E4DA83EE6__INCLUDED_

#include "StdAfx.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg_login.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg_login dialog

class CDlg_login : public CDialog
{
// Construction
public:
	int m_login_grade;
	CDlg_login(CWnd* pParent = NULL);   // standard constructor
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

// Dialog Data
	//{{AFX_DATA(CDlg_login)
	enum { IDD = IDD_DIALOG_LOGIN };
	CString	m_login_name;
	CString	m_login_pwd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg_login)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg_login)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_LOGIN_H__6DFECFB8_4DD8_4EE7_8379_DB2E4DA83EE6__INCLUDED_)
