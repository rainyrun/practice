#include <stdio.h>
#define IN 1
#define OUT 0
/*以每行一个单词的形式，打印其输入*/
int main(){
    int c, state;
    state = OUT;
    while((c = getchar()) != EOF){
        if(c == '\t' || c == ' ' || c == '\n'){
            if(state == IN)
                printf("\n");
            state = OUT;
        }
        else{
            state = IN;
            putchar(c);
        }
    }
}
