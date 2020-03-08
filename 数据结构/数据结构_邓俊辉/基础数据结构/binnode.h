//
//  binode.h
//  BDS
//
//  Created by 润蕾 on 2018/8/13.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef binode_h
#define binode_h
#include "queue@list.h"
#include "stack@vector.h"

#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)

//节点颜色

template <class T>
class BinNode{
public:
    T data;//数据元素
    BinNodePosi(T) parent;//双亲
    BinNodePosi(T) lc;//左孩子
    BinNodePosi(T) rc;//右孩子
    int height;//该节点所在的子树高
    //左式堆
    //颜色
/*备注：因BinTree类要频繁访问BinNode的上述成员，如果声明称private，那么需要提供对应的接口，供BinTree访问。所以示例代码才会写成结构体。*/
    //构造函数
    BinNode() : parent(NULL), lc(NULL), rc(NULL), height(0) {}
    BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) llc = NULL, BinNodePosi(T) rrc = NULL, int h = 0) : data(e), parent(p), lc(llc), rc(rrc), height(h){}
    int size();//以该节点为根的子树规模
    BinNodePosi(T) insertAsLC(const T& e);//将数据e作为节点的左孩子（原无）插入
    BinNodePosi(T) insertAsRC(const T& e);//将数据e作为节点的右孩子（原无）插入
    BinNodePosi(T) succ();//返回该节点按中序遍历的直接后继
    void travLevel(void (*visit)(T&));//从该节点开始，层序遍历
    /*备注：
     1.错误代码：void travLevel((*visit(T)));//C++ requires a type specifier for all declarations
     解决方法：函数指针加上类型
     */
    void travPre(void (*visit)(T&));//从该节点开始，先序遍历
    void travIn(void (*visit)(T&));//从该节点开始，中序遍历
    void travIn_I2(void (*visit)(T&));
    void travIn_I3(void (*visit)(T&));
    void travPost(void (*visit)(T&));//从该节点开始，先序遍历
    //运算符重载
    //旋转
};

template <class T>
BinNodePosi(T) BinNode<T>::insertAsLC(const T& e){
    return lc = new BinNode(e, this);
}

template <class T>
BinNodePosi(T) BinNode<T>::insertAsRC(const T& e){
    return rc = new BinNode(e, this);
}

template <class T>
void BinNode<T>::travLevel(void (*visit)(T&)){
    Queue<BinNodePosi(T)> Q;
    Q.enqueue(this);
    while (!Q.empty()) {
        BinNodePosi(T) p = Q.dequeue();
        visit(p->data);
        if (p->lc)
            Q.enqueue(p->lc);
        if(p->rc)
            Q.enqueue(p->rc);
    }
    printf("\n");
}

template <class T>
void BinNode<T>::travPre(void (*visit)(T&)){
    Stack<BinNodePosi(T)> S;
    BinNodePosi(T) p = this;
    S.push(p);
    while(!S.empty()){
        p = S.pop();
        while(p){//visitAlongLeftChild
            visit(p->data);
            S.push(p->rc);
            p = p->lc;
        }
    }
    printf("\n");
}
/*备注
 1.错误代码：
 do{
 while(p){//visitAlongLeftChild
 visit(p->data);
 S.push(p);//!入栈的是已访问的节点“根”
 p = p->lc;
 }
 p = S.pop();
 p = p->rc;//转入右子树
 }while(!S.empty());//!当转向“根”的右子树时，栈可能为空，此时循环提前终止
 */

template <class T>
void BinNode<T>::travIn(void (*visit)(T&)){
    Stack<BinNodePosi(T)> S;
    BinNodePosi(T) p = this;
    while(true){
        while(p){//goAlongLeftChild
            S.push(p);
            p = p->lc;
        }//左
        if(S.empty())
            break;
        p = S.pop();//中(在pop()前需要考虑栈是否为空的问题
        visit(p->data);
        p = p->rc;//转入右子树
    }
    printf("\n");
}

template <class T>
void BinNode<T>::travIn_I2(void (*visit)(T&)){
    Stack<BinNodePosi(T)> S;
    BinNodePosi(T) p = this;
    while(true){
        if(p){
            S.push(p);
            p = p->lc;//遍历左子树
        }
        else if(!S.empty()){
            p = S.pop();
            visit(p->data);
            p = p->rc;//遍历右子树
        }
        else
            break;
    }
    printf("\n");
}

template <class T>
void BinNode<T>::travIn_I3(void (*visit)(T&)){//中序遍历，无辅助栈版
    BinNodePosi(T) p = this;
    bool backtrace = false;
    while(true){
        if(p->lc && !backtrace)//有左孩子，且不是回溯过来的
            p = p->lc;//深入左孩子遍历
        else{//没有左孩子，或是回溯来的
            visit(p->data);
            if(p->rc){
                backtrace = false;
                p = p->rc;//深入右孩子遍历
            }
            else{
                p = p->succ();
                if(!p)
                    break;
                backtrace = true;
            }
        }
    }
}


template <class T>
void BinNode<T>::travPost(void (*visit)(T&)){
    Stack<BinNodePosi(T)> S;
    BinNodePosi(T) p = this;
    S.push(p);
    while (!S.empty()) {
        if(S.top() != p->parent){//不是双亲，则必为右子树
            /*gotoHLVFL*/
            while((p = S.top())) {//深入右子树，按照未来访问顺序的逆序，将节点入栈
                if(p->lc){//沿左子树前进
                    if(p->rc)//入栈顺序先右
                        S.push(p->rc);
                    S.push(p->lc);//后左（未来访问顺序为先左后右）
                    p = p->lc;
                }
                else{//无左子树
                    S.push(p->rc);//右子树根节点入栈
                }
            }
            S.pop();
            /*gotoHLVFL*/
        }
        p = S.pop();
        visit(p->data);
    }
    printf("\n");
}

template <class T>
int BinNode<T>::size(){
    int s = 1;
    if(lc) s += lc->size();
    if(rc) s += rc->size();
    return s;
}
/*备注
 1.类似先序遍历*/

template <class T>
BinNodePosi(T) BinNode<T>::succ(){
    BinNodePosi(T) p = this;
    if(rc){//有右孩子，则必为右子树中最靠左的后代
        p = rc;
        while(p->lc)
            p = p->lc;
    }
    else{//无，则后继必为含该节点的左子树的最近的祖先
        while(p->parent && (p->parent->lc != p))//需要判断是否是根节点，即，双亲是否存在
            p = p->parent;
        p = p->parent;
    }
    return p;
}

#endif /* binode_h */
