#pragma once

#include "define.h"

class Tile
{
private:
	GLfloat		m_position[2];
	TILE_TYPE	m_type;
	BLOCK_POWER m_power;

	// ���� Ÿ���� ȭ��ǥ�� �׸���.
	void drawArrow();

	void drawStartTile();
public:
	Tile(void);
	virtual ~Tile(void);
	
	// Ÿ���� �׸���.
	void draw(void);

	// Ÿ���� ��ǥ�� �����Ѵ�
	void setPosition(GLfloat x, GLfloat y);

	// Ÿ���� Ÿ���� �����Ѵ�.
	void setType(TILE_TYPE type);

	// ���� Ÿ���� �Ŀ��� �����Ѵ�.
	void setPower(BLOCK_POWER power);

};
