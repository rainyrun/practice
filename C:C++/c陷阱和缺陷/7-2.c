#include <stdio.h>
int isnum(char s);
long atol(char *s)
{
	int neg = 1;
	char *p = s;
	long m = 0;
	//�����ո�
	for (; *p == ' '; p++)
		;
	//�ж�����
	if (*p == '-')
	{
		neg = 1;
	}
    //��������λ
    if(*p == '-' || *p == '+')
        p++;
		
	//�ж��Ƿ�������
	while (isnum(*p))
	{
        int temp = *p - '0';
        if(neg){//����Ǹ�����ֱ���ø������㣬�������
            temp = -temp;
        }
		m = m * 10 + temp;
	}
	return m;
}

int isnum(char s)
{
	char *num = "0123456789";
	for (int i = 0; i < 10; i++)
	{
		if (num[i] == s)
			return 1;
	}
	return 0;
}
