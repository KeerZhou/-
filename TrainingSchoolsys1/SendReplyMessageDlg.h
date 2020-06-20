#if !defined(AFX_SENDREPLYMESSAGEDLG_H__7E3E605C_7874_4943_8952_42D71804E6CC__INCLUDED_)
#define AFX_SENDREPLYMESSAGEDLG_H__7E3E605C_7874_4943_8952_42D71804E6CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SendReplyMessageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSendReplyMessageDlg dialog

class CSendReplyMessageDlg : public CDialog
{
// Construction
public:
	CSendReplyMessageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSendReplyMessageDlg)
	enum { IDD = IDD_DIALOG_SENDREPLYMESSAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSendReplyMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSendReplyMessageDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SENDREPLYMESSAGEDLG_H__7E3E605C_7874_4943_8952_42D71804E6CC__INCLUDED_)
