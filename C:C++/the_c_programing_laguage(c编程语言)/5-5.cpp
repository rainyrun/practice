/*实现库函数strncpy、strncat、strncmp
他们最多对参数字符串中的前n个字符进行操作。
例如strncpy(s, t, n)将t中最多前n个字符复制到s中。*/

#include <stdio.h>

void strncpy(char *s, char *t, int n)
{
	while ((n > 0) && (*s++ = *t++))//*s++ = *t++ 的顺序很重要，如果放在前面，当n=0时，依然会运算一次
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