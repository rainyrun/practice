//
//  OrdList.h
//  DataStructure
//
//  Created by 润蕾 on 2018/4/15.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef OrdList_h
#define OrdList_h
/*
 ADT OrderedList{
 数据对象：D = {a(i) | a(i) € Node, i = 1, 2……, n >= 0}
 数据关系：R1 = {<a(i-1), a(i)> | a(i) € Node }
 基本操作：
 InitList(&L)
 操作结果：构造一个空的有序表L
 DestroyList(&L)
 初始条件：有序表L存在
 操作结果：销毁有序表L
 AppendElem(&L, p)
 初始条件：有序表L存在
 操作结果：在有序表L的末尾插入结点p
 InsertAfter(&L, p, e)
 初始条件：有序表L存在，p指向的结点在链表L内
 操作结果：将元素e插在p指向结点之后，插入失败返回false
 LocateElem(L，e)
 初始条件：有序表L存在
 操作结果：返回指针p，指向不大于e的最大元素的结点，若有元素=e，则返回null
 }
 */
#include "Node.h"
typedef struct OrderedList{
    LinkType head, tail;
} OrderedList;

OrderedList *InitList(void);
void DestroyList(OrderedList *L);
void AppendElem(OrderedList *L, LinkType s);
status InsertAfter(OrderedList *L, LinkType p, ElemType e);
LinkType LocateElem(OrderedList *L, ElemType e);

OrderedList *InitList(void){
    //需要增设头指针作为MakeNode的参数
    OrderedList *L;
    L = (OrderedList*)malloc(sizeof(OrderedList));
    if (L) {
        L->head = MakeNode(' ');
        if(L->head)
            L->tail = L->head;
        else
            L->head = L->tail = NULL;
    }
    return L;
}//InitList
void DestroyList(OrderedList *L){
    LinkType p,s;
    p = L->head;
    while(p){
        s = p; p = p->next; FreeNode(s);
    }
    L->head = L->tail = NULL;
}
void AppendElem(OrderedList *L, LinkType s){
    if(L->head && s){
        //需要增设有序链表的尾指针，否则AppendElem的时间复杂度为O(n)，而此函数又经常用到
        L->tail->next = s;
        L->tail = s;
    }
}//AppendElem
status InsertAfter(OrderedList *L, LinkType p, ElemType e){
    LinkType q;
    q = MakeNode(e);
    if(!q)
        return FALSE;
    if(!p->next){
        L->tail = q;
    }
    q->next = p->next;
    p->next = q;
    return TRUE;
}
LinkType LocateElem(OrderedList *L, ElemType e){
    LinkType s,p;
    s = L->head;
    p = L->head->next;
    while(p && p->data <= e){
        if(p->data == e)
            return NULL;
        s = p; p = p->next;
    }
    return s;
}

#endif /* OrdList_h */
