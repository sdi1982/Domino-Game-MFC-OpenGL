// Term_DominoDlg.h : header file
//
#include "OpenGLView.h"
#include "resource.h"

#if !defined(AFX_TERM_DOMINODLG_H__B343665A_3559_40FA_93D3_BDAAF6770446__INCLUDED_)
#define AFX_TERM_DOMINODLG_H__B343665A_3559_40FA_93D3_BDAAF6770446__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTerm_DominoDlg dialog

class CTerm_DominoDlg : public CDialog
{
// Construction
public:
	CRect rect;
	COpenGLView* m_pOpenGLView;
	CTerm_DominoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTerm_DominoDlg)
	enum { IDD = IDD_TERM_DOMINO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTerm_DominoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTerm_DominoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnBlock1();
	afx_msg void OnBlock0();
	afx_msg void OnBlock2();
	afx_msg void OnBlock3();
	afx_msg void OnBlock4();
//	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnStand();
	afx_msg void OnReset();
	afx_msg void OnStart();
	afx_msg void OnExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TERM_DOMINODLG_H__B343665A_3559_40FA_93D3_BDAAF6770446__INCLUDED_)
