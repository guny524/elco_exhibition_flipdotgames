#include"display.h"
#include"snake.h"

int snake[MAP_ROW][MAP_COL] = { {0,} };
int apple_row = 0;
int apple_col = 0;

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
	snake[rand() % (MAP_ROW-1)+1][rand() % (MAP_COL-1)+1] = 1;
}
void print_snake()
{
	for (int i = 0; i < MAP_ROW; i++)
		for (int j = 0; j < MAP_COL; j++)
			if (snake[i][j])
				print(i,j);
}
void print_apple()
{
	print(apple_row, apple_col);
}
void init_apple()
{
	apple_row = rand() % (MAP_ROW - 1) + 1;
	apple_col = rand() % (MAP_COL - 1) + 1;
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
#if ISWINDOW
		Sleep(1000);
#else
		sleep(1);
#endif
		while (kbhit())
			key = getch();
		printf("%c", key);
		if (key == 0x1b)
			break;
	}
}