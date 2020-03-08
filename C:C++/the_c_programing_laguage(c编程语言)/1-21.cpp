#include <stdio.h>
/*��д����entab�����ո��滻Ϊ�����������Ʊ���Ϳո񣬵�Ҫ�����滻ǰ�󣬵��ʼ�ļ�����䡣
 �����Ʊ���ֹλ��λ����1-20��detab����������ͬ��
 ˼·��
 1. ʹ�ñ���len��¼��������ַ�����ʹ��space��¼�����Ŀո�����
 2. �� space < (n - len % n)�������j���ո�
    ������� (space - (n - len % n)) / n + 1 ��tab��(space - (n - len % n)) % n���ո�
 ���� while(len / n != (len + space) / n), �����tab���ٲ���ʣ��Ŀո�
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

		while (s[num] != '\0')//���Ժ�������m��ֵ������ num < m ;
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
