/*从客户端读字符，然后将每个字符转换为大写并回送给客户端。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"
#include <sys/wait.h>
#include <signal.h>

#define MAXLINE 80
#define SERV_PORT 8000  //端口号

void sig_chld(int signo);

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n, pid;
    struct sigaction newact, oldact;
    
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);//创建监听socket
    
    //初始化servaddr
    bzero(&servaddr, sizeof(servaddr)); //servaddr存储空间置0
    servaddr.sin_family = AF_INET;      //ipv4
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   //INADDR_ANY表示本地的任意ip地址
    servaddr.sin_port = htons(SERV_PORT);
    
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//绑定ip地址和端口号
    
    Listen(listenfd, 20);   //声明listenfd处在监听状态，最多允许有20个客户端处在连接等待状态

    //自定义SIGCHLD的处理函数
    newact.sa_handler = sig_chld;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGCHLD, &newact, &oldact);    
    
    printf("Accepting connections ...\n");
    while (1) {
        cliaddr_len = sizeof(cliaddr);
        connfd = Accept(listenfd, (struct sockaddr*) &cliaddr, &cliaddr_len);//cliaddr为传出参数，传递客户端的地址和端口号

        if((pid = fork()) < 0){
            perr_exit("fork");
        }
        else if(pid == 0){//子进程
            Close(listenfd);
            while(1){
                n = Read(connfd, buf, MAXLINE);
                if(n == 0){
                    printf("the other side has been closed\n");
                    break;
                }
                printf("received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));
                for (i = 0; i < n; i++)
                    buf[i] = toupper(buf[i]);
                Write(connfd, buf, n);
            }
            Close(connfd);
        }
        else{//父进程
            Close(connfd);
        }
    }
    //恢复SIGCHLD
    sigaction(SIGCHLD, &oldact, NULL);
}
//SIGCHLD信号处理函数
void sig_chld(int signo){
    int stat_val;
    wait(&stat_val);
    if (WIFEXITED(stat_val)){//子进程正常终止
        printf("Child exited with code %d\n", WEXITSTATUS(stat_val));//打印退出状态
    }
    else if (WIFSIGNALED(stat_val)){//子进程收到信号终止
        printf("Child terminated abnormally, signal %d\n", WTERMSIG(stat_val));//打印信号编号
    }
}
