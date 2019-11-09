#pragma once

typedef struct Coordinate {
	int row, col;
}coor;
typedef struct Snake {
	coor arr[MAP_COL * MAP_ROW];
	int size;
}snake;

void init_map(int map[MAP_COL][MAP_ROW]);
void init_snake(snake *s);
void init_feed(coor *f);
void merge_arr(int map[MAP_COL][MAP_ROW], snake *s, coor *f);
int is_crash();
int is_collide();
void run_snake();