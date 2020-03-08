#include <stdio.h>

/*将输入复制到输出，并将输入连续的空格合并成一个*/

int main()
{
	int c, inspace;

	inspace = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (inspace == 0)
			{
				inspace = 1;
				putchar(c);
			}
			else
				printf("跳过空格");
		}
		if (c != ' ')
		{
			inspace = 0;
			putchar(c);
		}
	}
    return 0;
}
/*
备注
1. windows下 ctrl+z模拟结束符不好用，必须是前面一个是换行符，后面ctrl+z，才能起到结束符的作用。
 */
