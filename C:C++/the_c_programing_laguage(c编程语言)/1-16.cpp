#include <stdio.h>

/*读入一组文本，并将文本一行一行的打印出来，并打印输入行的长度*/
#define MAXLINE 100
int getLine(char s[], int max);
void copy(char to[], char from[]);
int main()
{
	char longest[MAXLINE];
	char line[MAXLINE];
	int len, max;

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
	{
		printf("this line has %d letters, it's :%s", len, line);
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	}
	if (max > 0)
		printf("longest line is :%s", longest);
}

int getLine(char s[], int max)
{
	int i;
	char c;
	for (i = 0; i < max-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while ((to[i] = from[i]) != '\0')
	{
		++i;
	}
}