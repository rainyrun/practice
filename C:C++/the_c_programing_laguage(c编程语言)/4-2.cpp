#include <stdio.h>
#include <ctype.h>
/*��atof�����������䣬ʹ�����Դ�������123.45e-6�Ŀ�ѧ��ʾ����
���У�������������ܻ����һ��e��E�Լ�һ��ָ���������������ţ���*/
double atof(char s[])
{
	int i, sign, num;
	double val, power, epower, esign;

	for (i = 0; s[i] == ' '; i++)
		;
//    printf("skip space, i = : %d\n", i);
	sign = ((s[i] == '-') ? -1 : 1);
	if ((s[i] == '-') || (s[i] == '+'))
		i++;
//    printf("if nagitive, i = : %d\n", i);
	for (val = 0.0; isdigit(s[i]); i++)
	{
		val = val * 10 + s[i] - '0';
	}
//    printf("val = : %e\n", val);
//    printf("integer, i = : %d\n", i);
	if (s[i] == '.')
		i++;
//    printf("if decimal, i = : %d\n", i);
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = val * 10 + s[i] - '0';
		power *= 10;
	}
//    printf("decimal, power = %e, val = %e\n", power, val);
//    printf("decimal, i = : %d\n", i);
	if ((s[i] == 'e') || (s[i] == 'E'))
		i++;
	esign = ((s[i] == '-') ? 0.1 : 10);
	if ((s[i] == '-') || (s[i] == '+'))
		i++;
//    printf("e, i = : %d\n", i);
	for (num = 0; s[i] != '\0'; i++)
	{
		num = num * 10 + s[i] - '0';
	}
//    printf("e, num = : %d\n", num);
	for (epower = 1.0; num; num--)
	{
		epower *= esign;
	}
	printf("e, epower = : %e\n", epower);
	return (sign * val / power * epower);
}

int main()
{
	char s[] = " 123e-2";
	double a;
	a = atof(s);
	printf("s = %f\n", a);
}
