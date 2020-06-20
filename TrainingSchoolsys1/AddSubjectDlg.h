#if !defined(AFX_ADDSUBJECTDLG_H__A7EDCE3E_364F_4C1E_8D8B_AD900D7E2004__INCLUDED_)
#define AFX_ADDSUBJECTDLG_H__A7EDCE3E_364F_4C1E_8D8B_AD900D7E2004__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSubjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg dialog

class CAddSubjectDlg : public CDialog
{
// Construction
public:
	CAddSubjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSubjectDlg)
	enum { IDD = IDD_DIALOG_ADDSUBJECT };
	CString	m_classtitle;
	CString	m_classdatetime;
	CString	m_classcontent;
	CString	m_class_id;
	CString	m_class_fee;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSubjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSubjectDlg)
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSUBJECTDLG_H__A7EDCE3E_364F_4C1E_8D8B_AD900D7E2004__INCLUDED_)
