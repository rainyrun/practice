#include <stdio.h>
#include <limits.h>
/*��дһ������rightrot(x, n)���ú�������
��xѭ�����ƣ��������Ҷ��Ƴ���λ������������룩n�������ƣ�λ�����õ�ֵ��*/

/*һλһλ���ƣ�������һλ��0�������ƺ��ö��⴦�������һλ��1��������ǰ�油1*/
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