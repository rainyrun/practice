//
//  laby.h
//  BApp
//
//  Created by 润蕾 on 2018/8/13.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef laby_h
#define laby_h
#include "all.h"

#define MAZE_SIZE 10

typedef enum {avalible, route, wall, backed} Status;
typedef enum {unkown, east, south, west, north, noway} Direct;//迷宫格点方向，初始为unkown，四个方向都尝试过，变为noway（方便判断）

struct Cell{
    int x,y;//迷宫格点坐标
    Status status;
    Direct outcoming;//出单元格的方向
    bool operator != (Cell cell);
    Cell(int xx = 0, int yy = 0, Status ostatus = avalible, Direct odir = unkown) : x(xx), y(yy), status(ostatus), outcoming(odir) {};
};

//判断该单元格是否是通路
bool pass(const Cell& cur){
    if(cur.status == avalible)
        return true;
    return false;
}
//重载!=运算符
//bool Cell::operator != (Cell cell){
//    if(x == cell.x && y == cell.y)
//        return true;
//    return false;
//}

//根据当前单元格的方向，在maze中找到下一个单元格
Cell* nextCell(Cell maze[MAZE_SIZE][MAZE_SIZE], const Cell& cur){
    switch (cur.outcoming) {
        case east:
            return &(maze[cur.x][cur.y + 1]);
        case south:
            return &(maze[cur.x + 1][cur.y]);
        case west:
            return &(maze[cur.x][cur.y - 1]);
        case north:
            return &(maze[cur.x - 1][cur.y]);
        default:
            printf("outcoming undirect.\n");
            exit(-1);
            break;
    }
}

//转向下个方向
void nextDirect(Cell& cell){
    switch (cell.outcoming) {
        case unkown:
            cell.outcoming = east;
            break;
        case east:
            cell.outcoming = south;
            break;
        case south:
            cell.outcoming = west;
            break;
        case west:
            cell.outcoming = north;
            break;
        case north:
            cell.outcoming = noway;
            break;
        default:
            break;
    }
}

void printMaze(Cell maze[MAZE_SIZE][MAZE_SIZE]){
    printf("maze is :\n");
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            if(maze[i][j].status == wall)
                printf("* ");
            else if(maze[i][j].status == route)
                printf("- ");
            else if(maze[i][j].status == backed)
                printf("o ");
            else
                printf("  ");
        }
        printf("\n");
    }
}

void labyrinth(Cell maze[MAZE_SIZE][MAZE_SIZE], Cell& start, Cell& end){
    //迷宫maze为n * n的数组，start为迷宫起点，end为迷宫终点
    /*添加代码：退化情况*/
    if(start.status != avalible || end.status != avalible)
        return;
    Stack<Cell*> S;//需要修改maze中内容，故需要使用指针(名：path)
    Cell* nextc;//下一个前进的迷宫格点
    start.status = route;
    S.push(&start);//起点入栈
    do {
        Cell* cur = S.top();
        nextDirect(*cur);//转向下一个方向
        if(cur->outcoming == noway){//四个方向都尝试过，则
            cur->status = backed;//回溯
            S.pop();
//            printMaze(maze);
        }
        else{//否则转入下一方向
            nextc = nextCell(maze, *cur);//在maze中找到下一个单元格，因为要修改cell中的内容，所以需要使用指针
            if(pass(*nextc)){//若下一方向能够走通，则
                nextc->status = route;
                S.push(nextc);//入栈
//                printMaze(maze);
            }
        }
    } while (S.top() != &end && !S.empty());
    printMaze(maze);
}

void buildMaze(Cell maze[MAZE_SIZE][MAZE_SIZE]){//生成迷宫，简陋版
    for (int i = 0; i < MAZE_SIZE; i++) {
        for (int j = 0; j < MAZE_SIZE; j++) {
            maze[i][j].x = i;
            maze[i][j].y = j;
//            maze[i][j].status = avalible;
//            maze[i][j].outcoming = unkown;
        }
    }
    for(int i = 0; i < MAZE_SIZE; i++){//造墙
        maze[0][i].status = wall;
        maze[MAZE_SIZE - 1][i].status = wall;
        maze[i][0].status = wall;
        maze[i][MAZE_SIZE - 1].status = wall;
    }
    for (int i = 3; i < 9; i++) {//造墙
        maze[3][i].status = wall;
        maze[i - 1][3].status = wall;
    }
    printMaze(maze);
}



void test_maze(){
    Cell maze[MAZE_SIZE][MAZE_SIZE];
    buildMaze(maze);
    labyrinth(maze, maze[1][6], maze[8][2]);
}
/*备注
 1.错误代码：
 Cell maze[MAZE_SIZE][MAZE_SIZE];
 buildMaze(maze);//No matching function for call to 'buildMaze'
 ???原因：buildMaze()的参数类型是Cell**，改为Cell maze[MAZE_SIZE][MAZE_SIZE]即可
 */

#endif /* laby_h */
