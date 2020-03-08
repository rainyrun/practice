#include <stdio.h>
/*删除每个输入行末尾的空格及制表符，并删除完全是空格或制表符的行
 思路：
 1. 如果输入空格或制表符，使用队列存储该字符，直到遇到其他字符
 2. 如果输入非空格、制表符、换行符，则打印队列中存储的字符，和该字符
 3. 如果输入换行符，如果是空行（只有空格或制表符或换行符），则跳过；否则打印换行符
 4. 输入的空字符超过队列上限，返回值报错。
 */
#define EXIT_FAILURE 1
#define MAXQUEUE 10
int advance(int index);

int main(){
    int queue[MAXQUEUE], c, head, tail, newline;
    head = tail = 0;
    newline = 0;
    while((c = getchar()) != EOF){
        if(c == '\n'){
            if(newline)
                printf("\n");
            newline = 0;//有新的“非空”字符出现，才会置1
            head = tail = 0;//队列置空
        }
        else if(c == ' ' || c == '\t'){
            if(advance(head) == tail){//队满
                return EXIT_FAILURE;
            }
            queue[head] = c;
            head = advance(head);
        }
        else{//非空字符出现
            newline = 1;
            while(tail != head){//队列不为空，打印队列中的“空格”
                putchar(queue[tail]);
                tail = advance(tail);
            }
            putchar(c);
        }
    }
}

int advance(int index){
    if(index < MAXQUEUE - 1)
        return index + 1;
    else
        return 0;
}
