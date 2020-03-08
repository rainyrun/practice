/*从客户端读字符，然后将每个字符转换为大写并回送给客户端。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000  //端口号

int main(void)
{
    struct sockaddr_in servaddr, cliaddr;
    socklen_t cliaddr_len;
    int listenfd, connfd, maxfd, sockfd;
    int nready, client[FD_SETSIZE];
    fd_set rset, allset;
    char buf[MAXLINE];
    char str[INET_ADDRSTRLEN];
    int i, n, maxi;
    pid_t pid;
    
    listenfd = Socket(AF_INET, SOCK_STREAM, 0);//创建监听socket
    
    //初始化servaddr
    bzero(&servaddr, sizeof(servaddr)); //servaddr存储空间置0
    servaddr.sin_family = AF_INET;      //ipv4
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);   //INADDR_ANY表示本地的任意ip地址
    servaddr.sin_port = htons(SERV_PORT);
    
    Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));//绑定ip地址和端口号
    
    Listen(listenfd, 20);   //声明listenfd处在监听状态，最多允许有20个客户端处在连接等待状态

    maxi = -1;
    maxfd = listenfd;

    for (i = 0; i < FD_SETSIZE; ++i){
        client[i] = -1;//-1表示可用的entry
    }
    FD_ZERO(&allset);//将集合清0
    FD_SET(listenfd, &allset);//将listenfd加入集合
    
    printf("Accepting connections ...\n");
    while (1) {
        rset = allset;
        nready = select(maxfd+1, &rset, NULL, NULL, NULL);//从[0, maxfd+1)读出准备好的文件数
        printf("nready is %d\n", nready);
        if(nready < 0){
            perror("select error:");
        }
        if(FD_ISSET(listenfd, &rset)){//创建新socket
            cliaddr_len = sizeof(cliaddr);
            connfd = Accept(listenfd, (struct sockaddr*) &cliaddr, &cliaddr_len);//cliaddr为传出参数，传递客户端的地址和端口号
            printf("received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));
            for(i = 0; i < FD_SETSIZE; i++){//存储connfd
                if(client[i] == -1){
                    client[i] = connfd;
                    break;
                }
            }
            if(i == FD_SETSIZE){
                fputs("too much clients\n", stderr);
                exit(1);
            }
            FD_SET(connfd, &allset);
            if(connfd > maxfd)
                maxfd = connfd;
            if(i > maxi)
                maxi = i;
            if(--nready == 0)//除了listenfd外，没有已准备好的socket连接
                continue;
        }

        for(i = 0; i <= maxi; i++){
            if((sockfd = client[i]) < 0)
                continue;
            if(FD_ISSET(sockfd, &rset)){
                if((n = Read(sockfd, buf, MAXLINE)) == 0){//客户端链接已关闭
                    printf("the other side has been closed\n");
                    Close(sockfd);
                    FD_CLR(sockfd, &allset);
                    client[i] = -1;
                }
                else{
                    int j;
                    for (j = 0; j < n; j++)
                        buf[j] = toupper(buf[j]);
                    Write(connfd, buf, n);
                }
                if(--nready == 0)//没有待处理的链接
                    break;
            }
        }
    }//while
}
