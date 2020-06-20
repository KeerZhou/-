// TrainingSchoolsysDlg.h : header file
//

#if !defined(AFX_TRAININGSCHOOLSYSDLG_H__5B2D4E5B_58C9_41F9_B38C_9440EB45800A__INCLUDED_)
#define AFX_TRAININGSCHOOLSYSDLG_H__5B2D4E5B_58C9_41F9_B38C_9440EB45800A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrainingSchoolsysDlg dialog

class CTrainingSchoolsysDlg : public CDialog
{
// Construction
public:
	CTrainingSchoolsysDlg(CWnd* pParent = NULL);	// standard constructor
	CMenu m_Menu;
// Dialog Data
	//{{AFX_DATA(CTrainingSchoolsysDlg)
	enum { IDD = IDD_TRAININGSCHOOLSYS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainingSchoolsysDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrainingSchoolsysDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDlgLogin();
	afx_msg void OnDlgRegister();
	afx_msg void OnMenuPersonalinfo();
	afx_msg void OnMenuMessage();
	afx_msg void OnMenuReplymessage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAININGSCHOOLSYSDLG_H__5B2D4E5B_58C9_41F9_B38C_9440EB45800A__INCLUDED_)
