/*��ʹ��&&��||��д����
for(i = 0; i < lim - 1 && ((c = gechar()) != '\n') && c != EOF)
	s[i] = c;
��ͬ�����ѭ�����*/

#include <stdio.h>
#define MAX 100
int main()
{
	int c, i;
	int s[MAX];
	i = 0;
	while ((c = getchar()) != EOF)
	{
        if(i >= MAX)
            break;
		if (c == '\n')
			break;
        s[i++] = c;
	}
    return 0;
}
