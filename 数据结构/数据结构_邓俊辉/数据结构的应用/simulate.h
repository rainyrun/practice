//
//  simulate.h
//  BApp
//
//  Created by 润蕾 on 2018/8/13.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef simulate_h
#define simulate_h
#include "all.h"
#define OPEN_TIME 40
#define WIN_NUM 5

struct Customer{
    int number;//客户编号
    int arriveTime;//到达时间
    int serveTime;//要求服务时间
    int windowNum;//排队窗口
    int leaveTime;//离开时间
    Customer(int num = 1, int arr = -1, int ser = -1, int win = -1, int lea = -1) : number(num), arriveTime(arr), serveTime(ser), windowNum(win), leaveTime(lea){}
};

Customer* generate(int& num, int time){//生成客户
    int sertime = rand() % 20 + 1;
    return new Customer( ++num, time, sertime, -1, sertime + time);
}

int sugWin(Queue<Customer>* win){//返回人最少的窗口号
    int num = 0;//人最少窗口号
    int people = INT_MAX;//最少的人数
    for (int i = 0; i < WIN_NUM; i++) {
        if(win[i].size() < people){
            num = i;
            people = win[i].size();
        }
    }
    return num;
}

void simulate(){//模拟银行客户排队
    Queue<Customer> windows[WIN_NUM];//开放WIN_NUM个窗口
    int num = 0;//客户数
    for (int i = 0; i < OPEN_TIME; i++) {
        if(rand() % 4){//客户按照3/4的概率到达
            int sertime = rand() % 20 + 1;
            Customer cur(++num, i, sertime, -1, sertime + i);//当前到达的客户
            printf("customer %d comes at time %d, needs servetime %ds, will leave at %d.\n", cur.number, cur.arriveTime, cur.serveTime, cur.leaveTime);
            cur.windowNum = sugWin(windows);//推荐人少的窗口
            windows[cur.windowNum].enqueue(cur);//客户去排队
            printf("customer %d waited at win %d.\n", cur.number, cur.windowNum);
        }
        for (int j = 0; j < WIN_NUM; j++) {//遍历窗口，服务完的客户出队
            if(windows[j].size() && (i == windows[j].front().leaveTime)){
                printf("customer %d leaves.\n", windows[j].front().number);
                windows[j].dequeue();
            }
        }
    }
//    delete [] windows;//下班……(^-^)
}
/*备注
 1.初始代码：
 Queue<Customer*> windows[WIN_NUM];//其实并不需要指针，直接存放客户即可
 cur = generate(num, i);//生成客户(可以不用写成函数，直接声明对象，如Customer cur(a,b,c,d,e)
 */


void test_simu(){
    srand((unsigned int) time(NULL));
    simulate();
}

#endif /* simulate_h */
