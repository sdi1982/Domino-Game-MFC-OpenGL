// Term_Domino.h : main header file for the TERM_DOMINO application
//

#if !defined(AFX_TERM_DOMINO_H__00224445_3B81_48A0_9D4F_308C1F012FB5__INCLUDED_)
#define AFX_TERM_DOMINO_H__00224445_3B81_48A0_9D4F_308C1F012FB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTerm_DominoApp:
// See Term_Domino.cpp for the implementation of this class
//

class CTerm_DominoApp : public CWinApp
{
public:
	CTerm_DominoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerm_DominoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTerm_DominoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERM_DOMINO_H__00224445_3B81_48A0_9D4F_308C1F012FB5__INCLUDED_)
