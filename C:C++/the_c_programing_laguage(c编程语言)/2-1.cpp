#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("采用打印标准头文件limits.h中的相应值：\n");
	//signed types  
	printf("signed char min = %d\n", SCHAR_MIN);
	printf("signed char max = %d\n", SCHAR_MAX);
	printf("signed short min = %d\n", SHRT_MIN);
	printf("signed short max = %d\n", SHRT_MAX);
	printf("signed int min = %d\n", INT_MIN);
	printf("signed int max = %d\n", INT_MAX);
	printf("signed long min = %ld\n", LONG_MIN);
	printf("signed long max = %ld\n", LONG_MAX);
	//unsigned types  
	printf("unsigned char max = %u\n", UCHAR_MAX);
	printf("unsigned short max = %u\n", USHRT_MAX);
	printf("unsigned int max = %u\n", UINT_MAX);
	printf("unsigned long max = %lu\n", ULONG_MAX);

	printf("采用直接计算的方式：\n");
	//signed types  
	printf("signed char min = %d\n", -(char)((unsigned char)~0 >> 1) - 1);
	printf("signed char max = %d\n", (char)((unsigned char)~0 >> 1));
	printf("signed short min = %d\n", -(short)((unsigned short)~0 >> 1) - 1);
	printf("signed short max = %d\n", (short)((unsigned short)~0 >> 1));
	printf("signed int min = %d\n", -(int)((unsigned int)~0 >> 1) - 1);
	printf("signed int max = %d\n", (int)((unsigned int)~0 >> 1));
	printf("signed long min = %ld\n", -(long)((unsigned long)~0 >> 1) - 1);
	printf("signed long max = %ld\n", (long)((unsigned long)~0 >> 1));
	//unsigned types  
	printf("unsigned char max = %u\n", (unsigned char)~0);
	printf("unsigned short max = %u\n", (unsigned short)~0);
	printf("unsigned int max = %u\n", (unsigned int)~0);
	printf("unsigned long max = %lu\n", (unsigned long)~0);
	return 0;
	/*利用按位运算符进行计算。表达式：(char)((unsigned char)~0>>1)
先把数字0的各个二进制位全部转换为1：取反，~0
然后，将结果值转换为unsigned char类型：(unsigned char)~0
再把这个unsigned char类型值右移一位以清除符号位：(unsigned char)~0 >> 1
最后，把它转换为char类型：(char)((unsigned char)~0>>1)
这一系列操作的最终结果就得到了signed类型字符的最大值。
而其signed类型字符的最小值加负号后还需减去1才是最小值。*/
}