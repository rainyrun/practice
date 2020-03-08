//
//  bst_test.h
//  BDS
//
//  Created by 润蕾 on 2018/8/27.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef bst_test_h
#define bst_test_h
#include "bst.h"

void test_bst(){
    BST<int> t_bst;
    t_bst.insert(3);
    t_bst.insert(4);
    t_bst.insert(1);
    t_bst.insert(2);
    t_bst.insert(5);
    t_bst.insert(6);
    t_bst.insert(0);
    t_bst.remove(5);
    t_bst.remove(0);
//    t_bst.rotateAt(t_bst.search(2));
//    t_bst.rotateAt(t_bst.search(6));
}

#endif /* bst_test_h */
