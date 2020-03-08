#include <stdio.h>
/*��дһ������setbits(x, p, n, y)���ú������ض�xִ�����в�����Ľ��ֵ��
��x�дӵ�pλ��ʼ��n���������ƣ�λ����Ϊy�����ұ�nλ��ֵ����x�������λ���ֲ��䡣*/

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned a = ~(~0 << (p + 1 - n));
	unsigned b = ~0 << (p + 1);
	unsigned c = a | b;
	unsigned d = x & c;

	unsigned e = (y & ~(~0 << n)) << (p + 1 - n);

	return d | e;
}