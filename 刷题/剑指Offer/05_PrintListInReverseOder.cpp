//
//  05_PrintListInReverseOder.cpp
//  C++Programing
//
//  Created by 润蕾 on 2018/6/24.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include <stdio.h>

typedef int ElemType;
typedef struct ListNode{
    ElemType data;
    struct ListNode *next;
} List;

//在链表末尾添加节点
void AddToTail(List *lists, ElemType value){
    if(lists != NULL){
        ListNode *p;
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = value;
        newNode->next = NULL;
        p = lists;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}

//找到第一个值为value的节点，删除掉
void DeleteNode(List *lists, ElemType value){
    if(lists != NULL){
        ListNode *p;
        ListNode *newNode = (ListNode*)malloc(sizeof(ListNode));
        newNode->data = value;
        newNode->next = NULL;
        p = lists;
        while(p && p->data != value)
            p = p->next;
        if(p != NULL){
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}
