#include <stdio.h>
/*检查程序里（）、[]、{}、‘’、“”、及注释的配对情况
 思路：
 1. 方案1:采用计数器，如遇到‘（’加1，遇到‘）’减1，程序结束时，若计数器归0，则可正确配对
    缺点：不能检测出[{]}这种错误情况
 2. 方案2:采用栈，遇到‘（’入栈，遇到‘）’查看栈顶元素是否匹配，若匹配则继续检查，不匹配则报错。
 */

/*方案1的实现*/
//#define NUM 5
//int main()
//{
//	int pair[NUM];//记录配对情况（+1，）-1，如果最后的值不等于0，则说明存在不配对的情况
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

//方案2的实现
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

/*""判断的不是很准确，如果遇到换行，如果遇到eof，判断不出来“有没有配对*/
/*如果换成按行进行判断，是不是会好点？*/
