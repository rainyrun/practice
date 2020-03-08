//
//  bintree.h
//  BDS
//
//  Created by 润蕾 on 2018/8/13.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef bintree_h
#define bintree_h
#include "binnode.h"

//macro
#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->lc ) )
#define IsRChild(x) ( ! IsRoot(x) && ( & (x) == (x).parent->rc ) )
#define HasParent(x) ( ! IsRoot(x) )
#define HasLChild(x) ( (x).lc )
#define HasRChild(x) ( (x).rc )
#define HasChild(x) ( HasLChild(x) || HasRChild(x) ) //至少拥有一个孩子
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) ) //同时拥有两个孩子
#define IsLeaf(x) ( ! HasChild(x) )
#define FromParentTo(x) /*来自父亲的引用*/ \
( IsRoot(x) ? _root : ( IsLChild(x) ? (x).parent->lc : (x).parent->rc ) )

/*
 1.底层考虑的越全面，用的时候出错的机会越少
 */

template <class T>
class BinTree{
protected:
    BinNodePosi(T) _root;//根节点
    int _size;//树的规模，含有的节点数
    int updateHeight(BinNodePosi(T) p);//更新节点p的高度
    void updateHeightAbove(BinNodePosi(T) p);//更新包括p在内，以节点p为后代的树的高度

public:
    //构造函数
    BinTree(): _size(0), _root(NULL) { }
    ~BinTree(){ if(_size > 0) remove(_root); }
    int size(){ return _size; };//返回树的规模
    int empty(){ return !_root; };//判断是否是空树
    BinNodePosi(T) root() { return _root; };//返回树根的位置
    BinNodePosi(T) insertAsRoot(const T& e);//将元素e作为树根插入
    BinNodePosi(T) insertAsLC(const T& e, BinNodePosi(T) x);//e作为x的左孩子（原无）插入
    BinNodePosi(T) insertAsRC(const T& e, BinNodePosi(T) x);//e作为x的右孩子（原无）插入
    BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>* t);//树t作为x左子树（原无）接入
    BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>* t);//t作为x右子树（原无）接入
    void remove(BinNodePosi(T) x);//删除以位置x处节点为根的子树
    BinTree<T>* secede(BinNodePosi(T) x);//将子树x从当前树中摘除，并将其转换为一颗独立子树
    void travLevel(void (*visit)(T&));
    void travPre(void (*visit)(T&));
    void travIn(void (*visit)(T&));
    void travPost(void (*visit)(T&));
    //重载运算符
    //旋转
};

template <class T>
int BinTree<T>::updateHeight(BinNodePosi(T) p){
    if(stature(p->lc) >= stature(p->rc))
        p->height = stature(p->lc) + 1;
    else
        p->height = stature(p->rc) + 1;
    return p->height;
}

template <class T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) p){
    while(p){
        int oldh = p->height;
        if(oldh == updateHeight(p))//若更新高度后，和当前高度相等，则不用再向上回溯
            break;
        p = p->parent;
    }
}

template <class T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T& e){//树不为空时，如何处理？
    _size = 1;
    BinNodePosi(T) p = new BinNode<T>(e);
    _root = p;
    return _root;
}

template <class T>
BinNodePosi(T) BinTree<T>::insertAsLC(const T& e, BinNodePosi(T) x){
    if(!x->lc){//左孩子为空
        _size++;
        x->insertAsLC(e);
        updateHeightAbove(x);
        return x->lc;
    }
    return NULL;
}

template <class T>
BinNodePosi(T) BinTree<T>::insertAsRC(const T& e, BinNodePosi(T) x){
    if(!x->rc){//右孩子为空
        x->insertAsRC(e);
        updateHeightAbove(x);
        return x->rc;
    }
    return NULL;
}

template <class T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* t){
    if(!x->lc){//左子树为空
        x->lc = t->_root;
        x->lc->parent = x;
    }
    _size += t->_size;
    updateHeightAbove(x);
    t->_root = NULL;
    t->_size = 0;
//    release(t);
    return x;//返回接入位置
}
/*备注：
 1.错误代码：缺少t->parent = x;导致找不到t的双亲，后续遍历时出错*/

template <class T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* t){
    if(!x->rc){//左子树为空
        x->rc = t->_root;
        x->rc->parent = x;
    }
    _size += t->_size;
    updateHeightAbove(x);
    t->_root = NULL;
    t->_size = 0;
//    release(t);
    return x;//返回接入位置
}

template <class T>
void BinTree<T>::travLevel(void (*visit)(T&)){
    _root->travLevel(visit);
}

template <class T>
void BinTree<T>::travPre(void (*visit)(T&)){
    _root->travPre(visit);
}

template <class T>
void BinTree<T>::travIn(void (*visit)(T&)){
    _root->travIn(visit);
    _root->travIn_I2(visit);
    _root->travIn_I3(visit);
}

template <class T>
void BinTree<T>::travPost(void (*visit)(T&)){
    _root->travPost(visit);
}

template <class T>
void BinTree<T>::remove(BinNodePosi(T) x){
    //切断来自父节点的指针
    if(x->parent->lc == x)
        x->parent->lc = NULL;
    if(x->parent->rc == x)
        x->parent->rc = NULL;
    
    if(x->lc)//x有左孩子
        remove(x->lc);//删除左孩子
    else if(x->rc)//x有右孩子
        remove(x->rc);//删除右孩子
    else{
        x->height = -1;
        updateHeightAbove(x->parent);
        delete x;
        _size--;
    }
}
/*备注
 1.上述代码，在更新高度时，效率很低。借鉴示例代码，可以专门拆出一个删除节点的函数。
 */

template <class T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x){
    BinTree<T>* t = new BinTree<T>;
    t->_root = x;
    x->parent = NULL;
    t->_size = x->size();
    _size -= t->_size;
    
    if(x->parent->lc == x)
        x->parent->lc = NULL;
    if(x->parent->rc == x)
        x->parent->rc = NULL;
    updateHeightAbove(x->parent);
    return t;
}

#endif /* bintree_h */
