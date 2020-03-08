//
//  bst.h
//  BDS
//
//  Created by 润蕾 on 2018/8/26.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include "bintree.h"

template <class T>
class BST : public BinTree<T>{
protected:
    BinNodePosi(T)& _root = BinTree<T>::_root;//为解决子类不能直接访问派生类的问题
    int& _size = BinTree<T>::_size;//为解决子类不能直接访问派生类的问题
    
    BinNodePosi(T) _hot;//指向目标节点的父节点
    BinNodePosi(T) connect34(BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c, BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3);//3+4重组，返回重组后的根节点
    BinNodePosi(T) rotateAt(BinNodePosi(T) v);//旋转，对v的父亲，祖父做旋转
public:
    virtual BinNodePosi(T)& search(const T& e);//在BST中从p节点开始向后查找元素e，hot更新_hot
    virtual BinNodePosi(T) insert(const T& e);//插入元素e，并返回插入位置。假设没有重复节点
    virtual bool remove(const T& e);//删除元素e
};
/*备注
 1.search函数拆分出searchIN，是因为递归版需要传递参数，所以需要拆出一个带参数的函数来
 2.search(), insert(), remove()以virtual修饰，强制要求所有派生类（BST变种）根据各自的规则对其重写
 */

template <class T>
BinNodePosi(T)& BST<T>::search(const T& e){
    return searchIn(_root, e, _hot);
}
/*
 1.示例代码：return searchIn ( _root, e, _hot = NULL );
 对父节点做初始化，应对查询元素为根的情况
 2.返回节点位置的引用，方便后续的插入、删除操作。
 */


template <class T>
static BinNodePosi(T)& searchIn(BinNodePosi(T)& p, const T& e, BinNodePosi(T)& hot){
    if(!p || p->data == e)
        return p;
    hot = p;
    if(p->data < e)
        return searchIn(p->rc, e, hot);
    else
        return searchIn(p->lc, e, hot);
}
/*
 1.错误提示：
 if(!p || p->data == e)
 return p;//Reference to stack memory associated with local variable 'p' returned
 原因：函数参数应该是BinNodePosi(T)& p,而不是BinNodePosi(T) p,
 */

template <class T>
static BinNodePosi(T)& searchIn_I(BinNodePosi(T)& p, const T& e, BinNodePosi(T)& hot){//迭代版
    while(p || p->data != e){
        hot = p;
        if(p->data < e)
            p = p->rc;
        else
            p = p->lc;
    }
    return p;
}

template <class T>
BinNodePosi(T) BST<T>::insert(const T& e){
    BinNodePosi(T)& p = search(e);
    BinNodePosi(T) m = new BinNode<T>(e, _hot);
    if(p)//如果元素已存在
        return NULL;
    if(!_hot){
        _root = m;
        return m;
    }
    else if(&(_hot->lc) == &p){//p是_hot的左孩子
        _hot->lc = m;
        return _hot->lc;
    }
    else{//p是_hot的右孩子
        _hot->rc = m;
        return _hot->rc;
    }
//    p = new BinNode<T>(e, _hot);
    _size++;
    BinTree<T>::updateHeightAbove(p->parent);
    return p;
}
/*
 1.注意考虑在空树插入空节点的情况。简洁版代码：
 BinNodePosi(T)& p = search(e);
 if(p)//如果元素已存在
 return NULL;
 p = new BinNode<T>(e, _hot);//!
 2.错误代码
     else if(_hot->lc == p){//p是_hot的左孩子
         _hot->lc = m;
         return _hot->lc;
     }
     else{//p是_hot的右孩子
         _hot->rc = m;
         return _hot->rc;
     }
 p必然是NULL，_hot->lc == p必然相等，以上代码不能正确插入。改成&(_hot->lc) == &p可正确运行。
 */

template <class T>
bool BST<T>::remove(const T& e){
    BinNodePosi(T)& p = search(e);
    if(!p)//如果元素不存在
        return false;
    if(!p->lc){//左子树为空
        if(p->rc)//右子树非空
            p->rc->parent = p->parent;//右子树代替p的位置
        if(p == p->parent->lc)//p是左孩子
            p->parent->lc = p->rc;
        else//p是右孩子
            p->parent->rc = p->rc;
        //简洁版：p = p->rc;
    }
    else if(!p->rc){//右子树为空
        p->lc->parent = p->parent;//左子树代替p的位置
        if(p == p->parent->lc)//p是左孩子
            p->parent->lc = p->lc;
        else//p是右孩子
            p->parent->rc = p->lc;
    }
    else{//左右子树都不为空
        BinNodePosi(T) q = p->succ();//找到p的后继
        
        T temp = p->data;//交换两节点的元素值
        p->data = q->data;
        q->data = temp;
        
        ((q->parent == p) ? q->parent->rc : q->parent->lc) = q->rc;//并删除后继元素（此时后继元素的左子树必为空）
        q->rc->parent = q->parent;
        p = q;
    }
    _hot = p->parent;//_hot记录被删除节点的父亲
    _size--;
    BinTree<T>::updateHeightAbove(_hot);
    delete p;
    return true;
}
/*
 1.示例代码将remove()拆出了removeAt()函数，removeAt()可适用更多的类。
 2.错误代码：
 q->parent->lc = q->rc;//并删除后继元素（此时后继元素的左子树必为空）
 少考虑了q是p的右孩子的情况
 3.通用函数应如何处理？如swap()，如何保证不重复编写？
 */

template <class T>
BinNodePosi(T) BST<T>::connect34(BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c, BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3){
    if(!a || !b || !c)//在rotateAt()函数判断更合适
        return NULL;
    a->lc = T0;
    a->rc = T1;
    if(T0)
        T0->parent = a;
    if(T1)
        T1->parent = a;
    a->parent = b;
    
    c->lc = T2;
    c->rc = T3;
    if(T2)
        T2->parent = c;
    if(T3)
        T3->parent = c;
    c->parent = b;
    
    b->lc = a;
    b->rc = c;
    BinTree<T>::updateHeight(b);
    return b;
}

template <class T>
BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v){
    BinNodePosi(T) p = v->parent;
    BinNodePosi(T) g = p->parent;
    if(!v)
        exit(-1);
    if(p == g->lc){//p是g的左孩子
        if(v == p->lc){//v是p的左孩子(zigzig)
            p->parent = g->parent;//向上联接
            return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
        }
        else{//v是p的右孩子(zagzig)
            v->parent = g->parent;
            return connect34(p, v, g, p->lc, v->rc, v->lc, g->rc);
        }
    }
    else{//p是g的右孩子
        if(v == p->lc){//v是p的左孩子(zigzag)
            v->parent = g->parent;
            return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
        }
        else{//v是p的右孩子(zagzag)
            p->parent = g->parent;
            return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
        }
    }
}
/*
 1.错误代码：BinNodePosi(T) gf = FromParentTo(*g);
 在尝试将重组后的子树和原树链接在一起时，当g为root时，重组后g可能有父亲，但是FromParentTo宏在运行时生成，判断g是不是root的依据是g有没有父亲，此时判断出错。
 示例代码将链接放在了上层代码中。
 */

#endif /* bst_h */
