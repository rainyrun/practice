#include <stdio.h>
/*使用宏来实现max的一个版本，其中max的参数都是整数，要求在宏max的定义中这些整型参数只被求值一次。*/
static int temp1, temp2;
#define max(a,b) (temp1 = (a), temp2 = (b)  \
    temp1 > temp2 ? temp1 : temp2)
