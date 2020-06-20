#if !defined(AFX_REGISTERDLG_H__F4D96FCE_7C15_42A4_803D_292A2F0078C2__INCLUDED_)
#define AFX_REGISTERDLG_H__F4D96FCE_7C15_42A4_803D_292A2F0078C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RegisterDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRegisterDlg dialog

class CRegisterDlg : public CDialog
{
// Construction
public:
	CRegisterDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRegisterDlg)
	enum { IDD = IDD_DIALOG_REGISTER };
	CString	m_address;
	CString	m_contact;
	CString	m_password;
	CString	m_truename;
	CString	m_username;
	CString	m_age;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegisterDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRegisterDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGISTERDLG_H__F4D96FCE_7C15_42A4_803D_292A2F0078C2__INCLUDED_)
