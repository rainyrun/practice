#include <stdio.h>
#define IN 1
#define OUT 0

/*打印输入中单词的长度的直方图，要垂直直方图和水平直方图*/
int main()
{
	int inword, a[10], n, c, j; //inword表示是否在单词内，a[i]保存长度为i的单词的个数，n统计单词的长度
	int empty, row;//empty记录在垂直直方图某高度上的直方个数，row记水平直方图的行数

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

	//垂直直方图
	printf("单词长度分布垂直直方图\n");
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

	//水平直方图
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
