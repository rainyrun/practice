#include <stdio.h>

/*¡æ×ª»¯ÎªF£¬c=0£¬¡­¡­15*/
int main()
{
	float c, f;
	float lower, upper, step;

	lower = 0;
	upper = 50;
	step = 5;

	c = lower;
    printf("%2s|%6s\n", "C", "F");
    printf("--|------\n");
	while (c <= upper)
	{
		f = c * 9 / 5 + 32;
		printf("%2.0f|%6.1f\n", c, f);
		c += step;
	}
}
