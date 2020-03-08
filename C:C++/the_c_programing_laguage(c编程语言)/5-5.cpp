/*ʵ�ֿ⺯��strncpy��strncat��strncmp
�������Բ����ַ����е�ǰn���ַ����в�����
����strncpy(s, t, n)��t�����ǰn���ַ����Ƶ�s�С�*/

#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	while ((n > 0) && (*s++ = *t++))//*s++ = *t++ ��˳�����Ҫ���������ǰ�棬��n=0ʱ����Ȼ������һ��
		--n;
	if (n == 0)
		*s = '\0';
}

void strncat(char *s, char *t, int n)
{
	while (*s)
		s++;
	strncpy(s, t, n);
}

int strncmp(char *s, char *t, int n)
{
	while ((*s == *t) && n > 0)
	{
		n--;
		if (*s == '\0' || n == 0)
			return 0;
		s++;
		t++;
	}
	return *s - *t;
}

int main()
{
	char s[50] = "abc";
	char b[] = "abefd";
	int n = 3;
	int m = strncmp(s, b, n);
	printf("m is : %d\n", m);
}