#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
/*一个逆波兰计算器，可以进行加、减、乘、除、取余运算*/
#define NUMBER '0'
#define MAXOP 100

double pop();
void push(double a);
int getop(char s[]);
int getch(void);
void ungetch(int c);

int main()
{
	char c;
	double op;
	char s[MAXOP];
	while ((c = getop(s)) != EOF)
	{
		switch (c)
		{
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '-':
			op = pop();
			push(pop() - op);
			break;
		case '*':
			push(pop() * pop());
			break;
		case '/':
			op = pop();
			if (op != 0.0)
				push(pop() / op);
			else
				printf("error: zero divider\n");
			break;
		case '%':
			op = pop();
			if (op != 0.0)
				push(fmod(pop(), op));
			else
				printf("error: zero divider\n");
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("unkown command %s\n", s);
			break;
		}
	}
}
#define MAXVAL 100
double val[MAXVAL];
int sp = 0;
double pop()
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("the stack is empty\n");
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

int getop(char s[])
{
	int c, i;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')//不是数字
        return c;
    
    i = 0;
    if(isdigit(c))//有整数部分
        while(isdigit(s[++i] = c = getch()))//数字整数部分存在s[]中
            ;
    if(c == '.')//有小数部分
        while(isdigit(s[++i] = c = getch()))//数字小数部分存在s[]中
            ;
    if(c != EOF)//将多取的字符退回
        ungetch(c);
    s[i] = '\0';
    return NUMBER;
}

#define BUFSIZE 50
char buf[BUFSIZE];
int bufp = 0;

int getch(){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp > BUFSIZE - 1)
        printf("put too much into stack\n");
    else
        buf[bufp++] = c;
}
