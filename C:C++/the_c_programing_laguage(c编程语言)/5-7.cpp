#include <stdio.h>
/*重写函数readlines，将输入的文本行存储到由main函数提供的一个数组中，而不是存储到调用alloc分配的存储空间中。
该函数的运行速度比改写前快了多少？*/

#define MAXLINE 1000
int readLines(char *lineptr[], int maxlines)
{
	int len, nlines, p;
	char line[MAXLINE];

	nlines = 0;
	p = 0;

	while ((len = getline(line, MAXLINE)) > 0)
		if (nlines >= maxlines)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy(lineptr[nlines++], line);
		}
	return nlines;
}
