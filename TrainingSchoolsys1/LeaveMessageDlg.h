#if !defined(AFX_LEAVEMESSAGEDLG_H__FB196C29_E33A_4707_B761_12BBDF492903__INCLUDED_)
#define AFX_LEAVEMESSAGEDLG_H__FB196C29_E33A_4707_B761_12BBDF492903__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeaveMessageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeaveMessageDlg dialog

class CLeaveMessageDlg : public CDialog
{
// Construction
public:
	CLeaveMessageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLeaveMessageDlg)
	enum { IDD = IDD_DIALOG_LEAVEMESSAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeaveMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLeaveMessageDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEAVEMESSAGEDLG_H__FB196C29_E33A_4707_B761_12BBDF492903__INCLUDED_)
