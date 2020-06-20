#if !defined(AFX_SUBJECTINFODLG_H__C4CF11D3_7FB2_4965_9ADA_7FE777EC8843__INCLUDED_)
#define AFX_SUBJECTINFODLG_H__C4CF11D3_7FB2_4965_9ADA_7FE777EC8843__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SubjectINFODlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSubjectINFODlg dialog

class CSubjectINFODlg : public CDialog
{
// Construction
public:
	CSubjectINFODlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSubjectINFODlg)
	enum { IDD = IDD_DIALOG_SUBJECTINFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSubjectINFODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSubjectINFODlg)
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonUpdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUBJECTINFODLG_H__C4CF11D3_7FB2_4965_9ADA_7FE777EC8843__INCLUDED_)
