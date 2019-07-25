#define ISWINDOW 1
#include<stdio.h>
#include<stdlib.h>
#if ISWINDOW
#include<windows.h>
#else
#include<termios.h>
#include<unistd.h>
#include<sys/ioctl.h>
int getch(void)
{
	struct termios oldt, newt;
	int ch;

	tcgetattr(0, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(0, TCSANOW, &newt);

	ch = getchar();
        tcsetattr(0, TCSANOW, &oldt);
	return ch;
}
_Bool kbhit()
{
	struct termios term;
	tcgetattr(0, &term);
	struct termios term2 = term;
	term2.c_lflag &= ~ICANON;
	tcsetattr(0, TCSANOW, &term2);

	int byteswaiting;
	ioctl(0, FIONREAD, &byteswaiting);
        tcsetattr(0, TCSANOW, &term);
	return byteswaiting > 0;
}
#endif
#include<time.h>

#define MAP_ROW 12
#define MAP_COL 16

void gotoxy(int x, int y);
void print(int x, int y);

int snake[MAP_ROW][MAP_COL] = { {0,} };
int apple_row = 0;
int apple_col = 0;

void gotoxy(int x, int y)
{
#if ISWINDOW
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
	printf("%c[%d;%df", 0x1B, y, x);
#endif
}
void print(int x, int y)
{
	gotoxy(x,y);
	printf("*");
}
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
int main()
{
#if ISWINDOW
	system("cls");
#else
	system("clear");
#endif
	srand((unsigned int)time(NULL));
	char key = 0;
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
	return 0;
}
