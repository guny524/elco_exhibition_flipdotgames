#include"display.h"
#include"snake.h"

int main()
{
	CLEAR();
	srand((unsigned int)time(NULL));

	printf("1.snake\n");
	printf("2.tetris\n");
	printf("3.car\n");
	printf("ESC: quit\n");

	while (1)
	{
		run_typing();
		GETKEY();
		if (key == '1')	//ESC
		{
			CLEAR();
			run_snake();
		}
	}
	return 0;
}