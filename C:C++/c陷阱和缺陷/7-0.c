#include <stdio.h>

//int main()
//{
//	/*int p = 2;
//	int apple = sizeof(int) * p;
//	printf("%d %d", apple, sizeof(int));*/
//
//	char *p = "abcde";
//	*p = 'f';//�ַ�����ʼ��ָ�룬�ַ���ֻ���������޸ġ�
//	printf("%s\n", p);
//}


void funArr(char ca[])
{
	printf("funArr: &ca = %x, &(ca[0]) = %x, &(ca[1]) = %x;\n", &ca, &(ca[0]), &(ca[1]));
}

void funPtr(char *pa)
{
	printf("funPtr: &pa = %x, &(pa[0]) = %x, &(pa[1]) = %x;\n", &pa, &(pa[0]), &(pa[1]));
	printf("funPtr: ++pa = %x;\n", ++pa);
}

void main()
{
	char ga[] = "abcdefg";
	funArr(ga);
	funPtr(ga);
	printf("ga[]: &ga = %x, &(ga[0]) = %x, &(ga[1]) = %x;\n", &ga, &(ga[0]), &(ga[1]));
}