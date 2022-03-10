#pragma once
#include "Board.h"
#include "Block.h"

class CTerm_DominoDlg;

class Domino
{
private:
	Domino(void);

	// ��ǥ�� ���念���� ���ϴ��� Ȯ���Ѵ�.
	bool InBoard(int x, int y);

	// �־��� ���콺 ��ǥ���� Ÿ���� ��� ������ Ÿ�� X, Y���� �����ش�. 
	POINT pickTile(int x, int y);
	
	// ���̾�α� ��ǥ�� ������ ��� ��ǥ�� ��ȯ�Ѵ�.
	POINT getBoardPoint(int ox, int oy);
public:
	virtual ~Domino(void);

	static Domino& GetInstance(){
		static Domino domino;

		return domino;
	}
	// ������ ��� Ÿ���� �����Ѵ�.
	void selectBlockType(BLOCK_TYPE blockType);

	// ���̳� ���带 �׸���.
	void drawBoard(void);

	// Ÿ�Ͽ� ����� �����Ѵ�.
	bool putBlockOnTile(int x, int y);

	// Ÿ�Ͽ� ���� ����� �����Ѵ�.
	bool putStartOnTile(int x, int y);

	Board		m_board;
	BLOCK_TYPE	m_selectBlockType;		// ������ �� Ÿ��
	bool		m_start;				// ������ ���ۿ���

public:
	// ���̳븦 �����Ѵ�.
	void start(void);
public:
	// ��������� �ʱ�ȭ
	void reset(void);
	
	// ����� �����.
	void stand(void);

public:
	CTerm_DominoDlg* m_pDlg;
};

#define g_domino Domino::GetInstance()