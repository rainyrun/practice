#include <stdio.h>

/*�����븴�Ƶ�����������Ʊ���滻��\t���˷��滻��\b��б���滻��\\*/
int main()
{
	int c;//�����ַ�

	while((c = getchar()) != EOF)
	{
		if (c == '\t')
		{
            putchar('\\');
            putchar('t');
		}
		else if (c == '\b')
		{
            putchar('\\');
            putchar('b');
		}
		else if (c == '\\')
		{
            putchar('\\');
            putchar('\\');
		}
		else
		{
            putchar(c);
		}
	}
}

/*
 ��ע
 1. windows�� ctrl+zģ������������ã�������ǰ��һ���ǻ��з�������ctrl+z�������𵽽����������á�
 */
