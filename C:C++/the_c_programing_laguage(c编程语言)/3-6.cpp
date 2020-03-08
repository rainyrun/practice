#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*�޸�itoa������ʹ�øú������Խ���3�����������е���������Ϊ��С�ֶο�ȡ�
Ϊ��֤ת�������õļǹ����پ��е����������ƶ�����С��ȣ��ڱ���ҪʱӦ�����ý����������һ���Ŀո�*/
void reverse(char s[]);
void itoa(int n, char s[], int b)
{
	char a[] = "0123456789";
	int i, sign;
	i = 0;
	sign = n;
	do
	{
		s[i++] = a[abs(n % 10)];
	} while (n /= 10);
	
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';

	if (i < b)
	{
		int j;
		for (j = i; j < b - i - 1; j++)
			s[j] = ' ';
		s[j] = '\0';
	}
	reverse(s);
}

void reverse(char s[]) {
    int i, j, temp;
    for (i = 0; s[i] != '\0'; i++)
        ;
    i -= 1;
    for (j = 0; j < i; j++, i--)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
    }
}
