#include <stdio.h>
/*���±�д����д��ĸת��ΪСд��ĸ�ĺ���lower�������������ʽ������е�if-else�ṹ*/

char lower(char s)
{
	return ((s >= 'A') && (s <= 'Z')) ? (s - 'A' + 'a') : s;
}