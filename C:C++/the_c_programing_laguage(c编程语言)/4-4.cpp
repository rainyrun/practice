#include <stdio.h>
/*在栈操作中添加几个命令，分别用于在不弹出元素的情况下，
打印栈顶元素；
复制栈顶元素；
交换栈顶两个元素的值。
另外增加一个命令用于清空栈。*/

#define MAXVAL 100
double val[MAXVAL];
int sp = 0;
double tope;
double pop()
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("the stack is empty");
		return 0.0;
	}
}

void push(double a)
{
	if (sp < MAXVAL)
		val[sp++] = a;
	else
		printf("the stack is overflower\n");
}

void printTop()
{
	if (sp < MAXVAL)
		printf("top element is: %g", val[sp - 1]);
	else
		printf("the stack is overflower\n");
}

void copyTop()
{
	if (sp < MAXVAL)
		tope = val[sp - 1];
	else
		printf("the stack is overflower\n");
}

void change()
{
	double temp;;
	if (sp < MAXVAL)
	{
		temp = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = temp;
	}
	else
		printf("the stack is overflower\n");
}

void clear()
{
	sp = 0;
	//while (sp > 0)
	//{
	//	val[--sp] = 0;
	//}
}