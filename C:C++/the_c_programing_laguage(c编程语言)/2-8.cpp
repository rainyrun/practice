#include <stdio.h>
#include <limits.h>
/*编写一个函数rightrot(x, n)，该函数返回
将x循环右移（即从最右端移出的位将从最左端移入）n（二进制）位后所得的值。*/

/*一位一位右移，如果最后一位是0，则右移后不用额外处理；若最后一位是1，则在最前面补1*/
int main()
{
	printf("char_bit %d", CHAR_BIT);
}
unsigned rightrot(unsigned x, int n)
{
	while (n > 0)
	{
		if ((x & 1) == 1)
		{
			x = (x >> 1) | ~(~0U >> 1);
		}
		else
			x = x >> 1;
		n--;
	}
	return x;
}