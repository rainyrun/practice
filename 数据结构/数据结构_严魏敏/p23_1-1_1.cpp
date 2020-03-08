#include <stdio.h>
#include <stdlib.h>
/*读入一组整型数组，具有n个数字，选择其中第k个最大的数字*/

#define N 5
int a[N];
void get_array(int a[], int n);//获得数组，并存在a[]内
void bubble_sort(int a[], int n);//将a[]冒泡排序

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