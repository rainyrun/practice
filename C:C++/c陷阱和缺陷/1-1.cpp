#include <stdio.h>
/*写一个测试程序，测试编译器是否允许嵌套注释。
要求：无论哪种编译器都能正常通过，但两种编译器运行结果不一样*/

int main()
{
	int result;
	result = /*/*/0 */**/1;

	char *s;
	s = /*/**/"*/"/*"/**/ ;

	printf("%d\n", result);
	printf("%s\n", s);
}

/*
 1-2
 不允许
 
 1-3
 词法分析中的贪心原则
 
 1-4
 a++ + ++b
 因为a++不能作为左值
 */
