#if !defined(AFX_USERINFODLG_H__566024EC_6D9A_4B77_872F_21B78D8E3BE3__INCLUDED_)
#define AFX_USERINFODLG_H__566024EC_6D9A_4B77_872F_21B78D8E3BE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserINFODlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserINFODlg dialog

class CUserINFODlg : public CDialog
{
// Construction
public:
	CUserINFODlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CUserINFODlg)
	enum { IDD = IDD_DIALOG_USERINFO };
	CListCtrl	m_userlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserINFODlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CUserINFODlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERINFODLG_H__566024EC_6D9A_4B77_872F_21B78D8E3BE3__INCLUDED_)
