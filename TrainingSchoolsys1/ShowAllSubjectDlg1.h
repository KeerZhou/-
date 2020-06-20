#if !defined(AFX_SHOWALLSUBJECTDLG1_H__2588B2A3_FDD7_4B48_8A5C_047F5956E952__INCLUDED_)
#define AFX_SHOWALLSUBJECTDLG1_H__2588B2A3_FDD7_4B48_8A5C_047F5956E952__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowAllSubjectDlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg1 dialog

class CShowAllSubjectDlg1 : public CDialog
{
// Construction
public:
	CShowAllSubjectDlg1(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowAllSubjectDlg1)
	enum { IDD = IDD_DIALOG_SHOWALLSUBJECT1 };
	CListCtrl	m_subjectlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowAllSubjectDlg1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowAllSubjectDlg1)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAddsubject();
	afx_msg void OnButtonAddsubject1();
	afx_msg void OnButtonDeletesubject();
	afx_msg void OnButtonUpdatesubject();
	afx_msg void OnButtonRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWALLSUBJECTDLG1_H__2588B2A3_FDD7_4B48_8A5C_047F5956E952__INCLUDED_)
