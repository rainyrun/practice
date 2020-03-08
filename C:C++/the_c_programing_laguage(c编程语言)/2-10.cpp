#include <stdio.h>
/*重新编写将大写字母转换为小写字母的函数lower，并用条件表达式替代其中的if-else结构*/

char lower(char s)
{
	return ((s >= 'A') && (s <= 'Z')) ? (s - 'A' + 'a') : s;
}