//
//  evaluate.h
//  BApp
//
//  Created by 润蕾 on 2018/8/9.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef evaluate_h
#define evaluate_h
#include "all.h"
#include <cmath>
#include <string.h>

#define N_OPTR 9
char prioder[N_OPTR][N_OPTR] = {//运算符优先等级[栈顶][当前]
/*            |--------------当前运算符-----------------*/
/*            |  +   -   *   /   ^   !   (   )   \0   */
/* --  + */     '>','>','<','<','<','<','<','>','>',
/* --  - */     '>','>','<','<','<','<','<','>','>',
/* 栈  * */     '>','>','>','>','<','<','<','>','>',
/* 顶  / */     '>','>','>','>','<','<','<','>','>',
/* 运  ^ */     '>','>','>','>','>','<','<','>','>',
/* 算  ! */     '>','>','>','>','>','>',' ','>','>',
/* 符  ( */     '<','<','<','<','<','<','<','=',' ',
/* --  ) */     ' ',' ',' ',' ',' ',' ',' ',' ',' ',
/* -- \0 */     '<','<','<','<','<','<','<',' ','='
};
/*备注
 1.code-0.1:
 char prioder[][9] = ……//使用现在的这种写法，拓展性更强
 */

typedef enum {ADD, SUB, MUL, DIV, POW, FAC, LP, RP, EOE, NON} Oper;

Oper toOptr(char op){
    Oper result = NON;
    switch(op){
        case '+':
            result = ADD;
            break;
        case '-':
            result = SUB;
            break;
        case '*':
            result = MUL;
            break;
        case '/':
            result = DIV;
            break;
        case '^':
            result = POW;
            break;
        case '!':
            result = FAC;
            break;
        case '(':
            result = LP;
            break;
        case ')':
            result = RP;
            break;
        case '\0':
            result = EOE;
            break;
        default:
            exit(-1);
    }
    return result;
}
/*备注
 1.简洁写法：
 case '+' : return ADD; //直接return，更简洁
 */

bool isDigit(char c){//识别字符c是否为数字
    if(0 <= (c - '0') && (c - '0')<= 9)
        return true;
    else
        return false;
}

float readNum(char* &s, char* &rpn){//将字符串转化成数字，支持小数
    float num = 0;
    float exp = 1;//命名为fraction更合适
    while(isDigit(*s)){
//        printf("%c\n", *s);
        num = num * 10 + *s - '0';
        *(rpn++) = *s;
        s++;
    }
    if(*s == '.'){
        *(rpn++) = *s;
        s++;
        while(isDigit(*s)){
            exp /= 10;
            num += (*s - '0') * exp;
            *(rpn++) = *s;
            s++;
        }
    }
    *(rpn++) = ' ';
    return num;
}
/*疑问
 1.*s++的运算顺序？答：相当于*(s++)
 2.s++什么时候自增一？答：执行完表达式后。故如果写成while(isDigit(*s++)),在while循环体内，s已变成了s+1
 3.备注：readNum的参数类型是引用，读取数字后，返回待识别的字符
 */

char compare(char optr1, char optr2){//比较两个操作符的优先级，若optr1 > optr2，返回“>”
    return prioder[toOptr(optr1)][toOptr(optr2)];
}

//^和!运算
int fac(int n){
    int result = 1;
    while (n) {
        result *= (n--);
    }
    return result;
}
/*疑问
 1.如果while中为n--，在result使用时，是n还是n-1 ？答：n-1，n在表达式结束后就会进行自减操作
 */

void operate(char s, Stack<float>& opnd){//在操作数栈中，取出操作数进行s运算，并将结果入栈
    float opnd1, opnd2;
    switch (s) {
        case '+':
            opnd1 = opnd.pop();
            opnd2 = opnd.pop();
            printf("%f + %f = \n", opnd2, opnd1);
            opnd.push(opnd2 + opnd1);
            break;
        case '-':
            opnd1 = opnd.pop();
            opnd2 = opnd.pop();
            printf("%f - %f = \n", opnd2, opnd1);
            opnd.push(opnd2 - opnd1);
            break;
        case '*':
            opnd1 = opnd.pop();
            opnd2 = opnd.pop();
            printf("%f * %f = \n", opnd2, opnd1);
            opnd.push(opnd2 * opnd1);
            break;
        case '/':
            opnd1 = opnd.pop();
            opnd2 = opnd.pop();
            printf("%f / %f = \n", opnd2, opnd1);
            //添加内容
            if(0 == opnd1) exit(-1);
            opnd.push(opnd2 / opnd1);
            break;
        case '^':
            opnd1 = opnd.pop();
            opnd2 = opnd.pop();
            printf("%f ^ %f = \n", opnd2, opnd1);
            opnd.push(pow(opnd2, opnd1));
            break;
        case '!':
            opnd1 = opnd.pop();
            printf("%f! = \n", opnd1);
            opnd.push((float)fac((int)opnd1));//仅支持整数阶乘
            break;
            
        default:
            exit(-1);
            break;
    }
}
/*备注：
 1.函数的划分原则：尽量不要传入和函数功能无关的参数。
 比如，这个函数的功能，是对操作符进行相应计算，那么就不用把操作数栈当作参数，而是将操作数栈中的内容取来做参数。如float calcu(float a, char op, float b);
 */


//, char*& RPN
float evaluate(char* S, char* rpn){
    //对已剔除空格的表达式求值，并转化为逆波兰RPN表达式
    Stack<float> opnd;//操作数栈
    Stack<char> optr;//操作符栈
    float result = -1;
    optr.push('\0');//哨兵
    while (!optr.empty()) {
        if(isDigit(*S)){//读入数字
            opnd.push(readNum(S, rpn));//数字入栈
        }
        else{//读入操作符
            switch(compare(optr.top(), *S)){
                case '<':
                    optr.push(*S++);
                    break;
                case '>':
                    operate((*(rpn++) = optr.pop()), opnd);
                    *(rpn++) = ' ';
                    break;
                case '=':
                    optr.pop();
                    S++;
                    break;
                default:
                    exit(-1);
            }
        }
    }//while
    result = opnd.pop();
    if(opnd.empty())
        return result;
    else
        return -1;
}
/*备注：
 1.错误代码：
 case '>':
 char temp = optr.pop();//错误，switch,case内不能直接定义对象
 ……
 解决方法1（推荐）：在case后加{}，如 case '=':{ …… } break;
 解决方法2：
 case '=':
 ;//后面进行对象的创建
 break;
 2.数字转换成字符串的简便方法：
 sprintf(buf, "%.2f \0", opnd);//sprintf:将格式化的数据，写入字符串buf中
 3.rpn加长的简便方法：strcat(rpn, buff);//将rpn和buf拼接起来，并放入rpn中。rpn必须由足够的空间
 4.rpn转换，要添加适当的分隔符，如“ ”。
 5.错误代码：
 while (*S == '\0'){……}//'\0'是哨兵，它不是循环结束的条件
 6.重载append()函数，将字符串添加到rpn结尾，可以使函数看起来更清晰
 */


void test_eva(){
//测试toOptr
//    char s[] = {'+', '-', '*', '/', '^', '!', '(', ')', '\0', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
//    for (int i = 0; i < 9; i++) {
//        if(i == toOptr(s[i]))
//            printf("%d, toOptr pass\n", i);
//        if(!isDigit(s[i]))
//            printf("%d isDigit pass\n", i);
//    }
//    for (int i = 9; i < 19; i++) {
//        if(isDigit(s[i]))
//            printf("%d isDigit pass\n", i);
//    }
    
////测试readNum
//    char* p[] = {"97", "0.53", "12.4", "abc", "55+", "43.87-12+4"};
//    for (int i = 0; i < 6; i++) {
//        printf("%f\n", readNum(p[i]));
//    }
//
////测试operate()
//    Stack<float> temp;
//    temp.push(5.6);
//    temp.push(7);
//    temp.push(1);
//    temp.push(2.2);
//    temp.push(3.4);
//    temp.push(5.4);
//    temp.push(7.3);
//    temp.push(6.2);
//    for (int i = 0; i < 8; i++) {
//        operate(s[i], temp);
//    }
    
//测试evaluate
    fac(3);
    char rpn[3][20];
    char* compute[] = {"1*3+2/4+(5-3)+6/3!", "1+2-3+4^2*(2-2)", "(1*2)^2^1+1.23-2.1*4+3!!/2"};
    for (int i = 0; i < 3; i++) {
        printf("%f\n", evaluate(compute[i], rpn[i]));
    }
}


#endif /* evaluate_h */
