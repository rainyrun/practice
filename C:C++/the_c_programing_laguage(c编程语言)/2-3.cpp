#include <stdio.h>
#include <stdlib.h>
/*��ʮ�������ַ���ת������֮�ȼ۵�����ֵ��������ѡ��ǰ׺0x��0X���ַ���������0-9��a~f��A~F*/

int main()
{
	//strtoul("f00", 0, 16);����Ӧ���Ƶ��ַ���ת��Ϊ�޷��ų�����
	int n;//���������ֵ
	int c;
	int first;//�жϵ�һ�����Ƿ���0

	n = 0;
	first = 1;

	while ((c = getchar()) != EOF && (c != ' ') && (c != '\n'))
	{
		if (c == '0' && first)
		{
            if((c = getchar()) != 'x' && c != 'X')
            {
                printf("preindex error: please input 0x or 0X\n");
                return 0;
            }
            first = 0;
            continue;
		}
		else
		{
			if (c >= 'a' && c <= 'f')
			{
				n = n * 16 + (c - 'a' + 10);
			}
			else if (c >= 'A' && c <= 'F')
			{
				n = n * 16 + (c - 'A' + 10);
			}
			else if (c >= '0' && c <= '9')
			{
				n = n * 16 + (c - '0');
			}
			else
			{
				printf("input error\n");
				n = 0;
			}
		}
	}
    printf("the num is: %d\n", n);
    return 0;
}
