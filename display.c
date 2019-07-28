#include"display.h"

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
	gotoxy(x, y);
	printf("*");
}
#if ISWINDOW
#else
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