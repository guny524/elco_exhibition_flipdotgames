#include"osname.h"
#include"display.h"
#include"i2c.h"

void clear()
{
	for (int i = 0; i < MAP_COL; i++)
		for (int j = 0; j < MAP_ROW; j++)
			g_arr[i][j] = 0;
	display();
}
int get_key()
{
	int key;
	if (kbhit())
	{
		key = getch();
		while (kbhit())
			getch();
	}
	return key;
}

#if ISWINDOW
void display()
{
	for (int i = 0; i < MAP_COL; i++)
		for (int j = 0; j < MAP_ROW; j++)
			printf("%d ", g_arr[i][j]);
}
void wait()
{
	Sleep(1000);
}
#else
void display()
{

}
void wait()
{
	sleep(1);
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