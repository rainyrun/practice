/*不使用&&和||，写出和
for(i = 0; i < lim - 1 && ((c = gechar()) != '\n') && c != EOF)
	s[i] = c;
相同含义的循环语句*/

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
