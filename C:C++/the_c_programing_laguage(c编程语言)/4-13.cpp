#include <stdio.h>
#include <string.h>
/*��дһ���ݹ�汾��reverse(s)���ַ���s����*/

void reverse(char s[], int i, int j)
{
	if(i >= j)
        return;
    else{
        int temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        reverse(s, i+1, j-1);
    }
}

int main()
{
	char s[] = "321";
	reverse(s, 0, strlen(s) - 1);
	printf("reverse s is %s\n", s);
}
