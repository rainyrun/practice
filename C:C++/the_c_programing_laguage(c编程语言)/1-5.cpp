#include <stdio.h>

/*�����ӡ0-300 F��Ӧ�ġ棬�ҡ汣��1λС��*/
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
