#include <stdio.h>
/*��ջ��������Ӽ�������ֱ������ڲ�����Ԫ�ص�����£�
��ӡջ��Ԫ�أ�
����ջ��Ԫ�أ�
����ջ������Ԫ�ص�ֵ��
��������һ�������������ջ��*/

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