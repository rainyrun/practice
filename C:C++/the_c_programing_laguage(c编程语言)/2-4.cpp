#include <stdio.h>
/*squeeze(s1, s2); 将字符串s1中所有和s2中的字符匹配到的字符都删除*/
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
/*还有一种不需要第三个for循环的方法，就是对s1重新赋值。
当s1中没有s2中的字符时，将s1的字符赋值给s1的当前位置
当s1中出现了s2中的字符时，该字符不保存，继续比较下一个字符
比较到最后一个字符时，将新赋值的s1的当前位置变为‘\0’*/