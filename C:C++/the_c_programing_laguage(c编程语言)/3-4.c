#include <stdio.h>
/*书p50的itoa函数(将数值转化为字符串）不能处理最大的负数，因为最大的负数不能用正数表示出来。修改该函数，使得它在任何机器上运行都能打印出正确的值。
 思路：
 1. 直接使用负数x计算，计算出的余数取反，求的实际的字符。当x = 0时，结束计算
 */
void itoa(int n, char s[]);

int main(){
    char s[15];
    itoa(123, s);
    return 0;
}

void itoa(int n, char s[]){
    int i, sign, temp;
    i = 0;
    if((sign = n) > 0)//转化为负数
        n = -n;
    do{
        temp = - n % 10;
        s[i++] = '0' + temp;
    }while((n /= 10) != 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';//还需要用reverse函数逆转，且s[0] = '\0'，此处忽略
    printf("%s\n", s);
}
