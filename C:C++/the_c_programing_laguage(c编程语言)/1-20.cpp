#include <stdio.h>
/*��д����detab���������е��Ʊ���滻���ʵ���Ŀ�Ŀո�ʹ�ո��������һ���Ʊ����ֹλ�ĵط���
 �����Ʊ����ֹλ��λ���ǹ̶��ģ�����ÿ��n�оͻ����һ���Ʊ����ֹλ��
 ˼·��
 1. ��nΪ�Ʊ�����ʹ�ñ���num��¼���Ʊ������Ѿ�ʹ�õ�λ������n-num�����Ʊ��Ӧ�����Ŀո�����numÿ�ﵽn�͹�0
 */

#define MAX_SIZE 100
#define	N 8

//ver1.0
int main()
{
	int i = 0;
	char c;
	char s[MAX_SIZE];
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
		for (int k = 0; k < (8 - (j % N)); k++)
			s[i++] = ' ';
		if (c != EOF)
			c = getchar();
	}
	s[i] = '\0';
	printf("s is : %s\n", s);
    return 0;
}
