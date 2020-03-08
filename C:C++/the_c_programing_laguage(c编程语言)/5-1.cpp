#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int c);

int getin(int *p)
{
	int c, sign;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-' ? -1 : 1);
	if (c == '-' || c == '+')
		c = getch();
	if (!isdigit(c))
	{
		ungetch(c);
		return 0;
	}
	for (*p = 0; isdigit(c); c = getch())
		*p = *p * 10 + c - '0';
	*p *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
