#include <stdio.h>

/*��Fת��Ϊ��Ӧ�ġ棬�С汣��1λС��������ת����Ķ�����ӡ����*/
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
