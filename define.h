#pragma once
#include <gl\gl.h>

//#include <gl\glaux.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

const int TILE_WIDTH = 20;
const int TILE_HEIGHT = 20;
const int DELAY_TIME = 300;

const GLfloat TILE_SIZE_X = 3.0f;
const GLfloat TILE_SIZE_Y = 3.0f;

enum TILE_TYPE { NORMAL, START};

const GLfloat BLOCK_SIZE_X = 2.0f;
const GLfloat BLOCK_SIZE_Y = 1.0f;
const GLfloat BLOCK_SIZE_Z = 4.0f;

// Ÿ�� ����, ����, ����, �������, �»���� Ÿ��
enum BLOCK_TYPE { TYPE0, TYPE1, TYPE2,TYPE3, TYPE4 };
enum BLOCK_COLOR { RED_COLOR = 0, YELLOW_COLOR, GREEN_COLOR, BLUE_COLOR, WHITE_COLOR, BLACK_COLOR, ORANGE_COLOR, PINK_COLOR,
SKY_COLOR, GRAY_COLOR, MAX_COLOR};
enum BLOCK_POWER { NO_POWER, LEFT_POWER, TL_POWER, TOP_POWER, TR_POWER, RIGHT_POWER, BR_POWER, BOTTOM_POWER, BL_POWER};
// enum BLOCK_AREA { NO_AREA, LEFT_AREA, TOP_AREA, RIGHT_AREA, BOTTOM_AREA, BL_AREA, TL_AREA, TR_AREA,	BR_AREA};
