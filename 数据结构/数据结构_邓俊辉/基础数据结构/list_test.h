//
//  list_test.h
//  BDS
//
//  Created by 润蕾 on 2018/8/3.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include "list.h"

#ifndef list_test_h
#define list_test_h

class TestList{
public:
    void test_sort();
    void test_basic();
    void visit(int*);
};

void TestList::test_sort(){
    //测试无序列表：find(), disordered(), deduplicate();
    //测试排序: merge(), mergeSort(), selecMax(), selectionSort(), insertSort()；
    //测试有序列表：search(),uniqufiy();
//无序列表测试
    List<int> b;
    b.insertAsLast(5);
    b.insertAsLast(8);
    b.insertAsLast(3);
    b.insertAsLast(0);
    b.insertAsLast(9);
    b.insertAsLast(7);
    b.insertAsLast(2);
    b.insertAsFirst(2);
    b.insertAsFirst(7);
    b.insertAsFirst(3);
    
    if( b.disordered() )
        printf("disordered.\n");
    
    if(9 == b.find(9)->data)
        printf("successful find.\n");
    if( !b.find(11))
        printf("successful find.\n");
    
    b.deduplicate();
    
    b.sort();
    
    if( !b.disordered() )
        printf("ordered.\n");
    
    if(8 == b.search(8)->data)
        printf("successful search.\n");
    
    if(1 != b.search(1)->data)
        printf("successful search.\n");
    
    b.insertB(b.search(7), 7);
    b.insertB(b.search(7), 7);
    b.insertB(b.search(9), 9);
    b.insertB(b.search(5), 5);
    
    b.uniquify();
    
}

void TestList::test_basic(){
    //测试: init(), clear(), remove(), valid(), copyNodes()， [](), reverse(), traverse();
    List<int> a;
    //测试： insertAsLast(), insertAsFirst() insertA(), insertB();
    a.insertAsLast(12);
    a.insertAsLast(1);
    a.insertAsFirst(3);
    a.insertA(a.find(1), 5);
    a.insertB(a.find(3), 7);
    
    List<int> b(a);
    b.remove(b.find(8));
    b.remove(b.find(3));

    if(a[3] == 1)
        printf("[] is correct.\n");
    
    b.valid(b.find(5));
    
    b.reverse();
//    a.clear();
    
//    b.traverse(visit);
}

void TestList::visit(int* p){
    printf("%d \n", *p);
}


#endif /* list_test_h */
