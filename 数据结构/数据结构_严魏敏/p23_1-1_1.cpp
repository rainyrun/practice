#include <stdio.h>
#include <stdlib.h>
/*����һ���������飬����n�����֣�ѡ�����е�k����������*/

#define N 5
int a[N];
void get_array(int a[], int n);//������飬������a[]��
void bubble_sort(int a[], int n);//��a[]ð������

int main(void)
{
	get_array(a, N);
	bubble_sort(a, N);
	printf("the %dth biggest number is :%d.\n", N / 2, a[N / 2 - 1]);
	return 0;
}

void get_array(int a[], int n)
{
	int i = 0;
	char c;
	char temp[N];
	printf("please input %d numbers, sigment by 1 chars.\n", N );
	while (i < n)
	{
		c = getchar();
		if (c >= '0' && c <= '9')
		{
			int j = 0;
			while (c >= '0' && c <= '9')
			{
				temp[j++] = c;
				c = getchar();
			}
			temp[j] = '\0';
			a[i++] = atoi(temp);
		}
		else
		{
			printf("please input a number.\n");
		}
	}
}

void bubble_sort(int a[], int n)
{
	int i, j;
	int temp;
	for ( i = 0; i < n; i++)
	{
		for ( j = 0; j < n - i; j++)
		{
			if (a[j] < a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}