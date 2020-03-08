#include <stdio.h>
/*O(N)���Ӷȣ��ַ����еĿո��滻Ϊ%20���滻ԭ�ַ���*/
#include <string.h>
#define MAXLEN 100
struct string_info
{
	int len;
	int space;
};

struct string_info get_info(char s[]);
void change_space(char s[], int maxlen);

int main(void)
{
	char s[MAXLEN];
	strcpy(s, "we are happy.");
	change_space(s, MAXLEN);
	printf("s is: %s \n", s);
	strcpy(s, "     ");
	change_space(s, MAXLEN);
	printf("s is: %s \n", s);
	strcpy(s, "wearehappy.");
	change_space(s, MAXLEN);
	printf("s is: %s \n", s);
	strcpy(s, "");
	change_space(s, MAXLEN);
	printf("s is: %s \n", s);
	strcpy(s, "w");
	change_space(s, MAXLEN);
	printf("s is: %s \n", s);
}

struct string_info get_info(char s[])
{
	struct string_info s_info;
	s_info.len = 0;
	s_info.space = 0;

	if (s == NULL)//sΪ��ָ��ʱ�Ĵ���
		return s_info;
	
	char *temp = s;//����sָ���ַ���ĩβ
	while (*temp != '\0')
	{
		s_info.len++;
		if (*temp == ' ')
			s_info.space++;
		temp++;
	}
	printf("s_info.len = %d.\ns_info.space = %d.\n", s_info.len, s_info.space);
	return s_info;
}

/*���ַ����еĿո���%20�滻*/
void change_space(char s[], int maxlen)
{
	struct string_info s_info = get_info(s);
	int tail_sp = s_info.len;//originalLength-->indexOfOriginal
	int new_sp = s_info.len + s_info.space * 2;//newLength-->indexOfNew
	if (new_sp > maxlen)
		return;
	while (new_sp != tail_sp)
	{
		if (s[tail_sp] == ' ')
		{
			s[new_sp--] = '0';
			s[new_sp--] = '2';
			s[new_sp--] = '%';
		}
		else
		{
			s[new_sp--] = s[tail_sp];
		}
		tail_sp--;
	}
	//printf("s is: %s \n", s);
}