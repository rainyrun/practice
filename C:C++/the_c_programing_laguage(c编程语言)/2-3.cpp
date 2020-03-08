#include <stdio.h>
#include <stdlib.h>
/*将十六进制字符串转化成与之等价的整型值，包含可选的前缀0x或0X，字符串中允许0-9、a~f、A~F*/

int main()
{
	//strtoul("f00", 0, 16);将对应进制的字符串转化为无符号长整型
	int n;//输出的整型值
	int c;
	int first;//判断第一个数是否是0

	n = 0;
	first = 1;

	while ((c = getchar()) != EOF && (c != ' ') && (c != '\n'))
	{
		if (c == '0' && first)
		{
            if((c = getchar()) != 'x' && c != 'X')
            {
                printf("preindex error: please input 0x or 0X\n");
                return 0;
            }
            first = 0;
            continue;
		}
		else
		{
			if (c >= 'a' && c <= 'f')
			{
				n = n * 16 + (c - 'a' + 10);
			}
			else if (c >= 'A' && c <= 'F')
			{
				n = n * 16 + (c - 'A' + 10);
			}
			else if (c >= '0' && c <= '9')
			{
				n = n * 16 + (c - '0');
			}
			else
			{
				printf("input error\n");
				n = 0;
			}
		}
	}
    printf("the num is: %d\n", n);
    return 0;
}
