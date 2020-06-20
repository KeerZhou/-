#if !defined(AFX_DELETESUBJECTDLG_H__2F76F8E3_ED59_47CF_A34F_34172F0F9D3A__INCLUDED_)
#define AFX_DELETESUBJECTDLG_H__2F76F8E3_ED59_47CF_A34F_34172F0F9D3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DeleteSubjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDeleteSubjectDlg dialog

class CDeleteSubjectDlg : public CDialog
{
// Construction
public:
	CDeleteSubjectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDeleteSubjectDlg)
	enum { IDD = IDD_DIALOG_DELETESUBJECT1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteSubjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDeleteSubjectDlg)
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonDelete();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETESUBJECTDLG_H__2F76F8E3_ED59_47CF_A34F_34172F0F9D3A__INCLUDED_)
