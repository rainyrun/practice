/*从命令行参数中获得一个字符串发给服务器，然后接收服务器返回的字符串并打印。*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);	//获取sockfd

	//设置servaddr
	bzero(&servaddr, sizeof(servaddr));	//将servaddr空间置0
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	Connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));//连接到socket

	while(fgets(buf, MAXLINE, stdin) != NULL){//从标准输入中不断读取
		Write(sockfd, buf, strlen(buf));//写入socket中

		n = Read(sockfd, buf, MAXLINE);//读取服务器响应到buf
		if(n == 0){
			printf("the other side has been closed.\n");
			break;
		}
		else{
			printf("Response from server:\n");
			Write(STDOUT_FILENO, buf, n);
			printf("\n");
		}
	}
	Close(sockfd);
	return 0;
}
