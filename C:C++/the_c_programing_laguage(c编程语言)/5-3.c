#include <stdio.h>
/*��ָ�뷽ʽʵ��strcat(s, t)������
strcat(s, t)������tָ����ַ������Ƶ�sָ����ַ�����β����*/

void strcat(char *s, char *t)
{
	while (*s++)
		;
	s--;
	printf("*(s-1) = %d\n", *(s - 1));
	while (*s++ = *t++)
		;
	printf("*(s-1) = %d\n", *(s - 1));
}

int main()
{
	char s[100] = "123";
	char *t = "abc";
	strcat(s, t);
	printf("s is : %s", s);
}
