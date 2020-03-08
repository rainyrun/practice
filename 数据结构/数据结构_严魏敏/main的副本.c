//
//  main.c
//  StackQueue
//
//  Created by 润蕾 on 2018/4/22.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include <stdio.h>
#include "base.h"
#include "maze.h"
#include "stkpas.h"
//4.主函数和其他函数的伪码算法
void Initialization(void);
void ReadCommand(char cmd);
void InterPret(char cmd);
int main(void){
    char cmd;
    Initialization();
    do{
        ReadCommand(cmd);//读入命令
        InterPret(cmd);
    }while (cmd != 'q');
    return 0;
}
void Initialization(){
    //初始化屏幕，显示指令说明
    printf("please input command.\n'c': input file name.\n'm': find a path.\n'p': print the maze.\n'q': quit.\n");
}
void ReadCommand(char cmd){
    printf("please input a command.\n");
    cmd = getchar();
    while(cmd != 'c' && cmd != 'm' && cmd != 'p'){
        printf("please input correct command.\n");
        cmd = getchar();
    }
}
void InterPret(char cmd){
    switch(cmd){
        case 'c':
            //提示用户输入迷宫数据的文件名filename；读入行列和二维数组的数据
            InitMaze(maze, a2, rnum, cnum);
            //输出迷宫初始化完成的信息；
            break;
        case 'm':
            //提示用户输入迷宫的入口from和出口term的坐标，坐标的行号列号从1开始
            if(MazePath(maze, from, term))
                //提示用户查看结果
                else
                    //提示没有路径
                    break;
        case 'p':
            MazePrint(maze);
            break;
    }//switch
}//InterPret
