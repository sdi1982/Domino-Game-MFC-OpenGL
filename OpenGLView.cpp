// OpenGLView.cpp : implementation file
//

#include "stdafx.h"
#include "Term_Domino.h"
#include "Term_DominoDlg.h"
#include "OpenGLView.h"
#include "Domino.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

HGLRC hRC;
HDC hDC;
BLOCK_TYPE m_selectBlockType = TYPE0;

/////////////////////////////////////////////////////////////////////////////
// COpenGLView

IMPLEMENT_DYNCREATE(COpenGLView, CView)

COpenGLView::COpenGLView()
{
//	m_selectBlockType = TYPE1;
}

COpenGLView::~COpenGLView()
{
}


BEGIN_MESSAGE_MAP(COpenGLView, CView)
	//{{AFX_MSG_MAP(COpenGLView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenGLView drawing

void COpenGLView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here	

	wglMakeCurrent(hDC, hRC);
	SetupRC();
	Render();	
	wglMakeCurrent(hDC, NULL);
	//Invalidate(TRUE);


	/*
	HDC hdc = ::GetDC(m_hWnd);
	HGLRC hglrc;

	hglrc = wglCreateContext(hdc);
	wglMakeCurrent(hdc,hglrc);
	glClearColor(0.5,0.5,0.5,0);
	glColor3f(0.5,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers(hdc);
	wglMakeCurrent(NULL,NULL);
	::ReleaseDC(m_hWnd,hdc);
	wglDeleteContext(hglrc);
	*/
}

/////////////////////////////////////////////////////////////////////////////
// COpenGLView diagnostics

#ifdef _DEBUG
void COpenGLView::AssertValid() const
{
	CView::AssertValid();
}

void COpenGLView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenGLView message handlers

void COpenGLView::SetupPixelFormat(HDC hDC)
{

	int nPixelFormat;	// �ȼ� ���� ����
	static PIXELFORMATDESCRIPTOR pfd = {sizeof(PIXELFORMATDESCRIPTOR),
	1,							// ���� �׻� 1
	PFD_DRAW_TO_WINDOW|			// â ��� ����
	PFD_SUPPORT_OPENGL|			// OpenGL ����
	PFD_DOUBLEBUFFER|			// ���� ���۸� ����
	PFD_TYPE_RGBA,				// RGBA ���� ���
	32,							// 32 ��Ʈ ���� ���
	0,0,0,0,0,0,
	0,
	0,
	0,
	0,0,0,0,
	16,
	0,
	0,
	PFD_MAIN_PLANE,				// ���� ����� ���
	0,
	0,0,0 };

	// ���� ������ �ȼ� ������ �����ϰ� �ȴ�. ������ ��ȯ�ȴ�.
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

	// �ȼ� ������ ��ġ ���ƿ� ����
	SetPixelFormat(hDC, nPixelFormat, &pfd);

//	DescribePixelFormat(hDC, nPixelFormat, sizeof(pfd), &pfd);
	
}

int COpenGLView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here

	hDC = ::GetDC(m_hWnd);
	CRect rect;
	GetWindowRect(&rect);
	SetupPixelFormat(hDC);	
	Initialize(hDC,rect);

//	hRC = wglCreateContext(hDC);
//	wglMakeCurrent(hDC, hRC);
//	wglMakeCurrent(NULL, NULL);
//	Invalidate(TRUE);
	
	
	return 0;
}

void COpenGLView::SetupRC()
{
	GLfloat ambientLight[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	GLfloat specularLight[] = { 0.9f, 0.9f, 0.9f, 1.0f };
	
	GLfloat lightPos[] = { TILE_SIZE_X*TILE_WIDTH/2.0f, TILE_SIZE_Y*TILE_HEIGHT/2.0f, 50.0f, 1.0f };
	GLfloat specularRef[] = { 0.6f, 0.6f, 0.6f, 1.0f };

	glEnable(GL_DEPTH_TEST);	// ��������
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);		// �ָ��� ��ü ���ο� ���ؼ��� ������� �ʴ´�.

	glEnable(GL_LIGHTING);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

	glMaterialfv(GL_FRONT, GL_SPECULAR, specularRef);
	glMateriali(GL_FRONT, GL_SHININESS, 64);

	glClearColor(0.0f, 0.0f, 0.5f, 1.0f);

}

void COpenGLView::Resize(CRect rect)
{
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	//g_camera.PositionCamera(TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_Y*TILE_HEIGHT/2, 1.0f,	TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_Y*TILE_HEIGHT/2, 0.0f,	0, 1, 0);
	// ����Ʈ ũ�⸦ �ٽ� ����
	glViewport(0,0,width,height);
	
	glMatrixMode(GL_PROJECTION);	// ���� ��ķ� ����
	glLoadIdentity();				// ���� ����� �ʱ�ȭ
	//g_camera.PositionCamera(0.0f, 0.0f , 1.0f,	0.0f,0.0f, 0.0f,	0, 1, 0);

	if(width <= height)
		glOrtho(-TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_X*TILE_WIDTH/2, -TILE_SIZE_Y*TILE_HEIGHT/2*((float)height/(float)width),TILE_SIZE_Y*TILE_HEIGHT/2*((float)height/(float)width),-100.0f,100.0f);
	else
		glOrtho(-TILE_SIZE_X*TILE_WIDTH/2*((float)width/(float)height), TILE_SIZE_X*TILE_WIDTH/2*((float)width/(float)height), -TILE_SIZE_Y*TILE_HEIGHT/2,TILE_SIZE_Y*TILE_HEIGHT/2,-100.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);		// �𵨺� ��ķ� ����
	glLoadIdentity();				// �𵨺� ����� �ʱ�ȭ
}


void COpenGLView::Render()
{
	g_domino.drawBoard();
	glFlush();
	SwapBuffers(hDC);			// �ĸ� ���۸� ���� ���۷� ��ü
	Invalidate(FALSE);
}

void COpenGLView::Initialize(HDC hdc, CRect rect)
{
//	SetupPixelFormat(::GetDC(m_hWnd));

	// ������ ���ؽ�Ʈ�� �����ϰ� ���� ������ ���ؽ�Ʈ�� �����.
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);
//	CRect rect;
	Resize(rect);
	SetupRC();
//	Invalidate(TRUE);
}

void COpenGLView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	// TODO: Add your message handler code here
//	wglMakeCurrent(hDC, hRC);
//	CRect rect;
//	GetWindowRect(&rect);
//	Resize(cx, cy);
//	Resize(&rect);
//	wglMakeCurrent(NULL , NULL);
	
}
/*
void COpenGLView::Resize(int x, int y)
{
	int width = x;
	int height = y;

	//g_camera.PositionCamera(TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_Y*TILE_HEIGHT/2, 1.0f,	TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_Y*TILE_HEIGHT/2, 0.0f,	0, 1, 0);
	// ����Ʈ ũ�⸦ �ٽ� ����
	glViewport(0,0,width,height);
	
	glMatrixMode(GL_PROJECTION);	// ���� ��ķ� ����
	glLoadIdentity();				// ���� ����� �ʱ�ȭ
	//g_camera.PositionCamera(0.0f, 0.0f , 1.0f,	0.0f,0.0f, 0.0f,	0, 1, 0);

	if(width <= height)
		glOrtho(-TILE_SIZE_X*TILE_WIDTH/2, TILE_SIZE_X*TILE_WIDTH/2, -TILE_SIZE_Y*TILE_HEIGHT/2*((float)height/(float)width),TILE_SIZE_Y*TILE_HEIGHT/2*((float)height/(float)width),-100.0f,100.0f);
	else
		glOrtho(-TILE_SIZE_X*TILE_WIDTH/2*((float)width/(float)height), TILE_SIZE_X*TILE_WIDTH/2*((float)width/(float)height), -TILE_SIZE_Y*TILE_HEIGHT/2,TILE_SIZE_Y*TILE_HEIGHT/2,-100.0f,100.0f);

	glMatrixMode(GL_MODELVIEW);		// �𵨺� ��ķ� ����
	glLoadIdentity();


}
*/

void COpenGLView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	wglMakeCurrent(hDC,NULL);
	wglDeleteContext(hRC);	
	::ReleaseDC(m_hWnd, hDC);
}

void COpenGLView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	int ox = point.x;
	int oy = point.y;

//	g_domino.putBlockOnTile(ox,oy);
//	Domino.putBlockOnTile(ox,oy);
	g_domino.putBlockOnTile(ox,oy);

	Invalidate(FALSE);

	CView::OnLButtonDown(nFlags, point);
}


void COpenGLView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	int ox = point.x;
	int oy = point.y;
	g_domino.putStartOnTile(ox,oy);
	CView::OnRButtonDown(nFlags, point);
}
