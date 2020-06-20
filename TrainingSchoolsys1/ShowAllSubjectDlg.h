#if !defined(AFX_SHOWALLSUBJECTDLG_H__9DB3D26E_7CB9_4C34_B014_B45D5A5DC683__INCLUDED_)
#define AFX_SHOWALLSUBJECTDLG_H__9DB3D26E_7CB9_4C34_B014_B45D5A5DC683__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowAllSubjectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowAllSubjectDlg dialog

class CShowAllSubjectDlg : public CDialog
{
// Construction
public:
	CShowAllSubjectDlg(CWnd* pParent = NULL);   // standard constructor

	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

// Dialog Data
	//{{AFX_DATA(CShowAllSubjectDlg)
	enum { IDD = IDD_DIALOG_SHOWALLSUBJECT };
	CListCtrl	m_subjectlist;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowAllSubjectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowAllSubjectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonAddsubject();
	afx_msg void OnButtonRefresh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWALLSUBJECTDLG_H__9DB3D26E_7CB9_4C34_B014_B45D5A5DC683__INCLUDED_)
