#if !defined(AFX_DIALOG_TEACHER_H__5BC51991_0FFF_474A_9E8B_7076FB9CC2E1__INCLUDED_)
#define AFX_DIALOG_TEACHER_H__5BC51991_0FFF_474A_9E8B_7076FB9CC2E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIALOG_TEACHER.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_TEACHER dialog

class CDIALOG_TEACHER : public CDialog
{
// Construction
public:
	CDIALOG_TEACHER(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDIALOG_TEACHER)
	enum { IDD = IDD_DIALOG_TEACHER };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIALOG_TEACHER)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIALOG_TEACHER)
	afx_msg void OnMenuAllsubject();
	afx_msg void OnMenuAllstudentinfo();
	afx_msg void OnMenuMessage1();
	afx_msg void OnMenuEnrollinfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_TEACHER_H__5BC51991_0FFF_474A_9E8B_7076FB9CC2E1__INCLUDED_)
