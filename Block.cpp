#include "stdafx.h"
#include "Block.h"

Block::Block(void)
{
	m_type = TYPE0;
	m_color = RED_COLOR;
	m_power = NO_POWER;
//	m_area = NO_AREA;

	m_position[0] = 0.0f;
	m_position[1] = 0.0f;
}

Block::~Block(void)
{
}

void Block::draw(void)
{
	// Ÿ�� ����
	if(m_type == TYPE0)
		return;
	glPopMatrix();
	glPushMatrix();
	glTranslatef(m_position[0]+BLOCK_SIZE_X/2,m_position[1]+BLOCK_SIZE_Y/2,0.0f);

	// ���� ���� ȸ���Ͽ� �����ϱ� ���� BLOCK_SIZE_Y/2��ŭ Z��ǥ�� ���� �̵��Ѵ�.
	if(m_power != NO_POWER)
		glTranslatef(0.0f,0.0f,BLOCK_SIZE_Y/2);

	// ���� ���� ���� ó��
	switch(m_power)
	{
	case NO_POWER:
		// ������ Ÿ��
		switch(m_type)
		{
		case TYPE1: // ����
			break;
		case TYPE2: // ����
			glRotatef(-90.0f,0.0f,0.0f,1.0f);
			break;
		case TYPE3: // �������
			glRotatef(45.0f,0.0f,0.0f,1.0f);
			break;
		case TYPE4: // �»����
			glRotatef(-45.0f,0.0f,0.0f,1.0f);
			break;
		}
		break;
	case LEFT_POWER:
		glRotatef(-90.0f,0.0f,0.0f,1.0f);
		glRotatef(70.0f,1.0f,0.0f,0.0f);
		break;
	case TL_POWER:
		glRotatef(-135.0f,0.0f,0.0f,1.0f);
		glRotatef(75.0f,1.0f,0.0f,0.0f);
		break;
	case TOP_POWER:
		glRotatef(180.0f,0.0f,0.0f,1.0f);
		glRotatef(70.0f,1.0f,0.0f,0.0f);
		break;
	case TR_POWER:
		glRotatef(135.0f,0.0f,0.0f,1.0f);
		glRotatef(75.0f,1.0f,0.0f,0.0f);
		break;
	case RIGHT_POWER:
		glRotatef(90.0f,0.0f,0.0f,1.0f);
		glRotatef(70.0f,1.0f,0.0f,0.0f);
		break;
	case BR_POWER:
		glRotatef(45.0f,0.0f,0.0f,1.0f);
		glRotatef(75.0f,1.0f,0.0f,0.0f);
		break;
	case BOTTOM_POWER:
		glRotatef(70.0f,1.0f,0.0f,0.0f);
		break; 
	case BL_POWER:
		glRotatef(-45.0f,0.0f,0.0f,1.0f);
		glRotatef(75.0f,1.0f,0.0f,0.0f);
		break;
	}

	// ����� ������ ���Ѵ�.
	switch(m_color)
	{
	case RED_COLOR:
		glColor3f(1.0f,0.0f,0.0f);
		break;
	case ORANGE_COLOR:
		glColor3f(0.8f,0.2f,0.0f);
		break;
	case YELLOW_COLOR:
		glColor3f(0.5f,0.5f,0.0f);
		break;
	case GREEN_COLOR:
		glColor3f(0.1f,1.0f,0.0f);
		break;
	case PINK_COLOR:
		glColor3f(1.0f,0.2f,0.2f);
		break;
	case SKY_COLOR:
		glColor3f(0.1f,0.2f,0.7f);
		break;
	case BLUE_COLOR:
		glColor3f(0.3f,0.3f,0.7f);
		break;
	case WHITE_COLOR:
		glColor3f(1.0f,1.0f,1.0f);
		break;
	case GRAY_COLOR:
		glColor3f(0.3f,0.3f,0.3f);
		break;
	case BLACK_COLOR:
		glColor3f(0.0f,0.0f,0.0f);
		break;
	}

	drawNormalBlock();
}

// ����� ��ǥ�� �����Ѵ�
void Block::setPosition(GLfloat x, GLfloat y)
{
	m_position[0] = x;
	m_position[1] = y;
}

// ������ ����� �׸���
void Block::drawNormalBlock(void)
{
	GLfloat blcokVertex[8][3] = 
	{
		{-BLOCK_SIZE_X/2,BLOCK_SIZE_Y/2,BLOCK_SIZE_Z},{BLOCK_SIZE_X/2,BLOCK_SIZE_Y/2,BLOCK_SIZE_Z},
		{BLOCK_SIZE_X/2,-BLOCK_SIZE_Y/2,BLOCK_SIZE_Z},{-BLOCK_SIZE_X/2,-BLOCK_SIZE_Y/2,BLOCK_SIZE_Z},
		{-BLOCK_SIZE_X/2,BLOCK_SIZE_Y/2,0.0f},{BLOCK_SIZE_X/2,BLOCK_SIZE_Y/2,0.0f},
		{BLOCK_SIZE_X/2,-BLOCK_SIZE_Y/2,0.0f},{-BLOCK_SIZE_X/2,-BLOCK_SIZE_Y/2,0.0f},
	};
	// ����
	glBegin(GL_POLYGON);
	glNormal3f(0.0f,0.0f,1.0f);
	glVertex3f(blcokVertex[0][0],blcokVertex[0][1],blcokVertex[0][2]);
	glVertex3f(blcokVertex[1][0],blcokVertex[1][1],blcokVertex[1][2]);
	glVertex3f(blcokVertex[2][0],blcokVertex[2][1],blcokVertex[2][2]);
	glVertex3f(blcokVertex[3][0],blcokVertex[3][1],blcokVertex[3][2]);
	glEnd();

	// �Ʒ���
	glBegin(GL_POLYGON);
	glNormal3f(0.0f,0.0f,-1.0f);
	glVertex3f(blcokVertex[5][0],blcokVertex[5][1],blcokVertex[5][2]);
	glVertex3f(blcokVertex[4][0],blcokVertex[4][1],blcokVertex[4][2]);
	glVertex3f(blcokVertex[7][0],blcokVertex[7][1],blcokVertex[7][2]);
	glVertex3f(blcokVertex[6][0],blcokVertex[6][1],blcokVertex[6][2]);
	glEnd();

	// ����
	glBegin(GL_POLYGON);
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(blcokVertex[1][0],blcokVertex[1][1],blcokVertex[1][2]);
	glVertex3f(blcokVertex[0][0],blcokVertex[0][1],blcokVertex[0][2]);
	glVertex3f(blcokVertex[4][0],blcokVertex[4][1],blcokVertex[4][2]);
	glVertex3f(blcokVertex[5][0],blcokVertex[5][1],blcokVertex[5][2]);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(1.0f,0.0f,0.0f);
	glVertex3f(blcokVertex[2][0],blcokVertex[2][1],blcokVertex[2][2]);
	glVertex3f(blcokVertex[1][0],blcokVertex[1][1],blcokVertex[1][2]);
	glVertex3f(blcokVertex[5][0],blcokVertex[5][1],blcokVertex[5][2]);
	glVertex3f(blcokVertex[6][0],blcokVertex[6][1],blcokVertex[6][2]);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0.0f,-1.0f,0.0f);
	glVertex3f(blcokVertex[3][0],blcokVertex[3][1],blcokVertex[3][2]);
	glVertex3f(blcokVertex[2][0],blcokVertex[2][1],blcokVertex[2][2]);
	glVertex3f(blcokVertex[6][0],blcokVertex[6][1],blcokVertex[6][2]);
	glVertex3f(blcokVertex[7][0],blcokVertex[7][1],blcokVertex[7][2]);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(-1.0f,0.0f,0.0f);
	glVertex3f(blcokVertex[0][0],blcokVertex[0][1],blcokVertex[0][2]);
	glVertex3f(blcokVertex[3][0],blcokVertex[3][1],blcokVertex[3][2]);
	glVertex3f(blcokVertex[7][0],blcokVertex[7][1],blcokVertex[7][2]);
	glVertex3f(blcokVertex[4][0],blcokVertex[4][1],blcokVertex[4][2]);
	glEnd();
}

void Block::setPower(BLOCK_POWER power)
{
	m_power = power;
}

// ����� ���� �����Ѵ�.
void Block::setColor(BLOCK_COLOR color)
{
	m_color = color;
}

// ����� ������ �����Ѵ�.
void Block::setType(BLOCK_TYPE type)
{
	m_type = type;
}

// ����� ������ ��ȯ�Ѵ�.
BLOCK_TYPE Block::getType(void)
{
	return m_type;
}
// �ܺ����� ��Ͽ� ��ġ�� �Ŀ��� ���Ѵ�.
BLOCK_POWER Block::externalPowerToBlock(BLOCK_POWER power)
{
	// Ÿ���� ���� ��� ��ġ�� ���� ����.
	if(m_type == TYPE0)
		return NO_POWER;

	// ���� ���� ���ٸ� �ٸ� ��Ͽ� ��ġ�� ���� ����.
	if(power == NO_POWER)		
		return NO_POWER;

	// �ڽ��� ���� ���� ���� ó��
	switch(power)
	{
	case LEFT_POWER:	// 
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			if(rand()%2 == 0)
				return TOP_POWER;
			else
				return BOTTOM_POWER;
		case TYPE2: // ���� Ÿ��
			return LEFT_POWER;
		case TYPE3: // ������� Ÿ��
			return TL_POWER;
		case TYPE4: // �����»� Ÿ��
			return BL_POWER;
		}
	case TL_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return TOP_POWER;
		case TYPE2: // ���� Ÿ��
			return LEFT_POWER;
		case TYPE3: // ������� Ÿ��
			return TL_POWER;
		case TYPE4: // �����»� Ÿ��
			if(rand()%2 == 0)
				return TR_POWER;
			else
				return BL_POWER;
		}
	case TOP_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return TOP_POWER;
		case TYPE2: // ���� Ÿ��
			if(rand()%2 == 0)
				return LEFT_POWER;
			else
				return RIGHT_POWER;
		case TYPE3: // ������� Ÿ��
			return TL_POWER;
		case TYPE4: // �����»� Ÿ��
			return TR_POWER;
		}
	case TR_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return TOP_POWER;
		case TYPE2: // ���� Ÿ��
			return RIGHT_POWER;
		case TYPE3: // ������� Ÿ��
			if(rand()%2 == 0)
				return TL_POWER;
			else
				return BR_POWER;
		case TYPE4: // �����»� Ÿ��
			return TR_POWER;
		}
	case RIGHT_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			if(rand()%2 == 0)
				return TOP_POWER;
			else
				return BOTTOM_POWER;
		case TYPE2: // ���� Ÿ��
			return RIGHT_POWER;
		case TYPE3: // ������� Ÿ��
			return BR_POWER;
		case TYPE4: // �����»� Ÿ��
			return TR_POWER;
		}
	case BR_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return BOTTOM_POWER;
		case TYPE2: // ���� Ÿ��
			return RIGHT_POWER;
		case TYPE3: // ������� Ÿ��
			return BR_POWER;
		case TYPE4: // �����»� Ÿ��
			if(rand()%2 == 0)
				return TR_POWER;
			else
				return BL_POWER;
		}
	case BOTTOM_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return BOTTOM_POWER;
		case TYPE2: // ���� Ÿ��
			if(rand()%2 == 0)
				return LEFT_POWER;
			else
				return RIGHT_POWER;
		case TYPE3: // ������� Ÿ��
			return BR_POWER;
		case TYPE4: // �����»� Ÿ��
			return BL_POWER;
		}
	case BL_POWER:
		switch(m_type)
		{
		case TYPE1: // ���� Ÿ��
			return BOTTOM_POWER;
		case TYPE2: // ���� Ÿ��
			return LEFT_POWER;
		case TYPE3: // ������� Ÿ��
			if(rand()%2 == 0)
				return TL_POWER;
			else
				return BR_POWER;
		case TYPE4: // �����»� Ÿ��
			return BL_POWER;
		}
	}

	// ����...
	return NO_POWER;
}

BLOCK_POWER Block::getPower()
{
	return m_power;
}