#include <stdio.h>
#include <string.h>
/*��������*/

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


//�ж�һ���ַ��Ƿ�����ĸ
int isLetter(char s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return 1;
	else
		return 0;
}

//�ж�һ���ַ��Ƿ�����ĸ������
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

//���һ��token��������token.string��
//���⣺���ַ�ΪEOFʱ��Ӧ����δ���
struct token getToken()
{
	char c;
	struct token temp;//��ʱ��������������token.
	char tempString[MAXTOKENLEN];
	while ((c = getc()) == ' ' || c == '\n' || c == '\t')
		;//�����ո񡢻س����Ʊ��
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
//����getToken()�Ƿ�����
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