#if !defined(AFX_CHECKMESSAGEDLG_H__2E5D292A_5DE5_4D20_B7B9_4AF8B5CCFCE6__INCLUDED_)
#define AFX_CHECKMESSAGEDLG_H__2E5D292A_5DE5_4D20_B7B9_4AF8B5CCFCE6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CheckMessageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCheckMessageDlg dialog

class CCheckMessageDlg : public CDialog
{
// Construction
public:
	CCheckMessageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCheckMessageDlg)
	enum { IDD = IDD_DIALOG_CHECKMESSAGE };
	CListCtrl	m_checkmessagelist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCheckMessageDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonReply();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKMESSAGEDLG_H__2E5D292A_5DE5_4D20_B7B9_4AF8B5CCFCE6__INCLUDED_)
