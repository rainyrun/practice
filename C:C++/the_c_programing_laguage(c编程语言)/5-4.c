/*��д����strend(s, t)����ַ���t�������ַ���s��β�����ú�������1�����򷵻�0��*/
#include <stdio.h>
#include <string.h>

int strend(char *s, char *t)
{
	int i;
	for (i = strlen(s) - strlen(t); i > 0; i--, s++)
		;
	while ((*s++ == *t++) && *s)
		printf("*s is : %c  *t is %c \n", *s, *t);
	printf("*(s - 1) = : %c\n", *(s - 1));
	if (*s == '\0')
		return 1;
	else
		return 0;
}

int main()
{
	char *s = "123456";
	char *t = "56";
	int a = strend(s, t);
	printf("a is : %d", a);
}