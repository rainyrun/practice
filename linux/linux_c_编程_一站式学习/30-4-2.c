/*请读者修改例 30.7 “管道”的代码和实验条件，验证我上面所说的四种特殊情况。*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 80
int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];
    if (pipe(fd) < 0) {//管道分配失败
        perror("pipe");
        exit(1);
    }
    if ((pid = fork()) < 0) {//子程序分配失败
        perror("fork");
        exit(1);
    }
    if (pid > 0) { /* parent */
        close(fd[0]);
//        sleep(10);
        write(fd[1], "hello world\n", 12);
//        close(fd[1]);//case1: pipe写端关闭
        wait(NULL);//等待第一个终止的子进程
    } else { /* child */
        close(fd[1]);
//        close(fd[0]);
        n = (int) read(fd[0], line, MAXLINE);
        printf("first read %d chars\n", n);
        write(STDOUT_FILENO, line, n);
        n = (int) read(fd[0], line, MAXLINE);//case1: 验证read是否返回0；case2: 验证子进程在pipe中没有内容时是否阻塞
        printf("second read %d chars\n", n);
        write(STDOUT_FILENO, line, n);
    }
    return 0;
}
