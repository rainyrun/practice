#include <stdio.h>
/*�����������[]��{}����������������ע�͵�������
 ˼·��
 1. ����1:���ü���������������������1��������������1���������ʱ������������0�������ȷ���
    ȱ�㣺���ܼ���[{]}���ִ������
 2. ����2:����ջ��������������ջ�������������鿴ջ��Ԫ���Ƿ�ƥ�䣬��ƥ���������飬��ƥ���򱨴�
 */

/*����1��ʵ��*/
//#define NUM 5
//int main()
//{
//	int pair[NUM];//��¼��������+1����-1���������ֵ������0����˵�����ڲ���Ե����
//	int c;
//
//	for (int i = 0; i < NUM; i++)
//	{
//		pair[i] = 0;
//	}
//
//	while ((c = getchar()) != EOF)
//	{
//		switch (c)
//		{
//		case '(': 
//			pair[0] += 1;
//			break;
//		case ')': 
//			pair[0] -= 1;
//			break;
//		case '[': 
//			pair[1] += 1;
//			break;
//		case ']': 
//			pair[1] -= 1;
//			break;
//		case '{': 
//			pair[2] += 1;
//			break;
//		case '}': 
//			pair[2] -= 1;
//			break;
//		case '\'': 
//			pair[3] += 1;
//			break;
//		case '"': 
//			pair[4] += 1;
//			printf("%d\n", pair[4]);
//			break;
//		default:
//			break;
//		}
//	}
//
//	if ((pair[0] == 0) && (pair[1] == 0) && (pair[2] == 0) && ((pair[3] % 2) == 0 ) && ((pair[4] % 2) == 0))
//	{
//		printf("()[]{}''\"\"is in pair in this program.\n");
//	}
//	if(pair[0] != 0)
//		if (pair[0] > 0)
//			printf("() is not in pair in this program. ( is %d more.\n", pair[0]);
//		else
//			printf("() is not in pair in this program. ) is %d more.\n", (0-pair[0]));
//	if (pair[1] != 0)
//		if (pair[0] > 0)
//			printf("[] is not in pair in this program. [ is %d more.\n", pair[1]);
//		else
//			printf("[] is not in pair in this program. ] is %d more.\n", (0 - pair[1]));
//	if ((pair[3] % 2) != 0)
//		printf("\' is not in pair in this program.");
//
//}

//����2��ʵ��
#define MAX 100
char pair[MAX];
char ungetc_stack[MAX];
int p = 0;
int ps = 0;
void push(char s) 
{
	if (p < MAX)
		pair[p++] = s;
	else
		printf("the stack if full.");
}

char pop()
{
	if (p > 0)
		return pair[--p];
	else
	{
		printf("the stack is empty.");
		return 0;
	}
}

void ungetc(char s)
{
	if (ps < MAX)
		ungetc_stack[ps++] = s;
	else
		printf("the ungetc_stack if full.");
}

char getc()
{
	if (ps > 0)
	{
		return ungetc_stack[--ps];
	}
	else
		return getchar();
}

int main()
{
	int incommen = 0;
	int inquote = 0;
	char c, temp;
	while ((c = getc()) != EOF)
	{
		switch (c)
		{
		case '(':
		case '[':
		case '{':
			if (incommen == 0 && inquote == 0)
				push(c);
			break;
		case ')':
		case ']':
		case '}':
			if (incommen == 0 && inquote == 0)
			{
				temp = pop();
				if ((c == ')' && temp == '(') || (c == ']' && temp == '[') || (c == '}' && temp == '{'))
					;
				else
					printf("the %c didn'pair with %c.", c, temp);
			}
			break;
		case '\'':
			c = getc();
			if (c == '\\')
				c = getc();
			if ((c = getc()) == '\'')
				;
			else
				printf("the ' is not in pair.");
			break;
		case '"':
			if (incommen == 0 && inquote == 0)
				inquote = 1;
			else if (incommen == 0)
				inquote = 0;
			break;
		case '/':
			if (incommen == 0 && inquote == 0)
			{
				if ((c = getc()) == '*')
					incommen = 1;
				else
					ungetc(c);
			}
			break;
		case '*':
			if (incommen == 1)
			{
				if ((c = getc()) == '/')
					incommen = 0;
			}
			break;
		case '\\':
			if (inquote == 1)
				c = getc();
			break;
		}
	}
	if (p > 0)
	{
		while (p > 0)
			printf("the %c is not in pair.", pair[--p]);
	}
    return 0;
}

/*""�жϵĲ��Ǻ�׼ȷ������������У��������eof���жϲ���������û�����*/
/*������ɰ��н����жϣ��ǲ��ǻ�õ㣿*/
