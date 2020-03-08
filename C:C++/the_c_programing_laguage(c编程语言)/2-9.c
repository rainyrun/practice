#include <stdio.h>
/*表达式x &= (x - 1)可以删除x中最右边值为1的一个二进制位。请用这一方法，统计x的二进制数中1的个数
 思路：
 1. 当 (x &= (x - 1)) == 0时，循环终止，计算循环次数即可
 */
int bitcount(int x);

int main(){
    bitcount(3);
    bitcount(15);
}

int bitcount(int x){
    int i;
    i = 0;
    for(i = 0; x != 0; x &= (x - 1))
        i++;
    return i;
}
