#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*修改itoa函数，使得该函数可以接收3个参数。其中第三个参数为最小字段宽度。
为保证转换后所得的记过至少具有第三个参数制定的最小宽度，在必须要时应在所得结果的左边填充一定的空格。*/
void reverse(char s[]);
void itoa(int n, char s[], int b)
{
	char a[] = "0123456789";
	int i, sign;
	i = 0;
	sign = n;
	do
	{
		s[i++] = a[abs(n % 10)];
	} while (n /= 10);
	
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	if (i < b)
	{
		int j;
		for (j = i; j < b - i - 1; j++)
			s[j] = ' ';
		s[j] = '\0';
	}
	reverse(s);
}

void reverse(char s[]) {
    int i, j, temp;
    for (i = 0; s[i] != '\0'; i++)
        ;
    i -= 1;
    for (j = 0; j < i; j++, i--)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
