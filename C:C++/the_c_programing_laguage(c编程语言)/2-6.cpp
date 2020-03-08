#include <stdio.h>
/*编写一个函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：
将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，将x的其余各位保持不变。*/

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned a = ~(~0 << (p + 1 - n));
	unsigned b = ~0 << (p + 1);
	unsigned c = a | b;
	unsigned d = x & c;

	unsigned e = (y & ~(~0 << n)) << (p + 1 - n);

	return d | e;
}