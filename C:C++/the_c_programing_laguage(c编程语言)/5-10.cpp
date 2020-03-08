#include <stdio.h>
/*编写程序expr，以计算从命令行输入的逆波兰表达式的值，其中每个运算符或操作数用一个单独的参数表示。
例如，命令 expr 2 3 4 + * 将计算表达式2*（3+4）的值*/
#define MAX 100

int pop();
void push(int num);
int atoi(char s[]);
int stack[MAX];
int p = 0;

int main(int argc, char *argv[])
{
	int op;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i][0] == '+')
			push(pop() + pop());
		else if (argv[i][0] == '-')
		{
			op = pop();
			push(pop() - op);
		}
		else if (argv[i][0] == '*')
			push(pop() * pop());
		else if (argv[i][0] >= '0' && (argv[i][0] <= '9'))
			push(atoi(argv[i]));
		else
			printf("unright operater.\n");
	}
	return pop();
}


int pop()
{
	if (p > 0)
		return stack[--p];
	else
		return 0;
}

void push(int num)
{
	if (p < MAX)
		stack[p++] = num;
	else
		printf("stack is overflow");
}

int atoi(char s[])
{
	int num;
	int i;

	num = 0;
	for (i = 0; s[i] != '\0'; i++)
		num = num * 10 + s[i] - '0';
	return num;
}
