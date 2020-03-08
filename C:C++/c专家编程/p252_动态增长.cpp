#include <stdio.h>
#include <stdlib.h>

int current_element = 0;
int totle_element = 128;
char *dynamic = (char *)malloc(totle_element);

void add_element(char c)
{
	if (current_element == totle_element - 1)
	{
		totle_element *= 2;
		dynamic = (char *)realloc(dynamic, totle_element);
		if (dynamic == NULL)
			printf("can't expend the table.\n");
	}
	dynamic[++current_element] = c;
}