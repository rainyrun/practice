#include <stdio.h>
#include <string.h>
/*声明翻译*/

#define MAXTOKENLEN 100
struct token {
	char type;
	char string[MAXTOKENLEN];
};

struct token stack[MAXTOKENLEN];
char charStack[MAXTOKENLEN];

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

int charsp = 0;
void pushc(char c)
{
	if (charsp < MAXTOKENLEN)
		charStack[charsp++] = c;
	else
		printf("charStack overflow.");
}

char popc()
{
	if (charsp > 0)
		return charStack[--charsp];
	else
		printf("the charStack is empty");
}


//判断一个字符是否是字母
int isLetter(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return 1;
	else
		return 0;
}

//判断一个字符是否是字母或数字
int isAlphaOrNumber(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9'))
		return 1;
	else
		return 0;
}

char getc()
{
	if (charsp == 0)
		return getchar();
	else
		return popc();
}

//获得一个token，并存在token.string内
//问题：当字符为EOF时，应该如何处理？
struct token getToken()
{
	char c;
	struct token temp;//临时变量，用来返回token.
	char tempString[MAXTOKENLEN];
	while ((c = getc()) == ' ' || c == '\n' || c == '\t')
		;//跳过空格、回车、制表符
	if (isLetter(c))
	{
		int i = 0;
		tempString[i++] = c;
		c = getc();
		while (isAlphaOrNumber(c))
		{ 
			tempString[i++] = c;
			c = getc();
		}
		pushc(c);
		tempString[i] = '\0';
		strcpy(temp.string, tempString);
	}
	else
	{
		tempString[0] = c;
		tempString[1] = '\0';
		strcpy(temp.string, tempString);
	}
	return temp;
}

//
//测试getToken()是否能用
void main()
{
	struct token test;
	test = getToken();
	char *s = test.string;
	while (!strcmp(s,"0"))
	{
		printf("test.string = %s.\n", test.string);
		test = getToken();
	}
}