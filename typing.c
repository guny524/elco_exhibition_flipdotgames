#include"display.h"
#include"typing.h"

void typing(char key)
{
	switch (key)
	{
		case 0x08:	//BackSpace
			printf("BACK");
			break;
		default:
			printf("%c",key);
			break;
	}
}
void typing_str(char *str)
{
	char *ch = str;
	while(*ch != '\0')
		typing(*(ch++));
}
void run_typing()
{
	clear();
	typing_str("TYPING!!!!\n");
	while (1)
	{
		g_key = getch();
		if (g_key == 0x1b)	//ESC
			break;
		else
			typing(g_key);
	}
}