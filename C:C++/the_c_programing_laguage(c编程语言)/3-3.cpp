#include <stdio.h>
/*��д����expand(s1, s2)�����ַ���s1��������a-zһ����ټǷ�����s2����չΪ�ȼ۵������б�abc��xyz��
�ú������Դ����Сд��ĸ�����֣������Դ���a-b-c��a-z0-9��-a-z�����Ƶ��������Ϊǰ����β���-�ַ�ԭ����ӡ��
 ˼·��
 1. ÿ����'-'�ַ�ʱ���ж�ǰ���ַ��Ĵ�С������ǰ������ĸ�����֣���ǰ<��ģ�������չ��
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
