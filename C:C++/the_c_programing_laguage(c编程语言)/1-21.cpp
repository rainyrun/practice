#include <stdio.h>
/*编写程序entab，将空格串替换为最少数量的制表符和空格，但要保持替换前后，单词间的间隔不变。
 假设制表终止位的位置与1-20的detab程序的情况相同。
 思路：
 1. 使用变量len记录已输入的字符数，使用space记录连续的空格数。
 2. 若 space < (n - len % n)，则添加j个空格
    否则，添加 (space - (n - len % n)) / n + 1 个tab，(space - (n - len % n)) % n个空格
 或者 while(len / n != (len + space) / n), 则添加tab，再补齐剩余的空格
 */

#define MAX_SIZE 100
#define N 8
int getline(char s[], int lim);

int main()
{
	int m;
	char s[MAX_SIZE];
	while ((m = getline(s, MAX_SIZE)) != 0)
	{
		int num = 0;
		int space = 0;

		while (s[num] != '\0')//可以合理利用m的值，比如 num < m ;
		{
			for (; s[num] != ' ' && s[num] != '\0'; ++num)
				putchar(s[num]);
			//printf("num is %d.\n", num);
			for (space = 0; s[num] == ' ' && s[num] != '\0'; ++num, ++space)
				;
			//printf("space is %d.\n", space);
			if ((space % N) >= (N - (num-space) % N))
			{
				//printf("tab is %d.\n", (space / N + 1));
				for (int i = 0; i < (space / N + 1); i++)
					putchar('\t');
				//printf("space is %d.\n", ((space % N) - (N - (num % N))));
				for (int j = 0; j < ((space % N) - (N - ((num - space) % N))); j++)
					putchar(' ');
			}
			else
			{
				for (int j = 0; j < space; j++)
					putchar(' ');
			}
		}
	}
    return 0;
}

int getline(char s[], int lim)
{
	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && c != EOF && (i < lim-1))
		s[i++] = c;
	s[i] = '\0';
	//printf("s is %s\n", s);
	return i;
}
