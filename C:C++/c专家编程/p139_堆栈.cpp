#include <stdio.h>
/*�������ݶΡ��ı��ε�λ�á����ݶ��ڵĶѣ�*/

int test();

int main()
{
	int i;//008ff9f4
	int n;
	int m = 1;
	printf("The stack top is near %p\n", &i);
	printf("The BSS top is near %p\n", &n);
	printf("The data stack top is near %p\n", &m);
	n = m;
	int(*j)();
	j = test;
	printf("The test top is near %p\n", &j);
	return 0;
}

int test()
{
	return 0;
}