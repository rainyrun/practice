#include <stdio.h>
#include <stdlib.h>
void main()
{
	int MB = 0;
	//int KB = 0;
	//while (malloc(1 << 10))
	while (malloc(1 << 20))
		++MB;
		//++KB;
	printf("Allocated %d MB total\n", MB);//1898MB
}