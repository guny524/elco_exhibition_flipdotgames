#include"common.h"
#include"snake.h"
#include"typing.h"
#include "i2c.h"

extern char g_arr[MAP_COL][MAP_ROW];
extern char g_arr_new[MAP_COL][MAP_ROW];
extern int g_key;
extern char g_buffer;
extern int fd_i2c;

int main()
{
	fd_i2c = raspi_i2c_set();
	clear();
	srand((unsigned int)time(NULL));
	g_key = 0;

	while (1)
	{
		printf("0.typing\n"); 
		printf("1.snake\n");
		printf("2.tetris\n");
		printf("3.car\n");

		g_key = getch();
		if (g_key == 'ESC')
			return;
		else if (g_key == '0')
		{
			run_typing();
		}
		else if (g_key == '1')
		{
			run_snake();
		}
		else if (g_key == '2')
		{
			run_snake();
		}
		else if (g_key == '3')
		{
			run_snake();
		}
	}
	return 0;
}