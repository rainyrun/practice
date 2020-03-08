#include <stdio.h>
/*用指针方式实现strcat(s, t)函数，
strcat(s, t)函数将t指向的字符串复制到s指向的字符串的尾部。*/

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
