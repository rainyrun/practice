#include <stdio.h>

int a(int i)
{
	if (i > 0)
		a(--i);
	else
		printf("i has reached zero.");
	return 0;
}

int main()
{
	a(1);
	return 0;
}