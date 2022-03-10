#include "stdafx.h"
#include "Board.h"
//#include "../RevSound/SoundManager.h"

//extern HWND g_hDlg;

//using namespace rev;

Board::Board(void)
{
	srand((unsigned int)time(NULL));
	for(int w = 0; w <TILE_WIDTH; w++)
	{
		for(int h = 0; h <TILE_HEIGHT; h++)
		{
			GLfloat x = -TILE_SIZE_X*TILE_WIDTH/2 + w*TILE_SIZE_X;
			GLfloat y = -TILE_SIZE_Y*TILE_HEIGHT/2 + h*TILE_SIZE_Y;
			m_tile[w][h].setPosition(x, y);
			m_block[w][h].setPosition(x+(GLfloat)((TILE_SIZE_X-BLOCK_SIZE_X)/2),y+(GLfloat)((TILE_SIZE_Y-BLOCK_SIZE_Y)/2));
		}
	}

	m_startTile.x = 0;
	m_startTile.y = 0;
	m_startPower = TL_POWER;

	setStartTile(m_startTile.x,m_startTile.x);
}

Board::~Board(void)
{
}

// Ÿ�Ͽ� ����� ���´�
void Board::setBlockOnTile(POINT pos, BLOCK_TYPE type)
{
	BLOCK_COLOR color = (BLOCK_COLOR)(rand()%MAX_COLOR);
	m_block[pos.x][pos.y].setColor(color);
	m_block[pos.x][pos.y].setType(type);
	m_block[pos.x][pos.y].setPower(NO_POWER);
}

// ���� ����� �����ϴ��� Ȯ���Ѵ�.
bool Board::isNextBlock(POINT index, BLOCK_POWER power)
{
	switch(power)
	{
	case NO_POWER:
		return false;
	case LEFT_POWER:
		if(index.x == 0)
			return false;
		else
			return true;
	case TL_POWER:
		if((index.x == 0)||(index.y == (TILE_HEIGHT -1)))
			return false;
		else
			return true;
	case TOP_POWER:
		if(index.y == (TILE_HEIGHT -1))
			return false;
		else
			return true;
	case TR_POWER:
		if((index.x == (TILE_WIDTH - 1))||(index.y == (TILE_HEIGHT -1)))
			return false;
		else
			return true;
	case RIGHT_POWER:
		if(index.x == (TILE_WIDTH - 1))
			return false;
		else
			return true;
	case BR_POWER:
		if(index.x == (TILE_WIDTH - 1)||(index.y == 0))
			return false;
		else
			return true;
	case BOTTOM_POWER:
		if(index.y == 0)
			return false;
		else
			return true;
	case BL_POWER:
		if((index.y == 0)||(index.x == 0))
			return false;
		else
			return true;
	}
	return false; // ����
}

// ���� ���� �ε����� ���Ѵ�.
POINT Board::getNextIndex(POINT index, BLOCK_POWER power)
{
	POINT nextIndex;		// ���� ��� �ε���
	switch(power)
	{
	case NO_POWER:		// ���� ����� ���ٸ� ... ����...
		nextIndex.x = index.x;
		nextIndex.y = index.y;
		break;
	case LEFT_POWER:
		nextIndex.x = index.x - 1;
		nextIndex.y = index.y;
		break;
	case TL_POWER:
		nextIndex.x = index.x - 1;
		nextIndex.y = index.y + 1;
		break;
	case TOP_POWER:
		nextIndex.x = index.x;
		nextIndex.y = index.y + 1;
		break;
	case TR_POWER:
		nextIndex.x = index.x + 1;
		nextIndex.y = index.y + 1;
		break;
	case RIGHT_POWER:
		nextIndex.x = index.x + 1;
		nextIndex.y = index.y;
		break;
	case BR_POWER:
		nextIndex.x = index.x + 1;
		nextIndex.y = index.y - 1;
		break;
	case BOTTOM_POWER:
		nextIndex.x = index.x;
		nextIndex.y = index.y - 1;
		break;
	case BL_POWER:
		nextIndex.x = index.x - 1;
		nextIndex.y = index.y - 1;
		break;
	}

	return nextIndex;
}

// ���̳� �������� �ѹ��� ó�� ...ó���� �������� ���θ� �����Ѵ�.
bool Board::startUpdate()
{
	gluLookAt(-TILE_SIZE_X*TILE_WIDTH/2,-TILE_SIZE_Y*TILE_HEIGHT/2,TILE_SIZE_Y*TILE_HEIGHT/2, 
				TILE_SIZE_X*TILE_WIDTH/2,TILE_SIZE_Y*TILE_HEIGHT/2,0.0f,
			0.33f,0.33f,0.33f);

	glTranslatef(-tile.x*TILE_SIZE_X,-tile.y*TILE_SIZE_Y,10.0f);

	// �ܺ��� ���� ��Ͽ� ��ġ�� ���� ���� ���Ѵ�.
	power = m_block[tile.x][tile.y].externalPowerToBlock(power);

	// ��Ͽ� ���� �����Ѵ�. --- ����� �Ѿ�����.
	m_block[tile.x][tile.y].setPower(power);

	// ���� ��ġ�� Ÿ�� ������ �� ������ ������.
	if(!isNextBlock(tile, m_block[tile.x][tile.y].getPower()))
		return true;

	// ���� Ÿ���� �ε����� ���Ѵ�.
	POINT next = getNextIndex(tile, power);

	// ���� Ÿ�� ��ġ�� Ÿ���� ������ ������.
	if(m_block[next.x][next.y].getType() == TYPE0)
		return true;

	// ���� Ÿ���� �̹� ���� �޾�����(����������)...������.
	if(m_block[next.x][next.y].getPower() != NO_POWER)
		return true;

	// �� ���� ��� �̸�... ������ ����� �ִ� ����̴�.
	tile = next;
	// ���� Ÿ�Ϸ� �����ϱ����� ���� �ð��� �д�.
	Sleep(DELAY_TIME);

//	getSoundManager()->play("block");
	return false;
}

// ���̳븦 �����߸���.
void Board::start(void)
{
	tile.x = m_startTile.x;
	tile.y = m_startTile.y;
	power = m_startPower;
}

// Ÿ�ϵ��� �׸���.
void Board::draw(void)
{
	for(int w = 0; w <TILE_WIDTH; w++)
	{
		for(int h = 0; h <TILE_HEIGHT; h++)
		{
			m_tile[w][h].draw();
			m_block[w][h].draw();
		}
	}

	//glPopMatrix();
	//// �߽����� ���� �׸���.
	//glLineWidth(3.0f);
	//glBegin(GL_LINES);
	////glColor3f(1.0f,0.0f,0.0f);
	////glVertex3f(0.0f,0.0f,0.0f);
	////glVertex3f(TILE_SIZE_X*TILE_WIDTH,0.0f,0.0f);
	////glColor3f(0.0f,1.0f,0.0f);
	////glVertex3f(0.0f,0.0f,0.0f);
	////glVertex3f(0.0f,TILE_SIZE_Y*TILE_HEIGHT,0.0f);
	//glColor3f(0.0f,1.0f,0.0f);
	//glVertex3f(0.0f,0.0f,0.0f);
	//glVertex3f(0.0f,0.0f,30.0f);
	//glEnd();

//	m_tile[0][0].draw();
}

// �ش��ϴ� �ε����� ����� �����Ѵ�.
Block& Board::getBlock(int x, int y)
{
	if((x < 0)||(x > TILE_WIDTH ) || (y < 0)||(y > TILE_HEIGHT ))
//		MessageBox(g_hDlg,"�߸��� �� �ε��� �Դϴ�.",NULL,NULL);
	
	return m_block[x][y];
}

// ���� Ÿ�� �ε��� ��ǥ�� �����Ѵ�
void Board::setStartTile(int x, int y)
{
	// ���� ���� Ÿ���� �Ϲ� Ÿ�Ϸ� �ٲ۴�.
	m_tile[m_startTile.x][m_startTile.y].setType(NORMAL);
	m_tile[m_startTile.x][m_startTile.y].setPower(NO_POWER);

	m_startTile.x = x;
	m_startTile.y = y;
	m_tile[m_startTile.x][m_startTile.y].setType(START);

	switch(m_startPower)
	{
	case LEFT_POWER:
		m_startPower = TL_POWER;
		break;
	case TL_POWER:
		m_startPower = TOP_POWER;
		break;
	case TOP_POWER:
		m_startPower = TR_POWER;
		break;
	case TR_POWER:
		m_startPower = RIGHT_POWER;
		break;
	case RIGHT_POWER:
		m_startPower = BR_POWER;
		break;
	case BR_POWER:
		m_startPower = BOTTOM_POWER;
		break;
	case BOTTOM_POWER:
		m_startPower = BL_POWER;
		break;
	case BL_POWER:
		m_startPower = LEFT_POWER;
		break;
	default:
		m_startPower = TOP_POWER;
		break;
	}
	m_tile[m_startTile.x][m_startTile.y].setPower(m_startPower);
}

void Board::reset(void)
{
	for(int w = 0; w <TILE_WIDTH; w++)
	{
		for(int h = 0; h <TILE_HEIGHT; h++)
		{
			m_block[w][h].setType(TYPE0);
			m_block[w][h].setPower(NO_POWER);
		}
	}
}

void Board::stand(void)
{
	for(int w = 0; w <TILE_WIDTH; w++)
	{
		for(int h = 0; h <TILE_HEIGHT; h++)
		{
			m_block[w][h].setPower(NO_POWER);
		}
	}
}
