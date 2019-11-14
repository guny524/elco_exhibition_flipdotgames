#ifndef _SNAKE_H__
#define _SNAKE_H__

#include"osname.h"

typedef struct Coordinate {
	int row, col;
}coor;
typedef struct Snake {
	coor arr[MAP_COL * MAP_ROW];
	int size;
}snake;

void run_snake();

#endif