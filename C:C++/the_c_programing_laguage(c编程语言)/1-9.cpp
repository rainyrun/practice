#include <stdio.h>

/*�����븴�Ƶ�������������������Ŀո�ϲ���һ��*/

int main()
{
	int c, inspace;

	inspace = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ')
		{
			if (inspace == 0)
			{
				inspace = 1;
				putchar(c);
			}
			else
				printf("�����ո�");
		}
		if (c != ' ')
		{
			inspace = 0;
			putchar(c);
		}
	}
    return 0;
}
/*
��ע
1. windows�� ctrl+zģ������������ã�������ǰ��һ���ǻ��з�������ctrl+z�������𵽽����������á�
 */
