#include <stdio.h>
/*编写程序tail，将其中输入中的最后n行打印出来。
默认情况下，n的值为10，但可通过一个可选参数改变n的值，因此，命令
tail -n
将打印其输入的最后n行。
无论输入或n的值是否合理，该程序都能正常运行。
编写的程序要充分的利用存储空间；
输入行的存储方式应该同5.6节中排序程序的存储方式一样，而不采用固定长度的二维数组。*/
#include <string.h>

#define MAX_SIZE 100
int getline(char s[], int lim);
char *alloc(int n);

int tail(int n, char *s[])
{
	int len;
	char line[MAX_SIZE];
	char *p;
	int i = 1;
	while ((len = getline(line, MAX_SIZE)) > 0)
	{
		if (i >= MAX_SIZE || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			strcpy(p, line);
			s[i++] = p;
		}
	}
	if (n <= i)
	{
		for (int j = 0; j < n; j++)
			printf("no.j is %s", s[i - n + j + 1]);
	}
	return i;
}

int main(int argc, char *argv[])
{
	int n = 10;
	char *s[MAX_SIZE];
	if (argc == 2 && argv[1][0] == '-')
		n = argv[1][1] - '0';
	tail(n, s);
}

/*答案p269采用对line_ptr[current_line]赋值，
而current_line = (current_line + 1) % n,能保证存储占用内存最小*/
