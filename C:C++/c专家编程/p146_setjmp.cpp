#include <stdio.h>
#include <setjmp.h>
/*���Ѿ���д�õĳ���Դ�ļ�������setjmp/longjmp��ʹ�ó����ڽ���ĳЩ�ر������ʱ�����¿�ʼ*/
/*�磬����һ�����֣�����ӡ���������Ĳ������֣���������*/
jmp_buf buf;
//���������⣬��δ���
int main()
{
	char c;
	printf("the begaining of the function.\n");
	int a = setjmp(buf);
	printf("setjmp is: %d\n", a);
	printf("please input a number:\n");
	c = getchar();//δ��ִ��
	if (c >= '0' && c <= '9')
	{
		printf("the number is %c\n", c);
	}
	else//�ⲿ�ֱ�ִ����2�Σ��ǳ����
	{
		printf("input number.\n");
		longjmp(buf, 1);//ִ�к�bufδ������
	}
}

//��ϰ����
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