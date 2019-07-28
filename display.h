#pragma once

#define ISWINDOW 1

#if ISWINDOW
#include<windows.h>
#else
#include<termios.h>
#include<unistd.h>
#include<sys/ioctl.h>
int getch(void);
_Bool kbhit();
#endif

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void gotoxy(int x, int y);
void print(int x, int y);

char key;

#if ISWINDOW
#define CLEAR(); system("cls");
#else
#define CLEAR(); system("clear");
#endif

#if ISWINDOW
#define SLEEP(); Sleep(1000);
#else
#define SLEEP(); sleep(1);
#endif

#if ISWINDOW
#define GETKEY(); while (kbhit()) key = getch();
#else
#define GETKEY(); printf("implement GETKEY"); exit(1);
#endif

