#include <stdio.h>
/*��д����any(s1, s2),���ַ���s2�е���һ�ַ����ַ���s1�е�һ�γ��ֵ�λ����Ϊ������ء����s1�в�����s2�е��ַ����򷵻�-1*/
int any(char s1[], char s2[])
{
	for ( int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
				return i;
		}
	}
	return -1;
}

int main()
{
	char s1[] = "abcdefg";
	char s2[] = "hi";
	int a;

	a = any(s1, s2);
	printf("%d\n", a);
}