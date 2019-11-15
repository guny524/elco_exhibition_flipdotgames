#include"osname.h"
#include"display.h"
#include"snake.h"
#include"i2c.h"

char play = 1;

void excute(char arr[MAP_ROW][MAP_COL], char *key, int i, int j, int state)
{
	if (kbhit())
	{
		play = 0;
		*key = getch();
		while (kbhit())
			getch();
	}
	arr[i][j] = state;
	display(arr);
	waitm();
}

int main()
{
	char key=0;
	char arr[MAP_ROW][MAP_COL] = {0,};
	raspi_i2c_set();

	while (1)
	{
		for(int i=0;i<MAP_ROW;i++)
			for (int j = 0; j < MAP_ROW; j++)
				if(play)
					excute(arr, &key,i,j,1);
		for (int i = 0; i < MAP_ROW; i++)
			for (int j = 0; j < MAP_ROW; j++)
				if (play)
					excute(arr, &key, i, j, 0);

		if (kbhit())
		{
			key = getch();
			while (kbhit())
				getch();
		}
		if (key == 27)
			return 0;
		if (key != 0)
		{
			clear(arr);
			run_snake();
			key = 0;
			play = 1;
		}
	}
	return 0;
}