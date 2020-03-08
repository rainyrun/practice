#include <stdio.h>
int myAtoi(char *string);
int main(void)
{
    char test1[50] = "1234";
    char test2[50] = "-123";
    char test3[50] = "017";
    char test4[50] = "0x12";
    char test5[50] = "abc";
    printf("1234 is %d\n", myAtoi(test1));
    printf("-123 is %d\n", myAtoi(test2));
    printf("017 is %d\n", myAtoi(test3));
    printf("0x12 is %d\n", myAtoi(test4));
    printf("abc is %d\n", myAtoi(test5));
    
    return 0;
}

int myAtoi(char *string)
{
	int sign = 1;
	int base = 10;
	int number = 0;
	if(string == NULL)
	{
		printf("the string is not exit!\n");
		return 0;
	}
	while(*string++ == ' ')
		;
    printf("skip the space.\n");
	if(*string == '+' || *string == '-')
	{
		if(*string == '-')
			sign = -1;
		string++;
	}
    printf("skip + or -.\n");
	if(*string == '0')
	{
		string++;
		if(*string == 'x' || *string == 'X')
		{
			base = 16;
			string++;
            printf("base is 16.\n");
		}
		else
        {
            base = 8;
            printf("base is 8.\n");
        }
	}
	while(*string >= '0' && *string <= '9' && *string != '\0')
	{
		number = number * base + (*string - '0');
        printf("number is %d.\n", number);
	}
    printf("number is %d.\n", number * sign);
	return number * sign;
}
