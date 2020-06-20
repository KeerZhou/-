#if !defined(AFX_DIALOG_STUDENT_H__9FC0F754_40CD_44D8_A4A5_35A5C7E795F1__INCLUDED_)
#define AFX_DIALOG_STUDENT_H__9FC0F754_40CD_44D8_A4A5_35A5C7E795F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DIALOG_STUDENT.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDIALOG_STUDENT dialog

class CDIALOG_STUDENT : public CDialog
{
// Construction
public:
	CDIALOG_STUDENT(CWnd* pParent = NULL);   // standard constructor

	CMenu m_Menu;//定义一个菜单类对象
// Dialog Data
	//{{AFX_DATA(CDIALOG_STUDENT)
	enum { IDD = IDD_DIALOG_STUDENT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDIALOG_STUDENT)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDIALOG_STUDENT)
	virtual BOOL OnInitDialog();
	afx_msg void OnMenuAllsubject();
	afx_msg void OnMenuTimetable();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOG_STUDENT_H__9FC0F754_40CD_44D8_A4A5_35A5C7E795F1__INCLUDED_)
