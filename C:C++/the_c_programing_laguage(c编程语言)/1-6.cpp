#include <stdio.h>

/*验证getchar() != EOF 表达式的值是0还是1*/
int main()
{
		printf("%d\n", getchar() != EOF);
		printf("%d\n", EOF);
}