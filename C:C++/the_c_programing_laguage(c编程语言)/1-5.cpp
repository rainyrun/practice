#include <stdio.h>

/*逆序打印0-300 F对应的℃，且℃保留1位小数*/
int main()
{
	int f;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	for (f = upper; f >= lower; f -= step)
        printf("%3d %6.1f\n", f, 5.0 / 9 * (f - 32));
}
