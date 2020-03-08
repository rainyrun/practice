#include <stdio.h>
/*编写函数expand(s1, s2)，将字符串s1中类似于a-z一类的速记符号在s2中扩展为等价的完整列表abc…xyz。
该函数可以处理大小写字母和数字，并可以处理a-b-c、a-z0-9与-a-z等类似的情况。作为前导和尾随的-字符原样排印。
 思路：
 1. 每遇到'-'字符时，判断前后字符的大小，符合前后都是字母或数字，且前<后的，进行拓展。
 */

void expand(char s1[], char s2[]) {
	int i, j;
	for (i = 0, j = 0; s1[i] != '\0'; i++, j++)
	{
		if ((s1[i] >= 'A') && (s1[i] <= 'Z')) {
			if (s1[i + 1] == '-') {
				if ((s1[i + 2] >= 'A') && (s1[i + 2] <= 'Z') && (s1[i + 2] > s1[i])) {
					int k = s1[i + 2] - s1[i];
					for (int m = 0; m < k; m++, j++)
					{
						s2[j] = s1[i] + m;
					}
					i += 1;
					j--;
				}
				else {
					s2[j] = s1[i];
					s2[++j] = s1[++i];
				}
			}
			else
				s2[j] = s1[i];
		}
		else if ((s1[i] >= 'a') && (s1[i] <= 'z')) {
			if (s1[i + 1] == '-') {
				if ((s1[i + 2] >= 'a') && (s1[i + 2] <= 'z') && (s1[i + 2] > s1[i])) {
					int k = s1[i + 2] - s1[i];
					for (int m = 0; m < k; m++, j++)
					{
						s2[j] = s1[i] + m;
					}
					i += 1;
					j--;
				}
				else {
					s2[j] = s1[i];
					s2[++j] = s1[++i];
				}
			}
			else
				s2[j] = s1[i];
		}
		else if ((s1[i] >= '0') && (s1[i] <= '9')) {
			if (s1[i + 1] == '-') {
				if ((s1[i + 2] >= '0') && (s1[i + 2] <= '9') && (s1[i + 2] > s1[i])) {
					int k = s1[i + 2] - s1[i];
					for (int m = 0; m < k; m++, j++)
					{
						s2[j] = s1[i] + m;
					}
					i += 1;
					j--;
				}
				else {
					s2[j] = s1[i];
					s2[++j] = s1[++i];
				}
			}
			else
				s2[j] = s1[i];
		}
		else if (s1[i] == '-') {
			if (i == 0)
				s2[j] = s1[i];
			else {
				if (s1[i - 1] == '-')
					s2[j] = s1[i];
				else {
					i -= 2;
					j--;
				}
			}
		}
		else
			s2[j] = s1[i];
	}
	s2[j] = '\0';
}

int main() {
	char s1[] = "-a-dweong-A-D e--0-3woea-b-c";
	//char s1[] = "b-aIGkd";
	char s2[100];

	expand(s1, s2);

	printf("%s\n", s2);
}
