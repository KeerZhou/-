#if !defined(AFX_MYTIMETABLEDLG_H__C7A9B6AC_C6AA_4B44_86D6_B6360E78C2D9__INCLUDED_)
#define AFX_MYTIMETABLEDLG_H__C7A9B6AC_C6AA_4B44_86D6_B6360E78C2D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyTimeTableDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyTimeTableDlg dialog

class CMyTimeTableDlg : public CDialog
{
// Construction
public:
	CMyTimeTableDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMyTimeTableDlg)
	enum { IDD = IDD_DIALOG_MYTIMETABEL };
	CListCtrl	m_timetable;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTimeTableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMyTimeTableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonDelete();
	afx_msg void OnButtonRefresh();
	afx_msg void OnButtonPay();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTIMETABLEDLG_H__C7A9B6AC_C6AA_4B44_86D6_B6360E78C2D9__INCLUDED_)
