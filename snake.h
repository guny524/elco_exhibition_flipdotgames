#pragma once

#define MAP_ROW 12
#define MAP_COL 16

extern int snake[MAP_ROW][MAP_COL];
extern int apple_row;
extern int apple_col;

void printmap();
void init_snake();
void print_snake();
void print_apple();
void init_apple();
void run_snake();