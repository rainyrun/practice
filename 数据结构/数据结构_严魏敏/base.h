//
//  base.h
//  StackQueue
//
//  Created by 润蕾 on 2018/4/22.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef base_h
#define base_h
#define RANGE 20
#define TRUE 1
#define FALSE 0
//1.坐标位置类型
typedef struct PosType{
    int r, c;//迷宫中r行c列的位置
} PosType;
PosType NextPos(PosType p, int dir);//给定坐标p和方向，将下一个坐标返回
bool Same(PosType a, PosType b);//比较a和b是否是同一个点，如果是，返回true；否则返回false

//1.坐标类型算法如下：
PosType NextPos(PosType p, int dir){
    PosType q;
    switch(dir){
        case 1:
            q.r = p.r;
            q.c = p.c + 1;
            break;
        case 2:
            q.r = p.r + 1;
            q.c = p.c;
            break;
        case 3:
            q.r = p.r;
            q.c = p.c - 1;
            break;
        case 4:
            q.r = p.r - 1;
            q.c = p.c;
            break;
    }
    return q;
}

bool Same(PosType a, PosType b){
    if(a.r == b.r && a.c == b.c)
        return TRUE;
    else
        return FALSE;
}

#endif /* base_h */
