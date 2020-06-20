#if !defined(AFX_CURRENTSITUATIONDLG_H__53B2B29E_E287_43D8_BE23_D4780D0C3A1F__INCLUDED_)
#define AFX_CURRENTSITUATIONDLG_H__53B2B29E_E287_43D8_BE23_D4780D0C3A1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CurrentSituationDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCurrentSituationDlg dialog

class CCurrentSituationDlg : public CDialog
{
// Construction
public:
	CCurrentSituationDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCurrentSituationDlg)
	enum { IDD = IDD_DIALOG_CURRENTSITUATION };
	CListCtrl	m_currentsituationlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCurrentSituationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCurrentSituationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonSearch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURRENTSITUATIONDLG_H__53B2B29E_E287_43D8_BE23_D4780D0C3A1F__INCLUDED_)
