#include <stdio.h>
/*squeeze(s1, s2); ���ַ���s1�����к�s2�е��ַ�ƥ�䵽���ַ���ɾ��*/
void squeeze(char s1[], char s2[]);

int main()
{
	char s1[] = "absqwewbdqwdda";
	char s2[] = "w";
	squeeze(s1, s2);
	printf("%s\n", s1);
}

void squeeze(char s1[], char s2[])
{
	for (int i = 0; s1[i] != '\0'; i++)
	{
		for (int j = 0; s2[j] != '\0'; j++)
		{
			if (s1[i] == s2[j])
			{
				int k = i;
				for ( k = i; s1[k] != '\0'; k++)
				{
					s1[k] = s1[k + 1];
				}
				s1[k] = '\0';
			}
		}
	}
}
/*����һ�ֲ���Ҫ������forѭ���ķ��������Ƕ�s1���¸�ֵ��
��s1��û��s2�е��ַ�ʱ����s1���ַ���ֵ��s1�ĵ�ǰλ��
��s1�г�����s2�е��ַ�ʱ�����ַ������棬�����Ƚ���һ���ַ�
�Ƚϵ����һ���ַ�ʱ�����¸�ֵ��s1�ĵ�ǰλ�ñ�Ϊ��\0��*/