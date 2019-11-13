#include<stdio.h>
#include<stdlib.h>	//rand(), srand();
#include<time.h>	//time(NULL);

#include"display.h"
#include"snake.h"
#include"i2c.h"

void init_map(int map[MAP_COL][MAP_ROW])
{
	for (int i = 0; i < MAP_COL; i++)
		for (int j = 0; j < MAP_ROW; j++)
			map[i][j] = 0;

	for (int i = 0; i < MAP_COL; i++)
		map[i][0] = 1;
	for (int i = 0; i < MAP_COL; i++)
		map[i][MAP_ROW-1] = 1;
	for (int i = 0; i < MAP_ROW; i++)
		map[0][i] = 1;
	for (int i = 0; i < MAP_ROW; i++)
		map[MAP_COL-1][i] = 1;
}
void init_snake(snake *s)
{
	s->arr[0].col = rand() % (MAP_COL - 1) + 1;
	s->arr[0].row = rand() % (MAP_ROW - 1) + 1;
	s->size = 1;
}
void init_feed(coor *feed)
{
	feed->col = rand() % (MAP_COL - 1) + 1;
	feed->row = rand() % (MAP_ROW - 1) + 1;
}
void merge_arr(int map[MAP_COL][MAP_ROW], snake *s, coor *feed)
{
	for (int i = 0; i < MAP_COL; i++)
		for (int j = 0; j < MAP_ROW; j++)
			g_arr[i][j] = map[i][j];	//�� ǥ��
	for (int i = 0; i < s->size; i++)
		g_arr[s->arr[i].col][s->arr[i].row] = 1;
	g_arr[feed->col][feed->row] = 1;
}
void move(snake *s, char key)	//����ĭ �Ӹ����� Ű���� �������� �̵�
{
	coor tmp_head = s->arr[0];	//�ϴ� �Ӹ� ����
	for (int i=0;i<s->size-1;i++)	//�Ӹ� �������� �������⿡ �ִ°� �� ���ܿ�
		s->arr[i] = s->arr[i+1];
	switch(key)	//����� �Ӹ� �̵�
	{
	case 'a':
		s->arr[0].row--;
		break;
	case 'w':
		s->arr[0].col--;
		break;
	case 's':
		s->arr[0].col++;
		break;
	case 'd':
		s->arr[0].row++;
		break;
	}
}
int is_crash()	//with map?
{
	;
}
int is_collide()	//it self?
{
	;
}
int is_consume()	//with feed?
{
	;
}
void run_snake()
{
	char map[MAP_COL][MAP_ROW] = { {0,} };
	snake s = { 0, };
	coor feed = { 0, };
	snake tmp_s = { 0, };

	srand((unsigned int)time(NULL));
	g_key = 0;

	init_map(map);
	init_snake(&s);
	init_feed(&feed);

	merge_arr(map, &s, &feed);
	send_arr();

	while (1)
	{
		wait();
		get_key();
		if (g_key == 0x1b)	//ESC
			break;
		else if (g_key == 0)
		{

		}
		else
		{
			move(&s, g_key);

			//collide_check

			//move

			merge_arr(map, &s, &feed);
			send_arr();
		}
	}
}