#include <stdio.h>
#include <stdlib.h>
/*��д����itob(n, s, b)��������nת��Ϊ��bΪ�׵���������ת��������ַ�����ʽ���浽�ַ���s�С�
 ����itob(n, s, 16)������n��ʽ��Ϊ16��������������s�С�*/

void reverse(char s[]);

void itob(int n, char s[], int b) {
    //static char alpha[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
	int i, sign;
	i = 0;
	sign = n;
    //assert(b >= 2 && b <= 36);
	do
	{
		s[i++] = alpha[abs(n % b)];
	} while (n /= b);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	printf("s is: %s\n", s);
	reverse(s);
	printf("reverse s is: %s\n", s);
}

void reverse(char s[]) {
	int i, j, temp;
	for (i = 0; s[i] != '\0'; i++)
		;
	printf("the lenth of s is : %d\n", i);
	i -= 1;
	for (j = 0; j < i; j++, i--)
	{
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}

int main() {
	char s[10];
	int a = -52;
	int b = 10;
	int c = 16;
	int d = 2;

	//itob(a, s, b);
	//printf("ʮ��������%s\n", s);
	//itob(a, s, c);
	//printf("ʮ����������%s\n", s);
	itob(a, s, d);
	printf("����������%s\n", s);
}
