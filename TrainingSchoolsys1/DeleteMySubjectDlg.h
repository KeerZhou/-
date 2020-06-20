#if !defined(AFX_DELETEMYSUBJECTDLG_H__A84D90A5_F80A_4018_95C2_41B1EFFE6FA4__INCLUDED_)
#define AFX_DELETEMYSUBJECTDLG_H__A84D90A5_F80A_4018_95C2_41B1EFFE6FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteMySubjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteMySubjectDlg dialog

class CDeleteMySubjectDlg : public CDialog
{
// Construction
public:
	CDeleteMySubjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteMySubjectDlg)
	enum { IDD = IDD_DIALOG_DELETEMYSUBJECT };
	CString	m_classtitle;
	CString	m_classdatetime;
	CString	m_classcontent;
	CString	m_classid;
	CString	m_classfee;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteMySubjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteMySubjectDlg)
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEMYSUBJECTDLG_H__A84D90A5_F80A_4018_95C2_41B1EFFE6FA4__INCLUDED_)
