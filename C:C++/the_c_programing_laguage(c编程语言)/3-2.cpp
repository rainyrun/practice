#include <stdio.h>
/*编写一个函数escape(s, t)，
将字符串t复制到字符串s中，
并在复制过程中将换行符、制表符等不可见字符分别转换为\n、\t等相应的可见的转移字符序列。
要求使用swich语句。
再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。*/

/*备注
1. switch语句可以嵌套。unescape中的if-else if可以用switch替换
2. 写的不全，只列出了2个转自字符，可自行补充*/
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