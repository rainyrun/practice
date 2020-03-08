#include <stdio.h>
#include <limits.h>
/*编写一个函数ungets(s)，将整个字符串s压回到输入中。
ungets函数需要使用buf和bufp吗？它能否仅使用ungetch函数？*/

void ungets(char s[])
{
	int i = strlen(s);
	while (i > 0)
	{
		ungetch(s[--i]);
	}
}