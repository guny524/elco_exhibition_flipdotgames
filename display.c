#include"osname.h"
#include"display.h"
#include"frame.h"
#include<stdio.h>

void clear(char arr[MAP_ROW][MAP_COL])
{
	for (int i = 0; i < MAP_COL; i++)
		for (int j = 0; j < MAP_ROW; j++)
			arr[i][j] = 0;
}

#if ISWINDOW
#include<stdio.h>
void display(char arr[MAP_ROW][MAP_COL])
{
	for (int i = 0; i < MAP_COL; i++)
	{
		for (int j = 0; j < MAP_ROW; j++)
			printf("%d", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
void wait()
{
	Sleep(1500);	//1.5s
}
void waitm()
{
	Sleep(100);	//100ms
}
#else
void display(char arr[MAP_ROW][MAP_COL])
{
	frame_change(arr);
}
void waitm()
{
	usleep(100000);		//1.5s
}
void wait()
{
	usleep(1500000);	//100ms
}
/* Initialize new terminal i/o settings */
void initTermios(int echo) {
	struct termios old, current;
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	current = old; /* make new settings same as old settings */
	current.c_lflag &= ~ICANON; /* disable buffered i/o */
	if (echo) {
		current.c_lflag |= ECHO; /* set echo mode */
	}
	else {
		current.c_lflag &= ~ECHO; /* set no echo mode */
	}
	tcsetattr(0, TCSANOW, &current); /* use these new terminal i/o settings now */
} /* Read 1 character - echo defines echo mode */
char getch() {
	char ch;
	struct termios old;
	tcgetattr(STDIN_FILENO, &old);
	initTermios(0);	//echo 0
	ch = getchar();
	tcsetattr(0, TCSANOW, &old);	//reset Termios
	return ch;
}
int kbhit(void)
{
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF)
	{
		ungetc(ch, stdin);
		return 1;
	}

	return 0;
}
#endif