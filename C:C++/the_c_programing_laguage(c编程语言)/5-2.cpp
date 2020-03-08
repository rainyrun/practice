#include <stdio.h>
#include <ctype.h>

int getch();
void ungetch(int c);

int getFloat(float *p)
{
	int c, sign, power;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
	{
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '-' || c == '+')
		c = getch();
	if (!isdigit(c) && c != '.')
	{
		ungetch(c);
		return 0;
	}
	for (*p = 0; isdigit(c); c = getch())
		*p = *p * 10 + c - '0';
	if (c == '.')
		c = getch();
	for (power = 1; isdigit(c); power *= 10, c = getch())
		*p = *p * 10 + c - '0';
	*p = *p * sign / power;
	if (c != EOF)
		ungetch(c);
	return c;
}
