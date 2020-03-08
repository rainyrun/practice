//
//  convert.h
//  BApp
//
//  Created by 润蕾 on 2018/8/7.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef convert_h
#define convert_h
#include "all.h"

//void convert(Stack<char>& S, int n, int base){//十进制数n到base进制数的转换（递归版）
//    char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
//    if(n == 0) return;//递归基
//    convert(S, n/base, base);
//    S.push(digit[n % base]);
//    printf("%c\n", digit[n % base]);
//}

/*备注：
 扩展版：n为负数的情况*/

void convert(Stack<char>& S, int n, int base){//十进制数n到base进制数的转换（迭代版）
    char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    while (n != 0){
        S.push(digit[n % base]);
        n /= base;
    }
    while (S.size()) {//输出
        printf("%c\n", S.pop());
    }
}

#endif /* convert_h */
