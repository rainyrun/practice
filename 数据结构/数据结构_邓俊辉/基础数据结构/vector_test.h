//
//  vector_test.h
//  Created on 2018/8/3.
#include "vector.h"

#ifndef vector_test_h
#define vector_test_h

class TestVector{
public:
    void test_copyFrom();
    void test_insert_remove();
    void test_order();
    void test_other();
    void test_search();
};

void TestVector::test_copyFrom(){
    int test[5] = {1, 2, 3, 5, 4};
    Vector<int> a;
    Vector<int> b(test, 5);
    Vector<int> c(test, 2, 4);
    Vector<int> d(b);
    Vector<int> e(b, 1, 7);
}

void TestVector::test_search(){
    int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Vector<int> a(test, 12);
    if((a.interpolatinSearch(3)) == 2)
        printf("interpolationSearch successful.\n");
}

void TestVector::test_insert_remove(){
    Vector<int> a;
    a.insert(0, 5);
    a.insert(0, 3);
    a.insert(0, 4);
    a.insert(0, 2);
    a.remove(0);
    a.remove(0, 3);
    a.insert(3);
}

void TestVector::test_order(){
    int test[10] = {6, 1, 3, 5, 4, 2, 7, 0, 9, 8};
    Vector<int> a(test, 10);
    //int disorder = a.disordered();
    a.sort();
}

void TestVector::test_other(){
    int test[10] = {6, 2, 3, 7, 7, 9, 7, 9, 9, 8};
    Vector<int> a(test, 10);
    //    int rank1 = a.find(5);
    //    int rank2 = a.search(7);
    //    a.deduplicate(0, 10);
    Vector<int> b(test, 10);
    //    b.sort();
    //    b.uniquify(0, 10);
    //    int temp = b[3];
    b.swap(test[0], test[7]);
}
#endif /* vector_test_h */
