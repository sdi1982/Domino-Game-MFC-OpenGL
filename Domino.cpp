#include "StdAfx.h"
#include "Domino.h"
//#include "../RevSound/SoundManager.h"
#include "Term_DominoDlg.h"
//extern HWND g_hDlg;

//using namespace rev;

Domino::Domino(void)
{
	m_selectBlockType = TYPE0;
	m_start = false;
}

Domino::~Domino(void)
{
}

void Domino::selectBlockType(BLOCK_TYPE blockType)
{
	// ������ Ÿ�� ������ ǥ���Ѵ�.
	CTerm_DominoDlg* m_pDlg = (CTerm_DominoDlg*)AfxGetMainWnd();
	switch(blockType)
	{
	case TYPE0:
		m_pDlg->SetDlgItemText(IDC_BLOCKTYPE,"��Ͼ���");
		break;
	case TYPE1:
		m_pDlg->SetDlgItemText(IDC_BLOCKTYPE,"����1");
		break;
	case TYPE2:
		m_pDlg->SetDlgItemText(IDC_BLOCKTYPE,"����2");
		break;
	case TYPE3:
		m_pDlg->SetDlgItemText(IDC_BLOCKTYPE,"����3");
		break;
	case TYPE4:
		m_pDlg->SetDlgItemText(IDC_BLOCKTYPE,"����4");
		break;
	}

	m_selectBlockType = blockType;
}

void Domino::drawBoard(void)
{
	// ������
	glEnable(GL_DEPTH_TEST);
	glFrontFace(GL_CW);
	// ȭ��� ���� ���۸� �����.
	glClearColor(1.0f,1.0f,1.0f,0.0f);						// ����� Ⱥ������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// ����� ���� ���۸� �����.
	glLoadIdentity();										// �𵨺� ��� �ʱ�ȭ
	if(m_start)
	{
		m_start = !m_board.startUpdate();
	}
	glPushMatrix();
	m_board.draw();
	glPopMatrix();
}
// ��ǥ�� ���念���� ���ϴ��� Ȯ���Ѵ�. 
bool Domino::InBoard(int x, int y)
{
	RECT rtBoardClient;
	CTerm_DominoDlg* m_pDlg = (CTerm_DominoDlg*)AfxGetMainWnd();
	CWnd* hBoard = m_pDlg->GetDlgItem(IDC_BOARD );
	hBoard->GetClientRect( &rtBoardClient );

	//// ������� ������� ���콺 ��ǥ ��
	//POINT boardPt = getBoardPoint(x,y);

	POINT boardPt;
	boardPt.x = x;
	boardPt.y = y;
	if((0 <= boardPt.x)&&( boardPt.x <= rtBoardClient.right)&&(0 < boardPt.y - 1)&&( boardPt.y < rtBoardClient.bottom - 1))
		return true;

	return false;
}

// �־��� ���콺 ��ǥ���� Ÿ���� ��� ������ Ÿ�� X, Y���� �����ش�. 
POINT Domino::pickTile(int x, int y)
{
	RECT rtBoardClient;
	CTerm_DominoDlg* m_pDlg = (CTerm_DominoDlg*)AfxGetMainWnd();
	CWnd* hBoard = m_pDlg->GetDlgItem(IDC_BOARD );
	hBoard->GetClientRect(&rtBoardClient );

	//// ������� ������� ���콺 ��ǥ ��
	//POINT boardPt = getBoardPoint(x,y);

	POINT boardPt;
	boardPt.x = x;
	boardPt.y = y;

	// Ÿ�ϰ��� ���� ������ ���Ѵ�.
	float cw = rtBoardClient.right / TILE_WIDTH;
	float ch = rtBoardClient.bottom / TILE_HEIGHT;


	// pt�� Ÿ�� �ε��� ���� �����Ѵ�.
	POINT TileIndex;
	TileIndex.x = boardPt.x / cw;

	TileIndex.y = TILE_HEIGHT - (boardPt.y / ch);

	return TileIndex;
}

// Ÿ�Ͽ� ����� �����Ѵ�.
bool Domino::putBlockOnTile(int x, int y)
{
	// Ŭ���� ���콺 ��ǥ�� ���� ���� �ִ��� Ȯ���Ѵ�.
	if(!InBoard(x,y))
		return false;

	// ���콺 ��ǥ ��ġ�� Ÿ���� �ε��� ���� ���Ѵ�.
	POINT pos = pickTile(x,y);

	m_board.setBlockOnTile(pos, m_selectBlockType);

	//	getSoundManager()->play("click");

	return true;
}


// Ÿ�Ͽ� ����� �����Ѵ�.
bool Domino::putStartOnTile(int x, int y)
{
	// Ŭ���� ���콺 ��ǥ�� ���� ���� �ִ��� Ȯ���Ѵ�.
	if(!InBoard(x,y))
		return false;

	// ���콺 ��ǥ ��ġ�� Ÿ���� �ε��� ���� ���Ѵ�.
	POINT pos = pickTile(x,y);

	// ���� Ÿ�� ��ǥ�� �����Ѵ�.
	m_board.setStartTile(pos.x,pos.y);

	return true;
}

// ������ ����� ��ǥ�� ���Ѵ�.
POINT Domino::getBoardPoint(int ox, int oy)
{
	RECT rtDlgWinodw;
	RECT rtDlgClient;
	RECT rtBoardWindow;
	RECT rtBoardClient;
	CTerm_DominoDlg* m_pDlg = (CTerm_DominoDlg*)AfxGetMainWnd();
	m_pDlg->GetWindowRect(&rtDlgWinodw);
	m_pDlg->GetClientRect(&rtDlgClient);

	CWnd* hBoard = m_pDlg->GetDlgItem(IDC_BOARD );
	hBoard->GetWindowRect(&rtBoardWindow );
	hBoard->GetClientRect(&rtBoardClient );

	// ������� = ������ ���� - Ŭ���̾�Ʈ ����) /2
	int borderWidth = ((rtDlgWinodw.right - rtDlgWinodw.left) - rtDlgClient.right)/2;
	// Ÿ��Ʋ�� ���� = ������ ���� - Ŭ���̾�Ʈ ���� - �Ʒ����� ����
	int titleHeight = (rtDlgWinodw.bottom - rtDlgWinodw.top) - rtDlgClient.bottom - borderWidth;

	// ����� ���̾�α� �۾�â�� ���� = Ÿ�̾�α� ��ǥ - ��������ǥ - (Ÿ��Ʋ�� ����/ ���� ����)
	POINT pt;
	pt.x = ox - (rtBoardWindow.left - rtDlgWinodw.left - borderWidth);
	pt.y = oy - (rtBoardWindow.top - rtDlgWinodw.top - titleHeight);

	return pt;
}

// ���̳븦 �����Ѵ�.
void Domino::start(void)
{
	m_start = true;
	m_board.start();
}

// ��������� �ʱ�ȭ
void Domino::reset(void)
{
	m_board.reset();
}

// ����� �����
void Domino::stand(void)
{
	m_board.stand();
}
