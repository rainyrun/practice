#include <stdio.h>
/*��д����readlines����������ı��д洢����main�����ṩ��һ�������У������Ǵ洢������alloc����Ĵ洢�ռ��С�
�ú����������ٶȱȸ�дǰ���˶��٣�*/

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
