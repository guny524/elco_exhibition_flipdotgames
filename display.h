#pragma once

#define ISWINDOW 1
#include<stdio.h>
#include<stdlib.h>
#if ISWINDOW
#include<windows.h>
#else
#include<termios.h>
#include<unistd.h>
#include<sys/ioctl.h>
int getch(void);
_Bool kbhit();
#endif
#include<time.h>

void gotoxy(int x, int y);
void print(int x, int y);

extern char key;