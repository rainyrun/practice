#include <stdio.h>
#include <limits.h>
/*��дһ������ungets(s)���������ַ���sѹ�ص������С�
ungets������Ҫʹ��buf��bufp�����ܷ��ʹ��ungetch������*/

void ungets(char s[])
{
	int i = strlen(s);
	while (i > 0)
	{
		ungetch(s[--i]);
	}
}