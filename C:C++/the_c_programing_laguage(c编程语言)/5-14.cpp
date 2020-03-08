#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*修改排序程序，使它能处理-r标记。该标记表明，以逆序（递减）方式排序。
要保证-r和-n能够组合在一起使用。*/
int readline(char *v[], int n);
void writeline(char *v[], int nlines);
void swap(char *v[], int, int);
int numcmp(const char *, const char *);
char *alloc(int len);

/*(y)快速排序*/
void qsort(char *v[], int left, int right, int(*comp)(void *, void *), int descend)
{
	int last = left;
	int i;
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	for (i = left+1; i <= right; i++)
	{
		if (descend)
		{
			if ((*comp)(v[i], v[left]) > 0)
				swap(v, ++last, i);
		}
		else
		{
			if ((*comp)(v[i], v[left]) < 0)
				swap(v, ++last, i);
		}
	}
	swap(v, left, last);
	qsort(v, left, last - 1, comp, descend);
	qsort(v, last + 1, right, comp, descend);
}

#define MAX_SIZE 100
char *v[MAX_SIZE];
void main(int argc, char *argv[])
{
	int numeric = 0;
	int descend = 0;
	int nlines;
	
	printf("argc is %d\n", argc);
	printf("argv[0] is %s\n", argv[0]);
	printf("argv[1] is %s\n", argv[1]);
	printf("argv[2] is %s\n", argv[2]);
	switch (argc)//这里有更简单的判断方法。见答案
	{
	case 2:
		if (strcmp(argv[1], "-n") == 0)
			numeric = 1;
		if (strcmp(argv[1], "-r") == 0)
			descend = 1;
		break;
	case 3:
		if (strcmp(argv[1], "-n") == 0 || strcmp(argv[2], "-n") == 0)
			numeric = 1;
		if (strcmp(argv[1], "-r") == 0 || strcmp(argv[2], "-r") == 0)
			descend = 1;
		break;
	default:
		break;
	}
	printf("numeric is %d\n", numeric);
	printf("descend is %d\n", descend);
	if ((nlines = readline(v, MAX_SIZE)) >= 0)
	{
		qsort(v, 0, (nlines - 1), (int(*)(void *, void *))(numeric ? numcmp : strcmp), descend);
		writeline(v, nlines);
	}
	else
		printf("input too big to sort");
}

/*(y)读入一行数据，并存在s[]中，返回改行字符数*/
int getline(char s[], int lim)
{
	char c;
	int len = 0;
	while (--lim > 0 && (c = getchar()) != '\n' && c != EOF)
		s[len++] = c;
	if (c == '\n')
		s[len++] = c;
	s[len] = '\0';
	return len;
}
/*(y)读入多行文本，并将每行文本的指针，存在v[]中，返回行数*/
int readline(char *lineptr[], int maxlines)
{
	char line[MAX_SIZE], *p;
	int len, nlines;

	nlines = 0;
	while ((len = getline(line, MAX_SIZE)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len+1)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';//删掉字符串最后的回车
			printf("line is %s\n", line);
			strcpy(p, line);
			lineptr[nlines++] = p;
			printf("lineptr is %s\n", lineptr[nlines-1]);
		}
	}
	return nlines;
}
/*(y)打印v[]中的数据*/
void writeline(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%d lines is %s\n", i+1, lineptr[i]);
}

/*(y)交换2个元素*/
void swap(char *v[], int x, int y)
{
	char *temp;
	temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

/*(y)将字符串转换成数字，并比较2个转化后的字符串大小*/
int numcmp(const char * x, const char * y) 
{
	double nx, ny;

	nx = atof(x);
	ny = atof(y);

	if (nx > ny)
		return 1;
	else if (nx < ny)
		return -1;
	else
		return 0;
}

#define ALLOCSIZE 1000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
/*(y)分配存储空间*/
char *alloc(int len)
{
	if (allocbuf + ALLOCSIZE - allocp >= len) {
		allocp += len;
		return allocp - len;
	}
	else
		return 0;
}