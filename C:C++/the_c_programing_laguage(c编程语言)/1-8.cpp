#include <stdio.h>

/*ͳ�ƿո��Ʊ�������з��ĸ���*/
int main() {
	int c, space, tab, enter;
	space = tab = enter = 0;

	while ((c = getchar()) != EOF)//windows�£�EOF=ctrl+z
	{
		if (c == ' ')
			space++;
		else if (c == '\t')
			tab++;
		else if (c == '\n')
			enter++;
	}
	printf("space = %d tab = %d enter = %d\n", space, tab, enter);
}
