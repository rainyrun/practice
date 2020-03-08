//
//  OrdSet.h
//  DataStructure
//
//  Created by 润蕾 on 2018/4/15.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef OrdSet_h
#define OrdSet_h
/*
 ADT OrderedSet{
 数据对象：D = {a(i) | a(i) € Node, i = 1, 2……, n >= 0}
 数据关系：R1 = {}
 基本操作：
 CreatSet(&T, str)
 初始条件：存在字符串str
 操作结果：过滤str中的非法字符和重复字符，并生成一个数据升序排列的集合T
 DestroySet(&T)
 初始条件：集合T存在
 操作结果：销毁集合T
 Union(&T, set1, set2)
 初始条件：se1, set2存在
 操作结果：求set1，set2点并集T
 Intersection(&T, set1, set2)
 初始条件：se1, set2存在
 操作结果：求set1，set2点交集T
 Difference(&T, set1, set2)
 初始条件：se1, set2存在
 操作结果：求set1，set2点差集T
 PrintSet(T)
 初始条件：集合T存在
 操作结果：打印集合T中的元素
 }
*/
#include "OrdList.h"
#include <string.h>
#include <ctype.h>
typedef OrderedList OrderedSet;
OrderedSet *CreatSet(char *s);
void DestroySet(OrderedSet *T);
OrderedSet *Union(OrderedSet set1, OrderedSet set2);
OrderedSet *Intersection(OrderedSet set1, OrderedSet set2);
OrderedSet *Difference(OrderedSet set1, OrderedSet set2);
void PrintSet(OrderedSet T);

OrderedSet *CreatSet(char *s){
    OrderedSet *T;
    LinkType p;
    T = InitList();
    if(T){//构造空集合T
        for(int i = 0; i < strlen(s); i++ ){
            //生成集合时，需要将元素插在合适的位置，链表需增设InsertAfter()将元素放在合适的位置，增设LocateElem()查找插入的位置
            //printf("s[%d] = %c.\n", i, s[i]);
            if(islower(s[i])){//过滤非法元素
                p = LocateElem(T, s[i]);
                if(p){
                    //printf("*p = %c.\n", p->data);
                    if(!InsertAfter(T, p, s[i]))
                        printf("insert failure.\n");
                }
            }
        }
    }
    return T;
}//CreatSet
void DestroySet(OrderedSet *T){
    DestroyList(T);
}//DestroySet
//在操作过程中，有很多地方扔需要判断结点是否生成。应尽量封装在各类操作中，使用时不用考虑太多空间问题
OrderedSet *Union(OrderedSet set1, OrderedSet set2){
    LinkType p, q;
    OrderedSet *T;
    T = CreatSet(" ");
    if(T){
        p = set1.head->next; q = set2.head->next;
        while(p && q){
            if(p->data == q->data){
                AppendElem(T, CopyNode(p));
                p = p->next;
                q = q->next;
            }
            else if(p->data > q->data){
                AppendElem(T, CopyNode(q));
                q = q->next;
            }
            else{
                AppendElem(T, CopyNode(p));
                p = p->next;
            }
        }//while
        while(p){
            AppendElem(T, CopyNode(p));
            p = p->next;
        }
        while(q){
            AppendElem(T, CopyNode(q));
            q = q->next;
        }
    }
    return T;
}//Union
OrderedSet *Intersection(OrderedSet set1, OrderedSet set2){
    LinkType p, q;
    OrderedSet *T;
    T = CreatSet(" ");
    if(T){
        p = set1.head->next; q = set2.head->next;
        while(p && q){
            if(p->data == q->data){
                AppendElem(T, CopyNode(p));
                q = q->next;
                p = p->next;
            }
            else if(p->data < q->data)
                p = p->next;
            else
                q = q->next;
        }//while
    }
    return T;
}//Intersection
OrderedSet *Difference(OrderedSet set1, OrderedSet set2){
    LinkType p, q;
    OrderedSet *T;
    T = CreatSet(" ");
    if(T){
        p = set1.head->next; q = set2.head->next;
        while(p && q){
            if(p->data == q->data){
                p = p->next;
                q = q->next;
            }
            else if(p->data < q->data){
                AppendElem(T, CopyNode(p));
                p = p->next;
            }
            else{
                q = q->next;
            }
        }//while
        while(p){
            AppendElem(T, CopyNode(p));
            p = p->next;
        }
    }
    return T;
}//Difference
void PrintSet(OrderedSet T){
    LinkType p;
    p = T.head->next;
    while(p){
        printf("%c, ", p->data);
        p = p->next;
    }
    printf(".\n");
}

#endif /* OrdSet_h */
