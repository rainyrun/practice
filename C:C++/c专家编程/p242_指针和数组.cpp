#include <stdio.h>

void my_function_1(int fruit[2][3][5]) { printf("parameter is fruit[2][3][5]\n"); }
void my_function_2(int fruit[][3][5]) { printf("parameter is fruit[][3][5]\n"); }
void my_function_3(int(*fruit)[3][5]) { printf("parameter is (*fruit)[3][5]\n"); }

void main()
{
	int apricot[2][3][5];
	my_function_1(apricot);
	my_function_2(apricot);
	my_function_3(apricot);

	int(*p)[3][5] = apricot;
	my_function_1(p);
	my_function_2(p);
	my_function_3(p);

	int(*q)[2][3][5] = &apricot;
	my_function_1(*q);
	my_function_2(*q);
	my_function_3(*q);
}
