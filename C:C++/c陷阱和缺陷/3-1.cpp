#include <stdio.h>
/*��дһ����������һ���������������ִ�ж��ֲ��ҡ�
�������������һ��ָ���ͷ��ָ�룬���е�Ԫ�ظ������Լ������ҵ���ֵ��
�����������һ��ָ���������Ҫ���Ԫ�ص�ָ�룬��δ���ҵ�����Ҫ�����ֵʱ������һ��nullָ�롣*/

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