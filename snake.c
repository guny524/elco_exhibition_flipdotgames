#include"display.h"
#include"snake.h"

int snake[MAP_ROW][MAP_COL] = { {0,} };
int apple_row;
int apple_col;

int snake_size;
int snake_head_row;
int snake_head_col;

void printmap()
{
	for (int i = 0; i < MAP_ROW; i++)
		print(i, 0);
	for (int i = 0; i < MAP_ROW; i++)
		print(i, MAP_COL);
	for (int i = 0; i < MAP_COL; i++)
		print(0, i);
	for (int i = 0; i < MAP_COL; i++)
		print(MAP_ROW, i);
}
void init_snake()
{
	snake_head_row = rand() % (MAP_ROW - 1) + 1;
	snake_head_col = rand() % (MAP_COL - 1) + 1;
	snake[snake_head_row][snake_head_col] = 1;
	snake_size = 1;
}
void print_snake()
{
	for (int i = 0; i < MAP_ROW; i++)
		for (int j = 0; j < MAP_COL; j++)
			if (snake[i][j])
				print(i,j);
}
void init_apple()
{
	apple_row = rand() % (MAP_ROW - 1) + 1;
	apple_col = rand() % (MAP_COL - 1) + 1;
}
void print_apple()
{
	print(apple_row, apple_col);
}
int is_crash()
{
	;
}
int is_collide()
{
	;
}
void run_snake()
{
	printmap();
	printf("\n");
	init_snake();
	init_apple();

	while (1)
	{
		print_apple();
		print_snake();
		SLEEP();

		GETKEY();
		if (key == 0x1b)	//ESC
			break;

		//key_check
		//collide_check
		//move
		
	}
}