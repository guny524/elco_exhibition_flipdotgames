#ifndef _DISPLAY_H__

#define _DISPLAY_H__

#include"osname.h"

char g_arr[MAP_COL][MAP_ROW];
int g_key = 0;

int get_key();
void display(char g_arr[MAP_COL][MAP_ROW]);
void clear();
void wait();

#if ISWINDOW
#include<windows.h>	//Sleep(1000);
#include<conio.h>	//getch();
#else
#include<termios.h>	//struct tertmios, tcgetattr(), tcsetattr();
#include<unistd.h>	//
#include<fcntl.h>	//fcntl();
static struct termios old, current;
void initTermios(int echo);
char getch();
int kbhit();

#endif

#endif