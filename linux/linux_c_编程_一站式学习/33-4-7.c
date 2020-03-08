/*请编写一个程序完成以下功能:
 父进程fork出子进程，子进程调用exit(2)终止，父进程自定义SIGCHLD信号的处理函数，在其中调用wait获得子进程的退出状态并打印。*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_chld(int signo);

int main(){
    pid_t pid;
    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, suspmask;
    
    if((pid = fork()) < 0){//创建子进程
        perror("fork");
        exit(1);
    }
    if(pid == 0){//子进程
        exit(3);
    }
    else{//父进程
        //自定义SIGCHLD的处理函数
        newact.__sigaction_u.__sa_handler = sig_chld;
        sigemptyset(&newact.sa_mask);
        newact.sa_flags = 0;
        sigaction(SIGCHLD, &newact, &oldact);
        
        //悬挂进程直到有SIGCHLD信号到来
        sigemptyset(&newmask);
        sigaddset(&newmask, SIGCHLD);
        sigprocmask(SIG_BLOCK, &newmask, &oldmask);
        
        suspmask = oldmask;
        sigdelset(&suspmask, SIGCHLD);//临时解除SIGCHLD信号的屏蔽
        
        sigsuspend(&suspmask);//悬挂结束后，恢复对SIGCHLD信号的屏蔽
        
        //恢复SIGCHLD
        sigaction(SIGCHLD, &oldact, NULL);
    }
    return 0;
}

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
