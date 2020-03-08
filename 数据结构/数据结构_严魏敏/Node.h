//
//  Node.h
//  DataStructure
//
//  Created by 润蕾 on 2018/4/15.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int status;

/*
 ADT Node{
 数据对象：D = {a(i) | a(i) € CharSet, i = 1, 2……, n >= 0}
 数据关系：R1 = {}
 基本操作：
 MakeNode(&p, e)
 操作结果：p指向新生成的结点，新结点的数据域为e，指针域为null。若空间分配失败，则返回false
 FreeNode(&p)
 初始条件：p指向的结点存在
 操作结果：释放p指向的结点，并将p指向null
 CopyNode(&p)
 初始条件：p指向的结点存在
 操作结果：生成新结点，结点数据域复制p结点的数据域，指针域为null
 }
 */
typedef char ElemType;
typedef struct NodeType{
    ElemType data;
    struct NodeType *next;
} NodeType, *LinkType;

LinkType MakeNode(ElemType e);
void FreeNode(LinkType p);
LinkType CopyNode(LinkType p);

LinkType MakeNode(ElemType e){
    LinkType p;
    p = (LinkType)malloc(sizeof(NodeType));
    if(!p) return p;
    p->data = e; p->next = NULL;
    return p;
}
void FreeNode(LinkType p){
    free(p);
    p = NULL;
}
LinkType CopyNode(LinkType p){
    LinkType s;
    s = MakeNode(p->data);
    if(!s)
        return s;
    s->next = NULL;
    return s;
}

#endif /* Node_h */
