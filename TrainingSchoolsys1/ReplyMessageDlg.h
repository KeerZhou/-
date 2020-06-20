#if !defined(AFX_REPLYMESSAGEDLG_H__74A249A6_B870_4DB4_B3CF_DA0E26E18554__INCLUDED_)
#define AFX_REPLYMESSAGEDLG_H__74A249A6_B870_4DB4_B3CF_DA0E26E18554__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReplyMessageDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReplyMessageDlg dialog

class CReplyMessageDlg : public CDialog
{
// Construction
public:
	CReplyMessageDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReplyMessageDlg)
	enum { IDD = IDD_DIALOG_REPLYMESSAGE };
	CListCtrl	m_messagelist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplyMessageDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReplyMessageDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLYMESSAGEDLG_H__74A249A6_B870_4DB4_B3CF_DA0E26E18554__INCLUDED_)
