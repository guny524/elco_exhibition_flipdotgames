#pragma once

#define ISWINDOW 1

#define MAP_ROW 12
#define MAP_COL 16

#include<stdio.h>
#include<stdlib.h>	//rand(), srand();
#include<time.h>	//time(NULL);

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

void commute_init();
void clear();
void send_arr();
void wait();