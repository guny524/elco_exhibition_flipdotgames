#ifndef _DISPLAY_H__

#define _DISPLAY_H__

#include"osname.h"
#include"i2c.h"

int get_key();
void display(char arr[MAP_COL][MAP_ROW]);
void clear(char arr[MAP_COL][MAP_ROW]);
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