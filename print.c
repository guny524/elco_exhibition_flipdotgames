 #include<stdio.h>
 #include<stdlib.h>
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
int main()
{
	system("clear");
	gotoxy(2,3);
	printf("*");
	gotoxy(1,3);
	printf("*\n");
	return 0;
}
