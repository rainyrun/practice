#include <stdio.h>
#include <setjmp.h>
/*在已经编写好的程序源文件中增加setjmp/longjmp，使得程序在接受某些特别的输入时会重新开始*/
/*如，输入一个数字，并打印。如果输入的不是数字，重新输入*/
jmp_buf buf;
//程序有问题，还未解决
int main()
{
	char c;
	printf("the begaining of the function.\n");
	int a = setjmp(buf);
	printf("setjmp is: %d\n", a);
	printf("please input a number:\n");
	c = getchar();//未被执行
	if (c >= '0' && c <= '9')
	{
		printf("the number is %c\n", c);
	}
	else//这部分被执行了2次，非常奇怪
	{
		printf("input number.\n");
		longjmp(buf, 1);//执行后buf未被销毁
	}
}

//练习程序
//void banana()
//{
//	printf("in banana() \n");
//	longjmp(buf, 1);
//	printf("you'll never see this, because i longjmp'd");
//}
//
//int main()
//{
//	if (setjmp(buf))
//		printf("back in main\n");
//	else
//	{
//		printf("first time through \n");
//		banana();
//	}
//}