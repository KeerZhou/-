#if !defined(AFX_ADDSUBJECTDLG1_H__2EE9BCEE_FF39_49BE_BC6A_C728F7B9AAFD__INCLUDED_)
#define AFX_ADDSUBJECTDLG1_H__2EE9BCEE_FF39_49BE_BC6A_C728F7B9AAFD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddSubjectDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddSubjectDlg1 dialog

class CAddSubjectDlg1 : public CDialog
{
// Construction
public:
	CAddSubjectDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAddSubjectDlg1)
	enum { IDD = IDD_DIALOG_ADDSUBJECT1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddSubjectDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddSubjectDlg1)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDSUBJECTDLG1_H__2EE9BCEE_FF39_49BE_BC6A_C728F7B9AAFD__INCLUDED_)
