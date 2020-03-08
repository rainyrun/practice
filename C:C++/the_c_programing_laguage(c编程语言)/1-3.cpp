#include <stdio.h>

/*将F转换为对应的℃，切℃保留1位小数，且在转换表的顶部打印标题*/
int main()
{
	float f, c;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	f = lower;
	printf("%3s %6s\n", "F", "C");
	while (f <= upper)
	{
		c = 5 * (f - 32) / 9;
		printf("%3.0f %6.1f\n", f, c);
		f += step;
	}
}
