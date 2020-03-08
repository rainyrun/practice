#include <stdio.h>
/*删除c语言程序中所有的注释语句。要正确处理带引号的字符串与字符常量。在c语言中，注释不允许嵌套
 思路：
 1. 注释有2种形式：/ * * / 和 //
 2. 变量in_comment = IN表示在注释内, = OUT表示在注释外。遇到／*后，in_comment变为IN，遇到*／后，in_comment变为OUT
 3. 在“”内的／*不需要识别
 4. 遇到／／后，直接忽略后面的字符，直到遇到换行
 */
#define IN 1
#define OUT 0

int main(){
    int c, in_comment, in_quote;
    in_comment = OUT;
    in_quote = OUT;
    while((c = getchar()) != EOF){
        if(c == '"'){
            in_quote = !in_quote;
            putchar(c);
        }
        else if(c == '/'){
            if(!in_quote){//不在引号内
                if((c = getchar()) == '*'){//进入注释
                    do{
                        while((c = getchar()) != '*')
                            ;
                    }while((c = getchar()) != '/');
                }//出注释
                else if(c == '/'){//进入注释
                    while((c = getchar()) != '\n')//忽略整行
                        ;
                    putchar(c);//换行
                }//出注释
                else{
                    putchar('/');
                    putchar(c);
                }
            }
            else//在引号内
                putchar(c);
        }
        else
            putchar(c);
    }//while
    return 0;
}
