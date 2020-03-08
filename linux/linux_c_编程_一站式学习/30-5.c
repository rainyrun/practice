/*
 实现一个简单的交互式Shell
 1、给出提示符，让用户输入一行命令，识别程序名和参数并调用适当的exec 函数执行程序，待执行完成后再次给出提示符。
 2、识别和处理以下符号:
     简单的标准输入输出重定向(<和>)
     管道(|)
 你的程序应该可以处理以下命令:
 ○ls△-l△-R○>○file1○
 ○cat○<○file1○|○wc△-c○>○file1○ ○表示零个或多个空格，△表示一个或多个空格
 
 思路：
 1. 打印提示符，将输入的命令存储在一个字符串内，若命令超过MAXLEN，则提示超长。命令以换行结束
    或：读取标准输入中的命令
 2. 判断命令中是否有管道，若有，则创建管道，分别处理命令的左右部分。右部分因可能存在多重管道，需递归处理
 3. 处理命令时，将命令参数存储在sh_argv[]内，并分析是否需要重定向。
 4. 支持的命令：ls, cat, quit（shell不退出就一直接受命令）
 
 测试用例：
 quit;    quit;quit   ;
 ls -l;ls   -l;   ls -l;ls -l   ;
 ls -l > test1;ls -l>test1;ls -l >test1;ls -l> test1;
 cat < file1;cat<file1;
 cat < file1 | wc -c > file2;
 
 总结：
 1. 子进程可以继承父进程的标准输入输出，因此管道的读写端重定向完成后，子进程也会继承。（不需要在参数中传递）
 
 遗留问题：
 1. 如何判断子程序是否被创建，子程序如何运行？
 */


#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>
#define MAXLEN 100   //命令不超过100个字符

const char *inner_proc[] = {"quit","cd", NULL};
enum {QUIT, CD};

int find_proc(char *name);
void deal_pipe(char command[], int lo, int hi);//[lo, hi)
void deal_redi(char command[], int lo, int hi);//[lo, hi)

int quit = 0;   //是否退出shell

int main(){
    while(!quit){   //shell不退出就一直运行
        ssize_t i;
        char command[MAXLEN];   //存储命令
        
        //输入命令
        printf("$ ");
        i = read(0, command, MAXLEN);
        if(i < 0){
            perror("read");
            exit(1);
        }
        else if(i == 0)
            continue;
        command[i - 1] = '\0';
        command[MAXLEN - 1] = '\0';
        printf("%s\n", command);
        
        deal_pipe(command, 0, MAXLEN);
    }
    return 0;
}

int find_proc(char *name){
    if(name == NULL){
        return -1;
    }
    int i;
    for (i = 0; inner_proc[i]; i++) {
        const char *p = inner_proc[i];
        char *s = name;
        while(*p && *p++ == *s++) //依次比较字符串中的字母，直到其中一个达到末尾
            ;
        if(*p == *s)
            return i;
    }
    return -1;
}

/*
 功能：检查command[lo, hi]命令中是否有管道。若有管道，则将管道的写端传递给deal_redi，读端传递给自身，递归处理command中后续的命令；如无，则调用deal_redi函数处理命令。
 参数：
 command[]：存储用户输入的命令。本函数处理command[lo, hi)部分的命令
 */

void deal_pipe(char command[], int lo, int hi){
    printf("deal_pipe.\n");
    int pipe_idx = lo;
    int fd[2];
    pid_t pid1, pid2;
    
    while(command[pipe_idx] != '|' && pipe_idx < hi && command[pipe_idx] != '\0')//检查命令中是否有管道
        pipe_idx++;
    
    if(pipe_idx < hi && command[pipe_idx] == '|'){//命令中存在管道
        command[pipe_idx] = '\0';
        printf("has pipe\n");
        if(pipe(fd) < 0){//分配管道
            perror("pipe");
            exit(2);
        }
        if((pid1 = fork()) < 0){//创建子程序1
            perror("fork");
            exit(1);
        }
        if(pid1 == 0){//子程序
            printf("child\n");
            close(fd[0]);
            dup2(fd[1], STDOUT_FILENO);//连接管道写端
            close(fd[1]);
            deal_redi(command, lo, pipe_idx);//处理前半部分，无管道
            printf("child end\n");
        }
        else{//父程序
            wait(NULL);
            printf("parent\n");
            if((pid2 = fork()) < 0){//创建子程序2
                perror("fork");
                exit(1);
            }
            if(pid2 == 0){//子程序2
                close(fd[1]);
                dup2(fd[0], STDIN_FILENO);//连接管道读端
                close(fd[0]);
                deal_pipe(command, pipe_idx + 1, hi);//处理后半部分，可能有管道
            }
            else{
                wait(NULL);
            }
        }
    }
    else{//命令中没有管道
        printf("no pipe\n");
        if((pid1 = fork()) < 0){//创建子程序
            perror("fork");
            exit(1);
        }
        if(pid1 == 0){//子程序
            deal_redi(command, lo, hi);
        }
        else{
            wait(NULL);
        }
    }
}

/*功能：将command[lo, hi)中的命令分解成token，并执行命令。
 缺陷：命令格式不正确，如，多次重定向; >和|重定向重复等问题，无法发现。
 */
void deal_redi(char command[], int lo, int hi){
    printf("deal_redi.\n");
    char *sh_argv[MAXLEN];      //命令行参数
    int i = lo;
    int argc = 0;
    
    int fd_in_idx, fd_out_idx;
    fd_in_idx = fd_out_idx = -1;
    
    int index = -1;//内建命令索引号
    int fd;
//    pid_t pid;
    
    while(i < hi && command[i] != '\0'){//将command[]中的命令分解成token，并存储在sh_argv[]中
        while(command[i] == ' '){//跳过空格
            command[i] = '\0';//填充字符串结束符，方便分割命令
            i++;
        }
        switch (command[i]) {
            case '<':   //输入重定向
                printf("<\n");
                sh_argv[argc++] = NULL;
                fd_in_idx = argc;
                command[i++] = '\0';
                break;
            case '>':   //输出重定向
                printf(">\n");
                sh_argv[argc++] = NULL;
                fd_out_idx = argc;
                command[i++] = '\0';
                break;
            default:    //参数
                sh_argv[argc++] = &command[i];//指向参数
                while(command[i] != ' ' && command[i] != '\0' && command[i] != '>' && command[i] != '<' && command[i] != '|' && i < hi){
                    i++;
                }
                break;
        }
    }
    sh_argv[argc] = NULL;
    
    int j = 0;
    for (; sh_argv[j]; j++) {
        printf("sh_argv[%d] = %s\n", j, sh_argv[j]);
    }
    
    //识别是否是内建命令
    index = find_proc(sh_argv[0]);
    switch (index) {
        case QUIT:
            quit = 1;
            printf("quiting...\n");
            break;
        case CD:
            chdir(sh_argv[1]);
            break;
        case -1://外部命令
            if(fd_in_idx != -1){//输入重定向
                fd = open(sh_argv[fd_in_idx], O_RDONLY);
                if(fd < 0){
                    perror("open fd_out");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }
            if(fd_out_idx != -1){//输出重定向
                fd = open(sh_argv[fd_out_idx], O_RDWR | O_CREAT, "w+");
                if(fd < 0){
                    perror("open fd_out");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }
            execvp(sh_argv[0], sh_argv);
            perror("execvp");
            exit(1);
            break;
        default:
            printf("no defined.\n");
            break;
    }
}
