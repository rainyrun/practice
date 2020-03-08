#include <stdio.h>
/*�Գ���entab��detab�Ĺ�����һЩ���䣬�Խ���������д�����
entab -m +n
��ʾ�Ʊ���ӵ�m�п�ʼ��ÿ��n��ֹͣ��ѡ�񣨶�ʹ���߶��ԣ��ȽϷ����Ĭ����Ϊ��*/
#define MAX_SIZE 100

void detab(int m, int n)
{
	int i = 0;
	char c;
	char s[MAX_SIZE];
	for (; (c = getchar()) != EOF && m > 0; m--)
		putchar(c);
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
		for (int k = 0; k < (8 - (j % n)); k++)
			s[i++] = ' ';
		if (c != EOF)
			c = getchar();
	}
	s[i] = '\0';
	printf("s is : %s\n", s);
}

int main(int argc, char *argv[])
{
	int m = 0;
	int n = 8;
	if (argc == 2)
	{
		if (*argv[0] > 0)
			n = *argv[0];
		else
			m = *argv[0];
	}
	else if (argc == 3)
	{
		if (*argv[0] < 0 && *argv[1] > 0)
		{
			m = *argv[0];
			n = *argv[1];
		}
		else
			printf("wrong parameter.\n");
	}
	detab(m, n);
}
