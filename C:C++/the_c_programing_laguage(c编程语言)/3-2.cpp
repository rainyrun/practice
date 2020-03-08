#include <stdio.h>
/*��дһ������escape(s, t)��
���ַ���t���Ƶ��ַ���s�У�
���ڸ��ƹ����н����з����Ʊ���Ȳ��ɼ��ַ��ֱ�ת��Ϊ\n��\t����Ӧ�Ŀɼ���ת���ַ����С�
Ҫ��ʹ��swich��䡣
�ٱ�дһ�������෴���ܵĺ������ڸ��ƹ����н�ת���ַ�����ת��Ϊʵ���ַ���*/

/*��ע
1. switch������Ƕ�ס�unescape�е�if-else if������switch�滻
2. д�Ĳ�ȫ��ֻ�г���2��ת���ַ��������в���*/
void escape(char s[], char t[])
{
	int i, j;
	for (i = 0, j = 0; t[i] != '\0'; i++, j++)
	{
		switch (t[i]) {
		case '\n':
			s[j] = '\\';
			s[++j] = 'n';
			break;
		case '\t':
			s[j] = '\\';
			s[++j] = 't';
			break;
		default:
			s[j] = t[i];
			break;
		}
	}
	s[j] = '\0';
}

void unescape(char s[], char t[]) {
	int i, j;
	for ( i = 0, j = 0; t[i] != '\0'; i++, j++)
	{
		switch (t[i]) {
			case '\\':
				if (t[i + 1] == 'n') {
					++i;
					s[j] = '\n';
				}
				else if (t[i + 1] == 't') {
					++i;
					s[j] = '\t';
				}
				else
					s[j] = t[i];
				break;
			default:
				s[j] = t[i];
		}
	}
	s[j] = '\0';
}

#define MAX 100
int main() {
	char t[] = "abc\nweg\tsieg";
	char s[MAX];
	char f[MAX];

	printf("%s\n", t);

	//escape(s, t);
	//printf("%s\n", s);

	//unescape(f, s);
	//printf("%s\n", f);
}