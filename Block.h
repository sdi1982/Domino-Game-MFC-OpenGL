#pragma once

#include "define.h"

class Block
{
private:
	BLOCK_TYPE m_type;
	BLOCK_COLOR m_color;
	GLfloat m_position[2];
	BLOCK_POWER m_power;
//	BLOCK_AREA m_area;
	// �Ϲ� ����� �׸���
	void drawNormalBlock(void);
public:
	Block(void);
	virtual ~Block(void);

	// ����� �׸���.
	void draw(void);

	// ����� ��ǥ�� �����Ѵ�.
	void setPosition(GLfloat x, GLfloat y);

	// ����� ���� �����Ѵ�.
	void setColor(BLOCK_COLOR color);

	// ����� �޴� ���� �����Ѵ�.
	void setPower(BLOCK_POWER power);

	// ����� �޴� ���� ��ȯ�Ѵ�.
	BLOCK_POWER getPower();

	// ����� ������ �����Ѵ�
	void setType(BLOCK_TYPE type);

	// ����� ������ ��ȯ�Ѵ�.
	BLOCK_TYPE getType(void);

	// �ܺ����� ��Ͽ� ��ġ�� �Ŀ��� ���Ѵ�.
	BLOCK_POWER externalPowerToBlock(BLOCK_POWER power);
};
