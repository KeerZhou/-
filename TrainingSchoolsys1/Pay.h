#if !defined(AFX_PAY_H__D8500F81_B6A1_49CF_94C0_77D59A9FAFAF__INCLUDED_)
#define AFX_PAY_H__D8500F81_B6A1_49CF_94C0_77D59A9FAFAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Pay.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPay dialog

class CPay : public CDialog
{
// Construction
public:
	CPay(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPay)
	enum { IDD = IDD_DIALOG_PAY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPay)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAY_H__D8500F81_B6A1_49CF_94C0_77D59A9FAFAF__INCLUDED_)
