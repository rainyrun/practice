#include <stdio.h>
/*编写一个函数，对一个已排序的整数表执行二分查找。
函数的输入包含一个指向表头的指针，表中的元素个数，以及待查找的数值。
函数的输出是一个指向满足查找要求的元素的指针，当未查找到满足要求的数值时，输入一个null指针。*/

//int *found(int *p, int n, int x)
//{
//	while ( n / 2 > 0)
//	{
//		if (x > *(p + n / 2))
//		{
//			p += n / 2;
//			n /= 2;
//		}
//		else if (x < *(p + n / 2))
//			n /= 2;
//		else
//			return (p + n / 2);
//	}
//	return NULL;
//}

int *found(int *p, int n, int x)
{
	int low, hi;
	low = 0;
	hi = n;

	while (low < hi)
	{
		int mid;
		mid = (hi + low) / 2;
		if (x > p[mid])
			low = mid + 1;
		else if (x < p[mid])
			hi = mid;
		else
			return p + mid;
	}
	return NULL;
}