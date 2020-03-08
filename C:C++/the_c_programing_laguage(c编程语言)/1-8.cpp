#include <stdio.h>

/*统计空格，制表符，换行符的个数*/
int main() {
	int c, space, tab, enter;
	space = tab = enter = 0;

	while ((c = getchar()) != EOF)//windows下，EOF=ctrl+z
	{
		if (c == ' ')
			space++;
		else if (c == '\t')
			tab++;
		else if (c == '\n')
			enter++;
	}
	printf("space = %d tab = %d enter = %d\n", space, tab, enter);
}
