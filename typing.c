#include"display.h"
#include"typing.h"

void typing(char key)
{
	if (key == 0x08)	//BackSpace
	{
		printf("BACK");
	}
}
void typing_str(const char* str)
{
	printf(str);
}
void run_typing()
{
	typing_str("TYPING!!!!\n");
	while (1)
	{
		GETKEY();
		if (key == 0x1b)	//ESC
			break;
		else
		{
			printf("%c", key);
		}
	}
}