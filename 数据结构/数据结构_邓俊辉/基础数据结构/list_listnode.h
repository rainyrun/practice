//
//  list_listnode.h
//  BDS
//
//  Created by 润蕾 on 2018/8/3.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef list_listnode_h
#define list_listnode_h

#define ListNodePosi(T) ListNode<T>*
//类型名，首字母大写；变量or函数名，首字母小写

template <class T>
struct ListNode{//列表节点模版类（双向链表）
    T data;//元素
    ListNodePosi(T) pred;//前驱
    ListNodePosi(T) succ;//后继
    //构造函数
    ListNode(){}
    ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL)
    :data(e), pred(p), succ(s){}
    
    //操作接口
    ListNodePosi(T) insertAsPred(T e);//紧靠当前节点插入前驱
    ListNodePosi(T) insertAsSucc(T e);//紧靠当前节点插入后继
};
/*疑问
 1.结构体是否也支持模版？答：C++中的结构体和类几乎相同，也支持构造和析构函数。不同的是，构造函数和析构函数在结构体中默认是公有的。
 2.为什么不只在List类中定义插入操作？
 */
template <class T>
ListNodePosi(T) ListNode<T>::insertAsPred(T e){
    ListNodePosi(T) p = new ListNode(e, pred, this);
    pred->succ = p;
    pred = p;
    return p;
}

template <class T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T e){
    ListNodePosi(T) p = new ListNode(e, this, succ);
    succ->pred = p;
    succ = p;
    return p;
}

#endif /* list_listnode_h */
