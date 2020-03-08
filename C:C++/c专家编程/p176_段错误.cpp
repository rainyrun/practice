#include <stdio.h>

void main()
{
	//union {
	//	char a[10];
	//	int i;
	//}u;

	//int *p = (int *) &(u.a[1]);
	//*p = 17;
	//printf("*p = %d.\n", *p);
	//以上代码没有产生段错误

	int *p = 0;
	*p = 17;
	//以上代码报告“写入访问冲突”，p指向空指针（nullptr)
}