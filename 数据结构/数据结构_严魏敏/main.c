//
//  main.c
//  DataStructure
//
//  Created by 润蕾 on 2018/4/15.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include "OrdList.h"
#include "OrdSet.h"
#define LEN 20

void Initialization(void);
void ReadCommand(char *c);
void Interpret(char c, OrderedSet *set1, OrderedSet *set2);

int main(void){
    char c;
    OrderedSet *set1, *set2;
    set1 = set2 = NULL;
    Initialization();//屏幕初始化，展示操作命令提示
    set1 = CreatSet(" ");
    set2 = CreatSet(" ");
    do{
        ReadCommand(&c);
        Interpret(c, set1, set2);
    }while(c != 'q' && c != 'Q');
    return 0;
}//main
void Initialization(){
    printf("please input cmds.\n");
    printf("  1 = input set1.\n  2 = input set2.\n  u = union.\n  i = intersection.\n  d = difference.\n  q & Q = quit.\n");
}
void ReadCommand(char *c){
    do{
        printf("please input a command.\n");
        scanf("%c", c);
    }while((*c != '1') && (*c != '2') && (*c != 'u') && (*c != 'i') && (*c != 'd') && (*c != 'q') && (*c != 'Q'));
}
void Interpret(char c, OrderedSet *set1, OrderedSet *set2){
    char str1[LEN], str2[LEN];
    OrderedSet *T;
    switch(c){
        case '1':
            //获取字符串str1，以回车为结尾
            printf("please input set1:\n");
            scanf("%s",str1);
            //set1存在时，要先销毁
            if(set1)
                DestroySet(set1);
            T = CreatSet(str1);
            *set1 = *T;
            PrintSet(*set1);
            break;
        case '2':
            //获取字符串str2，以回车为结尾
            printf("please input set2:\n");
            scanf("%s",str2);
            if(set2)
                DestroySet(set2);
            T = CreatSet(str2);
            *set2 = *T;
            PrintSet(*set2);
            break;
        case 'u':
            T = Union(*set1, *set2);
            PrintSet(*T);
            DestroySet(T);
            break;
        case 'i':
            T = Intersection(*set1, *set2);
            PrintSet(*T);
            DestroySet(T);
            break;
        case 'd':
            T = Difference(*set1, *set2);
            PrintSet(*T);
            DestroySet(T);
            break;
        case 'q':
        case 'Q':
            DestroySet(set1);
            DestroySet(set2);
            break;
    }
}
