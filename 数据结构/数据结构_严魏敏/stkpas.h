//
//  stkpas.h
//  StackQueue
//
//  Created by 润蕾 on 2018/4/22.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef stkpas_h
#define stkpas_h
//2.栈类型
typedef struct ElemType{
    PosType seat;
    int d;//表示下一步的方向
} ElemType;

typedef struct NodeType{
    ElemType data;
    struct NodeType *next;
} NodeType, *NodeLink;

typedef NodeLink Stack;

void InitStack(Stack *S);
void DestroyStack(Stack *S);
bool IsEmpty(Stack S)
void Push(Stack *S, ElemType e);
void Pop(Stack *S, ElemType *e);
NodeLink MakeNode(ElemType e);

//2.栈类型算法如下：
void InitStack(Stack *S){
    S = NULL;
}
bool Push(Stack *S, ElemType e){
    //若空间分配成功，则在S的栈顶插入新的栈顶元素e，并返回TRUE；否则栈不变，并返回FALSE
    NodeLink p;
    p = MakeNode(e);
    if(!p) return FALSE;
    p->next = *S;
    *S = p;
    return TRUE;
}
bool Pop(Stack *S, ElemType *e){
    //若栈不空，则删除S的栈顶元素并以e带回其值，且返回true；否则返回false，且e无意义
    if (IsEmpty(*S))
        return FALSE;
    else{
        p = *S;
        *S = p->next;
        *e = p->data;
        free(p);
    }
}
void DestroyStack(Stack *S){
    while(*S){
        p = *S;
        *S = p->next;
        free(p);
    }
}
bool IsEmpty(Stack S){
    if(!S)
        return FALSE;
    else
        return TRUE;
}
NodeLink MakeNode(ElemType e){
    p = (NodeLink)malloc(sizeof(NodeType));
    p->data = e;
    p->next = NULL;
    return p;
}
#endif /* stkpas_h */
