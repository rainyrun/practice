//
//  queen_stack.h
//  BApp
//
//  Created by 润蕾 on 2018/8/11.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef queen_stack_h
#define queen_stack_h
#include "all.h"

struct Queen{
    int x, y;//皇后的坐标
    Queen(int xx = 0, int yy = 0): x(xx), y(yy) {};
    bool operator!= (Queen q){
        if(q.x == x || q.y == y || (q.x + q.y) == (x + y) || (q.y - q.x) == (y - x))//在同一行或同一列或同一对角线
            return false;
        return true;
    }
};
/*备注
 1.错误代码(stack@vector的构造函数)：Vector(……, T v = 0){
 在八皇后问题里，构造Stack<Queen> S,时，提示No viable conversion from 'int' to 'Queen'。需要写Queen的构造函数
 */

void placeQueen(int n){//在n*n的棋盘上放置n个皇后，并输出路线
    Stack<Queen> S;
    int i = 0;//第i行
    int j = 0;//第j列
    while(j < n && S.size() < n){
        Queen q(i, j);
        if(S.empty()){//栈空，则皇后位置合法，放置皇后（使用find接口可简化这步）
            S.push(q);//放置皇后
            i++; j = 0;//找下一行的位置
        }
        else{//栈非空
            int k;
            for (k = 0; k < i && S[k] != q; k++);//和已放置的皇后比较(可使用find接口）
            if(k == i){//若位置合法
                S.push(q);//放置皇后
                i++; j = 0;//找下一行的位置
            }
            else{
                if(j == n - 1){//若已比较到最后一个位置
                    do{
                        q = S.pop();//拿起上一个皇后，重新找合适的位置
                        i = q.x;
                        j = q.y + 1;
                    }while (j == n);//若上一个皇后已比较到最后一个位置
                }//if
                else//下一个皇后
                    j++;
            }
        }
    }//while
    while(!S.empty()){//输出路线
        Queen temp(0,0);
        temp = S.pop();
        printf("%dth Queen: x = %d, y = %d.\n", n--, temp.x, temp.y);
    }
}

void test_queen(){
    Queen q1(1, 1), q2(0, 2);
    if(!(q1 != q2))
        printf("pass.\n");
    placeQueen(8);
}

#endif /* queen_stack_h */
