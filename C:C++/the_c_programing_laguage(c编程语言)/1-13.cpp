#include <stdio.h>
#define IN 1
#define OUT 0

/*��ӡ�����е��ʵĳ��ȵ�ֱ��ͼ��Ҫ��ֱֱ��ͼ��ˮƽֱ��ͼ*/
int main()
{
	int inword, a[10], n, c, j; //inword��ʾ�Ƿ��ڵ����ڣ�a[i]���泤��Ϊi�ĵ��ʵĸ�����nͳ�Ƶ��ʵĳ���
	int empty, row;//empty��¼�ڴ�ֱֱ��ͼĳ�߶��ϵ�ֱ��������row��ˮƽֱ��ͼ������

	n = 0;
	inword = OUT;
	empty = 0;
	row = 1;
	for(j = 0; j < 10; j++)
	{
		a[j] = 0;
	}

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\n' || c == '\t')
		{
			if (inword == IN)
			{
				a[n] += 1;
				inword = OUT;
				n = 0;
			}
		}
		else
		{
			n += 1;
			inword = IN;
		}
	}

	//��ֱֱ��ͼ
	printf("���ʳ��ȷֲ���ֱֱ��ͼ\n");
	for (j = 1; j < 10; j++)
		printf("%3d", j);
	printf("\n");

	while (empty != 9)
	{
		empty = 0;
			for (int j = 1; j < 10; j++)
			{
				if (a[j] < row)
				{
					printf("   ");
					empty += 1;
				}
				else
				{
					printf("  o");
				}
			}
		printf("\n");
		row += 1;
	}

	//ˮƽֱ��ͼ
	for (int j = 1; j < 10; j++)
	{
		printf("%d", j);
		int col;
		col = a[j];
		while (col > 0)
		{
			printf("  o");
			col -= 1;
		}
		printf("\n");
	}
}
