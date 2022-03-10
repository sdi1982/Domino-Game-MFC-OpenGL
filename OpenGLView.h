#if !defined(AFX_OPENGLVIEW_H__61334C4B_1CD1_43A3_B465_FA8ADF904CD7__INCLUDED_)
#define AFX_OPENGLVIEW_H__61334C4B_1CD1_43A3_B465_FA8ADF904CD7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OpenGLView.h : header file
//
#include "Domino.h"
#include "Board.h"
#include "Block.h"


class CTerm_DominoDlg;
/////////////////////////////////////////////////////////////////////////////
// COpenGLView view

class COpenGLView : public CView
{
protected:
//	COpenGLView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COpenGLView)

// Attributes
public:
	COpenGLView();
	virtual ~COpenGLView();


// Operations
public:
	void Initialize(HDC hdc, CRect rect);
	void Render();
	void Resize(CRect rect);
	void SetupRC();
	void SetupPixelFormat(HDC hdc);

	

	CTerm_DominoDlg* m_pDlg;
	

	
	// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
//	virtual ~COpenGLView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLVIEW_H__61334C4B_1CD1_43A3_B465_FA8ADF904CD7__INCLUDED_)
