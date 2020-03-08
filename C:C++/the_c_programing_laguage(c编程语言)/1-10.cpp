#include <stdio.h>

/*将输入复制到输出，并将制表符替换成\t回退符替换成\b反斜杠替换成\\*/
int main()
{
	int c;//输入字符

	while((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
            putchar('\\');
            putchar('t');
		}
		else if (c == '\b')
		{
            putchar('\\');
            putchar('b');
		}
		else if (c == '\\')
		{
            putchar('\\');
            putchar('\\');
		}
		else
		{
            putchar(c);
		}
	}
}

/*
 备注
 1. windows下 ctrl+z模拟结束符不好用，必须是前面一个是换行符，后面ctrl+z，才能起到结束符的作用。
 */
