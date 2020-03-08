#include <stdio.h>
int isnum(char s);
long atol(char *s)
{
	int neg = 1;
	char *p = s;
	long m = 0;
	//跳过空格
	for (; *p == ' '; p++)
		;
	//判断正负
	if (*p == '-')
	{
		neg = 1;
	}
    //跳过符号位
    if(*p == '-' || *p == '+')
        p++;
		
	//判断是否是数字
	while (isnum(*p))
	{
        int temp = *p - '0';
        if(neg){//如果是负数，直接用负数计算，避免溢出
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
