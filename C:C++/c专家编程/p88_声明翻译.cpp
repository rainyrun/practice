#include <stdio.h>
/*ЩљУїЗ­вы*/

#define MAXTOKENLEN 100
struct token {
	char type;
	char string[MAXTOKENLEN];
};

struct token stack[MAXTOKENLEN];

int stacksp = 0;
void push(struct token s)
{
	if (stacksp < MAXTOKENLEN)
		stack[stacksp++] = s;
	else
		printf("stack overflow.");
}

struct token pop()
{
	if (stacksp > 0)
		return stack[--stacksp];
	else
		printf("the stack is empty");
}

int isLetter(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return 1;
	else
		return 0;
}

int isAlphaOrNumber(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
		return 1;
	else
		return 0;
}

struct token getToken()
{
	char c;
	struct token temp;
	char tempString[MAXTOKENLEN];
	c = getchar();
	if (isLetter(c))
	{
		int i = 0;
		tempString[i++] = c;
		c = getchar();
		while (isAlphaOrNumber(c))
		{ 
			tempString[i++] = c;
			c = getchar();
		}
		tempString[i] = '\0';
		temp.string = tempString;
	}
	else
		temp.string = tempString;
		
}
