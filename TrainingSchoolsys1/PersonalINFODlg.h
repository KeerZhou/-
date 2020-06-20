#if !defined(AFX_PERSONALINFODLG_H__3D4F3974_10D4_4541_88AE_72F900E38774__INCLUDED_)
#define AFX_PERSONALINFODLG_H__3D4F3974_10D4_4541_88AE_72F900E38774__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PersonalINFODlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPersonalINFODlg dialog

class CPersonalINFODlg : public CDialog
{
// Construction
public:
	CPersonalINFODlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPersonalINFODlg)
	enum { IDD = IDD_DIALOG_PERSONALINFO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPersonalINFODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPersonalINFODlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PERSONALINFODLG_H__3D4F3974_10D4_4541_88AE_72F900E38774__INCLUDED_)
