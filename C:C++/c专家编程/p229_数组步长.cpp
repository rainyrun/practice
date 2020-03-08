#include <stdio.h>
#include <stdlib.h>

void main()
{
	/*数组步长*/
	//int apricot[2][3][5];
	//int(*r)[5] = apricot[0];
	//int *t = apricot[0][0];
	//printf("the destination of r is %x \n", r);
	//printf("the destination of t is %x \n", t);
	//printf("the step of r is %x \n", ++r);//20
	//printf("the step of t is %x \n", ++t);//4

	/*0 和 0.0的位模式*/
	int a = 0;
	int c = 123;
	float b = 0.0;
	float d = 123.0;
	printf("0 is %x \n", a);
	printf("123 is %x \n", c);
	printf("0.0 is %x \n", *(long *)&b);
	printf("123.0 is %x \n", *(long *)&d);
}