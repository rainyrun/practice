#include <stdio.h>
/*编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。
 假设制表符终止位的位置是固定的，比如每隔n列就会出现一个制表符终止位。
 思路：
 1. 称n为制表间隔，使用变量num记录在制表间隔内已经使用的位数，则n-num就是制表符应该填充的空格数。num每达到n就归0
 */

#define MAX_SIZE 100
#define	N 8

//ver1.0
int main()
{
	int i = 0;
	char c;
	char s[MAX_SIZE];
	c = getchar();
	while (c != EOF)
	{
		int j;
		for (j = 0; c != '\t' && c != EOF; j++, i++)
		{
			s[i] = c;
			c = getchar();
		}
		printf("j is :%d\n", j);
		for (int k = 0; k < (8 - (j % N)); k++)
			s[i++] = ' ';
		if (c != EOF)
			c = getchar();
	}
	s[i] = '\0';
	printf("s is : %s\n", s);
    return 0;
}
