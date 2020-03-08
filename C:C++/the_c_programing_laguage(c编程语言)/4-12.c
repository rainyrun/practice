#include <stdio.h>
/*����printd���������˼���дһ���ݹ�汾��itoa������
��ͨ���ݹ������ת��Ϊ�ַ�����*/
/*û���ж�ת���ɵ��ַ������Ƿ��ں���Χ��*/
//#define MAX 100
//int i = 0;
//void itoa(char s[], int n)
//{
//	if (n < 0)
//	{
//		n = -n;
//		s[i++] = '-';
//	}
//	if (n / 10)
//	{
//		itoa(s, n / 10);
//	}
//	s[i++] = n % 10 + '0';
//	s[i] = '\0';
//}
//
//int main()
//{
//	char s[MAX];
//	int n = 35235;
//	itoa(s, n);
//	printf("s is %s, n is %d\n", s, n);
//}


#include <stdlib.h>
char *utoa(unsigned value, char *digits, int base)
{
	char *s, *p;
	s = "0123456789abcdefghigklmnopqrstuvwxyz";
	if (base == 0)
		base = 10;
	if (digits == NULL || base <2 || base > 36)
		return NULL;
	if (value <(unsigned)base)
	{
		digits[0] = s[value];
		digits[1] = '\0';
	}
	else
	{
		for (p = utoa(value / ((unsigned)base), digits, base); *p; p++)
			printf("*p is %c", *p);//ִ����ݹ麯���󣬷���ִ�еݹ麯��������ݡ�
		utoa(value % ((unsigned)base), p, base);
	}
	return digits;
}

char *itoa(int value, char *digits, int base)
{
	char *d;
	unsigned u;
	d = digits;
	if (base == 0)
		base = 10;
	if (digits == NULL || base < 2 || base > 36)
		return NULL;
	if (value < 0)
	{
		*d++ = '-';
		u = -value;
	}
	else
		u = value;
	utoa(u, d, base);
	return digits;
}

void main()
{
	int a = 923;
	char digits[100];
	itoa(a, digits, 0);
	printf("digits is %s", digits);
}
