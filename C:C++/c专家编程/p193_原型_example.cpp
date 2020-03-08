#include <stdio.h>

void main()
{
	union {
		double d;
		float f;
	}u;

	u.d = 10.0;
	printf("put in a double, pull out a float f = %f \n", u.f);

	u.f = 10.0;
	printf("put in a float, pull out a double d = %f \n", u.d);
}//跟示例答案不一样……