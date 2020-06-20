// TrainingSchoolsys.h : main header file for the TRAININGSCHOOLSYS application
//

#if !defined(AFX_TRAININGSCHOOLSYS_H__68626792_E3F8_4BE8_B65D_0BDDB62B3804__INCLUDED_)
#define AFX_TRAININGSCHOOLSYS_H__68626792_E3F8_4BE8_B65D_0BDDB62B3804__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrainingSchoolsysApp:
// See TrainingSchoolsys.cpp for the implementation of this class
//

class CTrainingSchoolsysApp : public CWinApp
{
public:
	CTrainingSchoolsysApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainingSchoolsysApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrainingSchoolsysApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAININGSCHOOLSYS_H__68626792_E3F8_4BE8_B65D_0BDDB62B3804__INCLUDED_)
