#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*�޸��������ʹ���ܴ���-r��ǡ��ñ�Ǳ����������򣨵ݼ�����ʽ����
Ҫ��֤-r��-n�ܹ������һ��ʹ�á�*/
int readline(char *v[], int n);
void writeline(char *v[], int nlines);
void swap(char *v[], int, int);
int numcmp(const char *, const char *);
char *alloc(int len);

/*(y)��������*/
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
	switch (argc)//�����и��򵥵��жϷ���������
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

/*(y)����һ�����ݣ�������s[]�У����ظ����ַ���*/
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
/*(y)��������ı�������ÿ���ı���ָ�룬����v[]�У���������*/
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
			line[len - 1] = '\0';//ɾ���ַ������Ļس�
			printf("line is %s\n", line);
			strcpy(p, line);
			lineptr[nlines++] = p;
			printf("lineptr is %s\n", lineptr[nlines-1]);
		}
	}
	return nlines;
}
/*(y)��ӡv[]�е�����*/
void writeline(char *lineptr[], int nlines)
{
	for (int i = 0; i < nlines; i++)
		printf("%d lines is %s\n", i+1, lineptr[i]);
}

/*(y)����2��Ԫ��*/
void swap(char *v[], int x, int y)
{
	char *temp;
	temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

/*(y)���ַ���ת�������֣����Ƚ�2��ת������ַ�����С*/
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
/*(y)����洢�ռ�*/
char *alloc(int len)
{
	if (allocbuf + ALLOCSIZE - allocp >= len) {
		allocp += len;
		return allocp - len;
	}
	else
		return 0;
}