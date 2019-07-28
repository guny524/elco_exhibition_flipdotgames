#include"display.h"
#include"snake.h"

char key = 0;
int main()
{
#if ISWINDOW
	system("cls");
#else
	system("clear");
#endif
	srand((unsigned int)time(NULL));

	printf("1.snake");
	printf("2.tetris");
	printf("3.car");
	printf("ESC: quit");

	while (1)
	{
		while (kbhit())
			key = getch();
		if (key == '1')
			run_snake();
		else if (key == 0x1b)
			break;
	}
	return 0;
}