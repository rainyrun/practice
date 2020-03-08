//
//  bintree_test.h
//  BDS
//
//  Created by 润蕾 on 2018/8/14.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef bintree_test_h
#define bintree_test_h

#include "bintree.h"

void visit(int& e){
    printf("%d, ", e);
}

void test_basic(){
    //测试：构造, insert, attach, succ(), trav(), remove, secede
    BinTree<int> t;
    BinNodePosi(int) p = t.insertAsRoot(5);
    p = t.insertAsLC(3, p);
    p = t.insertAsRC(7, p);
    p = t.insertAsRC(4, p);
    
//    BinNode<int> q(6);//节点类内，没有处理插入节点时，高度更新的问题。所以测试高度更新时，需要使用树
    BinTree<int> m;
    BinNodePosi(int) q = m.insertAsRoot(6);
    m.insertAsLC(9, q);
    BinNode<int>* r = m.insertAsRC(2, q);
    m.insertAsLC(1, r);
    
    t.attachAsRC(t.root(), &m);
    
    if(p->succ()->data == 5)
        printf("section1: succ() pass.\n");
    if(q->succ()->data == 1)
        printf("section2: succ() pass.\n");
    
    t.travLevel(visit);
    t.travPre(visit);
    t.travIn(visit);
    t.travPost(visit);
    
    t.remove(r);
//    BinTree<int>* n = t.secede(&q);
}

void test_bintree(){
    test_basic();
}

//节点高度更新不对，接入右子树不对

#endif /* bintree_test_h */
