#include <stdio.h>
/*��д����tail�������������е����n�д�ӡ������
Ĭ������£�n��ֵΪ10������ͨ��һ����ѡ�����ı�n��ֵ����ˣ�����
tail -n
����ӡ����������n�С�
���������n��ֵ�Ƿ�����ó������������С�
��д�ĳ���Ҫ��ֵ����ô洢�ռ䣻
�����еĴ洢��ʽӦ��ͬ5.6�����������Ĵ洢��ʽһ�����������ù̶����ȵĶ�ά���顣*/
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

/*��p269���ö�line_ptr[current_line]��ֵ��
��current_line = (current_line + 1) % n,�ܱ�֤�洢ռ���ڴ���С*/
