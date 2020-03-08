#include <stdio.h>

void banana_peel(char a, short b, float c);

int main()
{
	union type
	{
		char a;
		short b;
		float c;
	};
	type temp;
	temp.c = 135;

	banana_peel(temp.c, temp.b, temp.a);
}