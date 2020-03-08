//
//  maze.h
//  StackQueue
//
//  Created by 润蕾 on 2018/4/22.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef maze_h
#define maze_h
//3.迷宫类型
typedef struct MazeType{
    int m, n;//行和列
    char arr[RANGE][RANGE];
} MazeType;
void InitMaze(MazeType *maze, int a[][], int row, int col);
bool MazePath(MazeType *maze, PosType start, PosType end)
void MarkPrint(MazeType maze);
bool IsPass(MazeType maze, PosType p);
void FootPrint(MazeType *maze, PosType p);
void MazePrint(MazeType *maze, PosType p);
//3.迷宫类型算法如下：
void InitMaze(MazeType *maze, int a[][], int row, int col){
    //按用户输入的row行col列初始化迷宫M
    //迷宫最外围包上一层障碍
    *maze.m = row;
    *maze.n = col;
    for (int i = 0; i < row + 2; ++i)
    {
        for (int j = 0; j < col + 2; ++j)
        {
            if(i == 0 || i == (row + 1) || j == 0 || j == (col + 1))
                *maze.arr[i][j] = '#';
            else{
                switch(a[i-1, j-1]){
                    case 0:
                        *maze.arr[i, j] = '#';
                        break;
                    case 1:
                        *maze.arr[i, j] = ' ';
                }
            }//else
        }//for
    }//for
}
bool IsPass(MazeType maze, PosType p){
    if(maze.arr[p.r][p.c] == ' ')
        return TRUE;
    else
        return FALSE;
}
void FootPrint(MazeType *maze, PosType p){
    *maze.arr[p.r][p.c] == '*';
}
void MarkPrint(MazeType *maze, PosType p){
    *maze.arr[p.r][p.c] == '@';
}
bool MazePath(MazeType *maze, PosType start, PosType end){
    //start和end在迷宫内，若迷宫maze中存在从入口start到出口end到通道，则求得一条存放在栈中，并返回true；否则返回false
    InitStack(S);
    PosType curpos = start;
    bool found = FALSE;
    do{
        if(IsPass(*maze, curpos)){
            FootPrint(maze, curpos);
            e = (curpos, 1);//e是ElemType类型，是“e.seat = curpos; e.d = 1;”的简便记法
            Push(&S, e);
            if(Same(curpos,end)) found = TRUE;
            else{
                curpos = NextPos(curpos, 1);
            }
        }//if
        else{//当前位置不能通过
            if(!IsEmpty(S)){
                Pop(&S, e);
                while (e.d == 4 && !IsEmpty(S)){
                    MarkPrint(maze, e.seat);
                    Pop(&S, e);
                }
                if(e.d < 4){
                    e.d += 1;
                    Push(&S, e);
                    curpos = NextPos(e.seat, e.d);
                }
            }
        }//else
    }while(!IsEmpty(S) && !found);
    return found;
}
void MazePrint(MazeType maze){
    for (int i = 1; i < (maze.m + 1); ++i){
        for (int j = 1; j < (maze.n + 1); ++j){
            printf("%c", maze.arr[i][j]);
        }
        printf("\n");
    }
}
#endif /* maze_h */
