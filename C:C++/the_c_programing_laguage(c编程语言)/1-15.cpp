#include <stdio.h>

/*�ú�������ʽд��ת��Ϊ��ĳ���*/
#define UPPER 300
#define LOWER 0
#define STEP 20

float ftoc(float f);

int main()
{
	float f;

	for (f = LOWER; f <= UPPER; f += STEP)
	{
		printf("%3.0f%6.1f\n", f, ftoc(f));
	}
}

float ftoc(float f)
{
	return 5 * (f - 32) / 9;
}