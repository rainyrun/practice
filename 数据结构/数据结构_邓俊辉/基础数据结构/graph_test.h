//
//  graph_test.h
//  BDS
//
//  Created by 润蕾 on 2018/8/20.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef graph_test_h
#define graph_test_h
#include "graph.h"
void t_graph_basic(){
    GraphMatrix<char, int> g;
    /*基本操作测试
     顶点操作
     insert(), firstNbr(), nextNbr(), remove()
     边操作
     insert(), remove()
     */
    //无向图(prim, dijkstra)
    g.insert('A');
    g.insert('B');
    g.insert('C');
    g.insert('D');
    g.insert('E');
    g.insert('F');
    g.insert('G');
    g.insert('H');
    g.insert(0, 1, 4);
    g.insert(0, 3, 6);
    g.insert(0, 6, 7);
    g.insert(1, 0, 4);
    g.insert(1, 2, 12);
    g.insert(2, 1, 12);
    g.insert(2, 3, 9);
    g.insert(2, 4, 1);
    g.insert(2, 5, 2);
    g.insert(2, 7, 10);
    g.insert(3, 0, 6);
    g.insert(3, 2, 9);
    g.insert(3, 4, 13);
    g.insert(3, 6, 2);
    g.insert(4, 2, 1);
    g.insert(4, 3, 13);
    g.insert(4, 5, 5);
    g.insert(4, 6, 11);
    g.insert(4, 7, 8);
    g.insert(5, 2, 2);
    g.insert(5, 4, 5);
    g.insert(5, 7, 7);
    g.insert(6, 0, 7);
    g.insert(6, 3, 2);
    g.insert(6, 4, 11);
    g.insert(6, 7, 14);
    g.insert(7, 2, 10);
    g.insert(7, 4, 8);
    g.insert(7, 5, 7);
    g.insert(7, 6, 14);
    
    //有向图（深度优先搜索）
    GraphMatrix<char, int> f;
    f.insert('A');
    f.insert('B');
    f.insert('C');
    f.insert('D');
    f.insert('E');
    f.insert('F');
    f.insert('G');
    f.insert(0, 1, 0);
    f.insert(0, 2, 0);
    f.insert(0, 5, 0);
    f.insert(1, 2, 0);
    f.insert(3, 0, 0);
    f.insert(3, 4, 0);
    f.insert(4, 5, 0);
    f.insert(5, 6, 0);
    f.insert(6, 0, 0);
    f.insert(6, 2, 0);
    
    //有向图（拓扑排序）
    GraphMatrix<char, int> a;
    a.insert('A');
    a.insert('B');
    a.insert('C');
    a.insert('D');
    a.insert('E');
    a.insert('F');
    a.insert(0, 2, 0);
    a.insert(0, 3, 0);
    a.insert(1, 2, 0);
    a.insert(2, 3, 0);
    a.insert(2, 4, 0);
    a.insert(2, 5, 0);
    a.insert(4, 5, 0);
    
    //无向图（关节点和连通域分量）BCC
    GraphMatrix<char, int> b;
    b.insert('J');
    b.insert('I');
    b.insert('H');
    b.insert('G');
    b.insert('F');
    b.insert('E');
    b.insert('D');
    b.insert('C');
    b.insert('B');
    b.insert('A');
    b.insert(9, 8, 0);
    b.insert(9, 2, 0);
    b.insert(9, 1, 0);
    b.insert(9, 0, 0);
    b.insert(8, 9, 0);
    b.insert(8, 7, 0);
    b.insert(7, 8, 0);
    b.insert(7, 6, 0);
    b.insert(7, 2, 0);
    b.insert(6, 7, 0);
    b.insert(6, 5, 0);
    b.insert(6, 3, 0);
    b.insert(5, 6, 0);
    b.insert(5, 3, 0);
    b.insert(4, 3, 0);
    b.insert(3, 4, 0);
    b.insert(3, 6, 0);
    b.insert(3, 5, 0);
    b.insert(2, 9, 0);
    b.insert(2, 7, 0);
    b.insert(1, 9, 0);
    b.insert(1, 0, 0);
    b.insert(0, 9, 0);
    b.insert(0, 1, 0);
    
    
    
//    if(6 == g.firstNbr(0))
//        printf("0 firstNbr pass.\n");
//    if(7 == g.firstNbr(6))
//        printf("6 firstNbr pass.\n");
//    if(5 == g.firstNbr(3))
//        printf("3 firstNbr pass.\n");
//    if(3 == g.nextNbr(0, 6))
//        printf("0, 6 nextNbr pass.\n");
//    if(5 == g.nextNbr(4, 6))
//        printf("4, 6 nextNbr pass.\n");
//    if(5 == g.nextNbr(3, 6))
//        printf("3, 6 nextNbr pass.\n");
//    if(-1 == g.nextNbr(7, 2))
//        printf("7, 2 nextNbr pass.\n");
    
//    g.bfs();
//    f.bfs();
//    g.dfs();
//    f.dfs();
    a.tSort();
//    b.bcc();
//    g.pfs(BfsPU<char, int>());
//    f.pfs(BfsPU<char, int>());
    g.prim();
    g.dijkstra();
    
}


void test_graph(){
    t_graph_basic();
}

#endif /* graph_test_h */
