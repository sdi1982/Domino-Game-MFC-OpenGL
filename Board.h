#pragma once

#include "define.h"
#include "Tile.h"
#include "Block.h"

class Board
{
private:
	Tile			m_tile[TILE_WIDTH][TILE_HEIGHT];
	Block			m_block[TILE_WIDTH][TILE_HEIGHT];

	POINT			m_startTile;			// ���� Ÿ�� �ε��� ��
	BLOCK_POWER		m_startPower;			// ���� Ÿ�� ��

	POINT			tile;					// �������� Ÿ���� ������ �ӽ� ����
	BLOCK_POWER		power;

	// ���� ����� �����ϴ��� Ȯ���Ѵ�.
	bool isNextBlock(POINT index, BLOCK_POWER power);

	// ���� ���� �ε����� ���Ѵ�.
	POINT getNextIndex(POINT index, BLOCK_POWER power);
public:
	Board(void);
	virtual ~Board(void);

	// Ÿ�Ͽ� ����� ���´�
	void setBlockOnTile(POINT pos, BLOCK_TYPE type);

	// ���̳븦 �����߸���.
	void start(void);

	// Ÿ�ϵ��� �׸���.
	void draw(void);

	// ���̳� �������� �ѹ��� ó��
	bool startUpdate();

	// �ش��ϴ� �ε����� ����� �����Ѵ�.
	Block& getBlock(int x, int y);

	// ���� Ÿ�� �ε��� ��ǥ�� �����Ѵ�
	void setStartTile(int x, int y);

	// ��� �������� �ʱ�ȭ�Ѵ�.
	void reset(void);
public:
	void stand(void);
};