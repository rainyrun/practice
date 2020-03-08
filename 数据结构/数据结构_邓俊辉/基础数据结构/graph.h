//
//  graph.h
//  BDS
//
//  Created by 润蕾 on 2018/8/20.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef graph_h
#define graph_h
#include "vector.h"
#include "queue@list.h"
#include "stack@vector.h"

#define hca(i) (fTime(i))

typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;//顶点状态
typedef enum {UNDETERMINED, TREE, CROSSED, BACKWARD, FORWARD} EType;//边在遍历树中所属的类型


template <class Tv, class Te>//顶点类型，边类型可以通过模板传递
class Graph{//图Graph模板类
/*备注：将图的更通用结构抽象出来，成为抽象类，保证派生类具有要求的行为。
 同时图抽象类的各类实现方法均为纯虚函数，需要依托具体的组织形式来实现
 和图的邻接矩阵结构拆分开，使结构更清晰。
 */
private:
    void reset();//顶点、边的辅助信息复位
    void BFS(int v);//（连通域）广度优先搜索算法
    void DFS(int v);//（连通域）深度优先搜索算法
    //void BCC ( int, int&, Stack<int>& );
    void BCC(int v);//（连通域）基于DFS的双连通分量分解算法
    void TSort();//（连通域）基于DFS的拓扑排序算法
    bool TSort2(int v, Stack<Tv>* S);//无需修改顶点出入度版本
    template <class PU>
    void PFS(int v, PU prioUpdater); //（连通域）优先级搜索框架
public:
//顶点
    int n; //顶点总数
    virtual int insert(const Tv&) = 0;//插入顶点，返回编号
    virtual Tv remove(int) = 0;//删除顶点及其关联边，返回该顶点信息
    virtual Tv& vertex(int) = 0;//顶点v的数据（该顶点的确存在）
    virtual int& inDegree(int) = 0;//顶点v的入度（该顶点的确存在）
    virtual int& outDegree(int) = 0;//顶点v的出度（该顶点的确存在）
    virtual int firstNbr(int) = 0;//顶点v的首个邻接顶点
    virtual int nextNbr(int, int) = 0;//顶点v的（相对于顶点j的）下一邻接顶点
    virtual VStatus& status(int) = 0;//顶点v的状态
    virtual int& dTime(int) = 0;//顶点v的时间标签discoverTime
    virtual int& fTime(int) = 0;//顶点v的时间标签finalTime
    virtual int& parent(int) = 0;//顶点v在遍历树中的父亲
    virtual int& priority(int) = 0;//顶点v在遍历树中的优先级数
//边(本模板适用于有向图，无向图视为有两条方向相反边的有向图)
    int e;//边总数
    virtual bool exists(int i, int j) = 0;//边(v, u)是否存在
    virtual void insert(int i, int j, int w) = 0;//在顶点v和u之间插入权重为w的边e
    virtual Te remove(int i, int j) = 0;//删除顶点v和u之间的边e，返回该边信息
    virtual EType& type(int i, int j) = 0;//边(v, u)的类型
    virtual Te& edge(int i, int j) = 0;//边(v, u)的数据（该边的确存在）
    virtual int& weight(int i, int j) = 0;//边(v, u)的权重
//算法
    void bfs();//广度优先搜索算法
    void dfs();//深度优先搜索算法
    void bcc();//基于DFS的双连通分量分解算法
    void tSort();//基于DFS的拓扑排序算法
    void prim();//最小支撑树Prim算法
    void dijkstra();//最短路径Dijkstra算法
    template <class PU>
    void pfs(PU prioUpdater);//优先级搜索框架
};
/*备注
 1.抽象结构与具体结构的关系？答：抽象结构从具体结构中来，是具体结构的概括和总结。因此在实际编写过程中，因先编写具体结构，有需要的情况下，再对具体结构做总结和概括，形成抽象结构。
 2.示例代码里的算法，参数都带了int，如void bfs ( int )。好处是，可以从任何一个节点开始搜索
 */

//顶点对象
template <class Tv>
struct Vertex{
    Tv data;//顶点数据
    int inDegree;//顶点入度数
    int outDegree;//顶点出度数
    VStatus status;//顶点状态
    int dTime;//dicoveredTime
    int fTime;//finishedTime
    int parent;//遍历树中的父亲
    int priority;//遍历树中的优先级
    Vertex(const Tv& d = (Tv) 0, int ind = 0, int outd = 0, VStatus s = UNDISCOVERED, int dt = -1, int ft = -1, int p = -1, int pri = INT_MAX) : data(d), inDegree(ind), outDegree(outd), status(s), dTime(dt), fTime(ft), parent(p), priority(pri){//构造函数
    }
};
/*备注
 1.data的初始化参数？答：使用(Tv)强制转换0的类型，初始化data
 2.除data外，其余成员都不需要传递参数，直接初始化即可。
 */

//边对象
template <class Te>
struct Edge{
    Te data;//边数据
    int weight;//权重
    EType type;//在遍历树中的类型
    Edge(const Te& d = (Te) 0, int w = 0): data(d), weight(w), type(UNDETERMINED){}//构造函数
};
/*备注
 1.参数为const Te& d,构造时出现问题：No matching constructor for initialization of 'Edge<int>'
 */


//邻接矩阵实现的图
template <class Tv, class Te>//顶点类型，边类型
class GraphMatrix : public Graph<Tv, Te>{
    //基于向量，以邻接矩阵形式实现的图
private:
    Vector<Vertex<Tv>> V;//顶点集（向量）
    Vector<Vector<Edge<Te>*>> E;//边集（邻接矩阵）
public:
    int& n = Graph<Tv, Te>::n;//解决派生类不能直接访问基类成员的问题
    int& e = Graph<Tv, Te>::e;
    GraphMatrix(){ n = e = 0; }//构造函数
    ~GraphMatrix(){//析构函数
        for (int i = 0; i < n; i++) {//释放边
            for (int j = 0; j < n; j++) {
//                if(E[i][j])
                    delete E[i][j];
            }
        }//for
    }//~GraphMatrix
/*备注
 1.释放E[5][1]时，发生错误：Thread 1: signal SIGABRT
 调试发现E[5][1]->weight = 10;莫名其妙有了数值，其他的边插入操作都正常。顶点插入insert(Tv data)算法，改用示例代码发现运行正确。
 解决方法：顶点插入时，向量的初始化做的不好，没有制定大小和容量。导致出现了未知错误。
 */
    
    //顶点的基本操作：查询第i个顶点（0 <= i < n）
    virtual Tv& vertex(int i){ return V[i].data; }//顶点数据
    virtual int& inDegree(int i){ return V[i].inDegree; }//入度
    virtual int& outDegree(int i){ return V[i].outDegree; }//出度
    virtual int firstNbr(int i);//顶点i首个邻接顶点，逆序扫描
    virtual int nextNbr(int i, int j);//顶点i相对于顶点j的下一邻接顶点
    virtual VStatus& status(int i){ return V[i].status; }//状态
    virtual int& dTime(int i){ return V[i].dTime; }//时间标签dTime
    virtual int& fTime(int i){ return V[i].fTime; }//时间标签fTime
    virtual int& parent(int i){ return V[i].parent; }//在遍历树中的父亲
    virtual int& priority(int i){ return V[i].priority; }//在遍历树中的优先级数
    
    //顶点的动态操作
    virtual int insert(const Tv& data);//插入顶点，返回编号
    virtual Tv remove(int i);//删除第i个顶点及其关联边（0 <= i < n），返回该顶点的信息
    
    //边的操作
    virtual bool exists(int i, int j){ return (0 <= i) && (i < n) && (0 <= j) && (j < n) && (E[i][j] != NULL);}//边(i, j)是否存在
    virtual EType& type(int i, int j){ return E[i][j]->type; }//边(i, j)的类型
    virtual Te& edge(int i, int j){ return E[i][j]->data; }//边(i, j)的数据
    virtual int& weight(int i, int j){ return E[i][j]->weight; }//边(i, j)的权重
    virtual void insert(int i, int j, int w);//插入权重为w的边e = (i, j)
    virtual Te remove(int i, int j);//删除顶点i和j之间的联边（exists(i, j)）
    
    
};


//Graph相关的方法
template <class Tv, class Te>
void Graph<Tv, Te>::reset(){//顶点、边辅助信息复位
    for (int i = 0; i < n; i++) {//顶点辅助信息复位
        inDegree(i) = 0;
        outDegree(i) = 0;
        status(i) = UNDISCOVERED;
        dTime(i) = -1;
        fTime(i) = -1;
        parent(i) = -1;
        priority(i) = INT_MAX;
    }//for
    
    for(int i = 0; i < n; i++){//计算节点出入度，边辅助信息复位
        for (int j = 0; j < n; j++) {
            if(exists(i, j)){
                type(i, j) = UNDETERMINED;
                outDegree(i)++;//若拓扑排序使用了方法2（不改变节点出入度信息），则不需要重置出入度
                inDegree(j)++;
            }
        }
    }//for
}//reset

template <class Tv, class Te>
void Graph<Tv, Te>::BFS(int v){//连通域，广度优先遍历
    Queue<int> Q;//辅助队列
    int t = 1;//时间，用来标注dTime（fTime未使用）
    int p = v;//指向待访问的节点
//    parent(p) = -1;//是否可以去掉？
    dTime(p) = t++;
    status(p) = DISCOVERED;
    Q.enqueue(p);//首个节点入队
    while(!Q.empty()){//队列不为空
        p = Q.dequeue();
        status(p) = VISITED;
        fTime(p) = t++;
        printf("%d is visited.\n", p);
        for (int i = firstNbr(p); -1 < i; i = nextNbr(p, i)) {//查找所有相邻节点
            switch (status(i)) {
                case UNDISCOVERED:
                    status(i) = DISCOVERED;
                    type(p, i) = TREE;//边类型标记为树边
                    dTime(i) = t++;//记录发现时间
                    parent(i) = p;//记录父亲
                    Q.enqueue(i);
//                    printf("%d's parent is %d, dTime is %d.\n", i, p, dTime(i));
//                    printf("(%d, %d) is a TREE edge.\n", p, i);
                    break;
                default:
                    type(p, i) = CROSSED;//边类型标记为跨边
//                    printf("(%d, %d) is a CROSSED edge.\n", p, i);
                    break;
            }
        }//for
    }//while
}//BFS

template <class Tv, class Te>
void Graph<Tv, Te>::DFS(int v){//连通域，深度优先遍历，递归版本
    static int t = 1;
    status(v) = DISCOVERED;
    dTime(v) = t++;
//    printf("%d is discovered at time %d.\n", v, dTime(v));
    for (int i = firstNbr(v); -1 < i; i = nextNbr(v, i)) {
        switch (status(i)) {
            case UNDISCOVERED:
                parent(i) = v;
                type(v, i) = TREE;
//                printf("%d's parent is %d.\n", i, v);
//                printf("(%d, %d) is a TREE edge.\n", v, i);
                DFS(i);//深入遍历
                break;
            case DISCOVERED:
                type(v, i) = BACKWARD;
//                printf("(%d, %d) is a BACKWARD edge.\n", v, i);
                break;
            case VISITED:
                type(v, i) = (dTime(v) < dTime(i)) ? FORWARD : CROSSED;
                break;
            default:
                printf("DFS: unexpected situation.\n");
                break;
        }
    }//for
    status(v) = VISITED;
    fTime(v) = t++;
//    printf("%d is visited at time %d.\n", v, fTime(v));
}//DFS
/*备注
 1.时间t可以定义在dfs()里，作为参数传递给DFS()
 2.错误代码：
 case DISCOVERED:
 if(dTime(i) > dTime(v)){
 type(v, i) = FORWARD;
 printf("(%d, %d) is a FORWARD edge.\n", v, i);
 }
 else{
 type(v, i) = BACKWARD;
 printf("(%d, %d) is a BACKWARD edge.\n", v, i);
 }
 break;
 深度优先遍历，DISCOVERED状态的顶点必然是祖先顶点。VISITED才可能是后代
 */

template <class Tv, class Te>
void Graph<Tv, Te>::BCC(int v){//基于DFS的双连通分量分解算法。双连通域(bi-connected component)
    static int t = 1;//时间
    static Stack<int> S;//存放双连通分量
    S.push(v);
    status(v) = DISCOVERED;
    dTime(v) = t++;
    hca(v) = dTime(v);//hca初始化
//    printf("%d is discovered at time %d, hca is %d.\n", v, dTime(v), hca(v));
    for (int i = firstNbr(v); -1 < i; i = nextNbr(v, i)) {
        switch (status(i)) {
            case UNDISCOVERED:
                parent(i) = v;
                type(v, i) = TREE;
                BCC(i);
//                示例代码，更严谨的更新父节点的hca
//                if ( hca ( u ) < dTime ( v ) ) //遍历返回后，若发现u（通过后向边）可指向v的真祖先
//                    hca ( v ) = min ( hca ( v ), hca ( u ) ); //则v亦必如此
                break;
            default://status(i) = DISCOVERED || VISITED
                if((i != parent(v)) && (hca(i) < hca(v)))//！相邻节点不是父节点
                    hca(v) = hca(i);//更新父亲的hca
                break;
        }
    }//for
    status(v) = VISITED;
    if(hca(v) < hca(parent(v)))//更新父亲的hca（hca在fTime内存储）
        hca(parent(v)) = hca(v);
//    printf("%d's hca is %d.\n", v, hca(v));
    if(hca(v) == dTime(v)){
        printf("%d is a important point.\n", v);//输出关节点
        printf("bi-connected component is: \n");
        while(true){//输出连通分量
            int temp = S.pop();
            printf("%d, ", temp);
            if(temp == v)
                break;
        }
        printf("\n");
        S.push(v);//v作为连接点重新入栈
    }
}
/*备注
 1.错误代码：
 while(!S.empty()){//输出连通分量
 printf("%d, ", S.pop());
 }
 连通分量的划分条件是，碰到关节点
 2.代码
 default://status(i) = DISCOVERED || VISITED
 if((i != parent(v)) && (hca(i) < hca(v)))//！相邻节点不是父节点
 中，(hca(i) < hca(v)) 改为 (dTime(i) < hca(v))更清晰
 */

template <class Tv, class Te>
void Graph<Tv, Te>::TSort(){
    Stack<int> S;//存放入度为零的节点
    int p = 0;
    for (int i = 0; i < n; i++) {//入度为零的节点入栈
        if(inDegree(i) == 0){
            S.push(i);
            inDegree(i) = -1;//已入栈标志（！修改了入度信息）
        }
    }
    while(!S.empty()){
        p = S.pop();
        printf("%c, ", vertex(p));//排序节点
        for (int i = 0; i < n; i++) {//以p为尾的节点，入度都减1
            if(exists(p, i)){
//                printf("%c's indegree is %d\n", vertex(i), inDegree(i));
                inDegree(i)--;
//                printf("%c's indegree is %d\n", vertex(i), inDegree(i));
            }
        }
        for (int i = 0; i < n; i++) {//入度为零的节点入栈
            if(inDegree(i) == 0){
                S.push(i);
                inDegree(i) = -1;//已入栈标志
            }
        }
    }//while
    printf("\n");
}
/*备注
 1.图有可能出现环路，该方法没有考虑有环的情况。补充：遍历发现纯在入度不为0的节点，说明有环
 */

template <class Tv, class Te>
bool Graph<Tv, Te>::TSort2(int v, Stack<Tv>* S){
    static int t = 1;
    status(v) = DISCOVERED;
    dTime(v) = t++;//非必需
//    printf("%d is discovered at time %d.\n", v, dTime(v));
    for (int i = firstNbr(v); -1 < i; i = nextNbr(v, i)) {
        switch (status(i)) {
            case UNDISCOVERED:
                parent(i) = v;
                type(v, i) = TREE;
                if(!TSort2(i, S))//深入搜索
                    return false;//发现回边则返回
                break;
            case DISCOVERED://深入优先遍历，发现discovered意味着有回路，无需比较dTime
//                if(dTime(i) > dTime(v)){
//                    type(v, i) = FORWARD;
//                    printf("(%d, %d) is a FORWARD edge.\n", v, i);
//                }
//                else{
                    type(v, i) = BACKWARD;
//                    printf("(%d, %d) is a BACKWARD edge.\n", v, i);
                    return false;
//                }
                break;
            case VISITED:
                type(v, i) = ( dTime ( v ) < dTime ( i ) ) ? FORWARD : CROSSED;
                break;
            default:
                printf("DFS: unexpected situation.\n");
                break;
        }
    }//for
    status(v) = VISITED;
    fTime(v) = t++;//非必需
    S->push(vertex(v));
    return true;
}
/*备注
 1.vertex(v)能够增加可读性*/


template <class Tv, class Te> template <class PU>
void Graph<Tv, Te>::PFS(int v, PU prioUpdater){
    priority(v) = 0;//优先级设为最高
    status(v) = VISITED;
    parent(v) = -1;
    printf("PFS: ");
    printf("%d, ", v);
    while(true){
        for (int i = firstNbr(v); -1 < i; i = nextNbr(v, i)) {
            prioUpdater(this, v, i);//更新相邻节点的优先级
        }
        int prio = INT_MAX;
        for (int i = 0; i < n; i++) {
//        for (int i = n - 1; -1 < i; i--) {
            if(status(i) == UNDISCOVERED)
                if(priority(i) < prio){
                    prio = priority(i);
//                    printf("%d's priority is: %d\n", i, priority(i));
                    parent(i) = v;
                    v = i;//选择未访问节点中，优先级最高的节点，作为选中的节点
                }
        }
        if(status(v) == VISITED)//所有节点都已访问，即遍历结束
            break;
        status(v) = VISITED;
        type(parent(v), v) = TREE;
        printf("%d, ", v);
    }
    printf("\n");
}

template <class Tv, class Te>
void Graph<Tv, Te>::bfs(){//广度优先搜索算法
    reset();
    for (int i = n - 1; -1 < i; i--) {
        if(status(i) == UNDISCOVERED)
            BFS(i);
    }
}

template <class Tv, class Te>
void Graph<Tv, Te>::dfs(){//深度优先搜索算法
    reset();
    for (int i = n - 1; -1 < i; i--) {
        if(status(i) == UNDISCOVERED)
            DFS(i);
    }
}

template <class Tv, class Te>
void Graph<Tv, Te>::bcc(){//基于DFS的双连通分量分解算法
    reset();
    for (int i = n - 1; -1 < i; i--) {
        if(status(i) == UNDISCOVERED)
            BCC(i);
    }
}

template <class Tv, class Te>
void Graph<Tv, Te>::tSort(){//基于DFS的拓扑排序算法
    reset();
    TSort();
    Stack<Tv>* S = new Stack<Tv>;
    for (int i = n - 1; -1 < i; i--) {
        if (UNDISCOVERED == status(i))
            if(!TSort2(i, S)){//若不是单连通域，则打印元素并停止计算
                while (!S->empty()) {//打印栈内元素
                    printf("%c, ", S->pop());
                }
                break;
            }
    }
    while (!S->empty()) {//打印拓扑排序顺序
        printf("%c, ", S->pop());
    }
}
/*备注
 1.栈内元素类型不固定时，如何打印栈内元素？
 */

//优先级更新器
template <class Tv, class Te>
struct BfsPU{//针对BFS算法的顶点优先级更新器
    virtual void operator () (Graph<Tv, Te>* g, int u, int v){//重载括号运算符，相当于定义了函数
        //v是u的相邻节点
        if(g->status(v) == UNDISCOVERED){//如果v没有被发现
            if(g->priority(v) > g->priority(u) + 1){
                g->priority(v) = g->priority(u) + 1;//v的优先级更新为v到起始顶点的距离（即每层顶点的优先级+1）
                g->parent(v) = u;
            }
        }
    }
};

template <typename Tv, typename Te> struct DfsPU { //（示例代码）针对DFS算法的顶点优先级更新器
    virtual void operator() ( Graph<Tv, Te>* g, int uk, int v ) {
        if ( g->status ( v ) == UNDISCOVERED ) //对于uk每一尚未被发现的邻接顶点v
            if ( g->priority ( v ) > g->priority ( uk ) - 1 ) { //将其到起点距离的负数作为优先级数
                g->priority ( v ) = g->priority ( uk ) - 1; //更新优先级（数）
                g->parent ( v ) = uk; //更新父节点
                return; //注意：与BfsPU()不同，这里只要有一个邻接顶点可更新，即可立即返回
            } //如此效果等同于，后被发现者优先
    }
};


template <class Tv, class Te>
struct primPU{//最小支撑树prim算法的优先级更新器
    virtual void operator () (Graph<Tv, Te>* g, int u, int v){
        //v是u的相邻节点
        if(g->status(v) == UNDISCOVERED)
            if(g->priority(v) > g->weight(u, v)){
//                printf("(%d, %d)'s weight is %d\n", u, v, g->weight(u, v));
                g->priority(v) = g->weight(u, v);//v的优先级更新为边（u，v）的权重
//                printf("%d's priority update: %d\n", v, g->priority(v));
                g->parent(v) = u;//更新父节点
            }
    }
};

template <class Tv, class Te>
struct dijkPU{//最短路径Dijkstra算法的优先级更新器
    void operator () (Graph<Tv, Te>* g, int u, int v){
        if(g->status(v) == UNDISCOVERED)
            if(g->priority(v) > (g->priority(u) + g->weight(u, v))){
                g->priority(v) = g->priority(u) + g->weight(u, v);//v的优先级更新为u的优先级+uv的权重
//                printf("%d's priority update: %d\n", v, g->priority(v));
                g->parent(v) = u;
            }
    }
};


template <class Tv, class Te>
void Graph<Tv, Te>::prim(){//最小支撑树Prim算法
    pfs(primPU<Tv, Te>());
}

template <class Tv, class Te>
void Graph<Tv, Te>::dijkstra(){//最短路径Dijkstra算法
    pfs(dijkPU<Tv, Te>());
}

template <class Tv, class Te> template <class PU>
void Graph<Tv, Te>::pfs(PU prioUpdater){//优先级搜索框架
    reset();
    for (int i = 0; i < n; i++) {
//    for (int i = n - 1; -1 < i; i--) {
        if(status(i) == UNDISCOVERED)
            PFS(i, prioUpdater);
    }
}


//GraphMatrix相关的方法
template <class Tv, class Te>
int GraphMatrix<Tv, Te>::firstNbr(int i){
    return nextNbr(i, n);
}

template <class Tv, class Te>
int GraphMatrix<Tv, Te>::nextNbr(int i, int j){
    for (j -= 1; 0 <= j && !exists(i, j); j--);//扫描边集
    return j;
}

template <class Tv, class Te>
int GraphMatrix<Tv, Te>::insert(const Tv& data){//插入顶点，返回顶点编号
    Vertex<Tv> v(data);
    V.insert(n, v);//在顶点集中加入顶点v

    Vector<Edge<Te>*> row(n + 1, n + 1, NULL);//构造向量
    E.insert(n, row);//将向量加入边集
    n++;
    for (int i = 0; i < n; i++) {//边集每行最末尾插入新的边
        E[i].insert(n - 1, NULL);//可以直接采用insert(NULL)接口，将元素插入末尾。
    }
    return n - 1;
//    for ( int j = 0; j < n; j++ )
//        E[j].insert ( NULL );
//    n++; //各顶点预留一条潜在的关联边
//    E.insert ( Vector<Edge<Te>*> ( n, n, ( Edge<Te>* ) NULL ) ); //创建新顶点对应的边向量
//    return V.insert ( Vertex<Tv> ( data ) ); //顶点向量增加一个顶点
}
/*备注
 1.注意”行向量插入边集“和”边集每行末尾增加一个节点“的顺序，如果顺序弄反了，会导致第一个节点插入时，列向量少一列
 2.错误代码：Vector<Edge<Te>*> row;//构造向量时，没有初始化，导致E空间不是严格的正方形，会出现很多隐藏问题。比如赋值和释放时。
 */

template <class Tv, class Te>
Tv GraphMatrix<Tv, Te>::remove(int i){
    Tv temp = V[i].data;
    for (int k = 0; k < n; k++) {//删除顶点i的行向量
        if(E[i][k]){//or exists(i, k)
            delete E[i][k];//释放行向量
            E[i][k] = NULL;
            V[k].inDegree--;
            e--;//边数-1
        }
        if(E[k][i]){
            delete E[k][i];//释放列向量
            E[k][i] = NULL;
            V[k].outDegree--;
            e--;//边数-1
        }
        E[k].remove(i);//删除行向量中的第i列
    }
    E.remove(i);
    n--;//顶点数减1
    return temp;
}

template <class Tv, class Te>
void GraphMatrix<Tv, Te>::insert(int i, int j, int w){
    //新添代码：确保该边不存在
    if(exists(i, j))
        return;
    Edge<Te>* p = new Edge<Te>;
    p->weight = w;
    E[i][j] = p;
    //简介版：E[i][j] = new Edge<Te> ( edge, w );
    e++;
    V[i].outDegree++;
    V[j].inDegree++;
}

template <class Tv, class Te>
Te GraphMatrix<Tv, Te>::remove(int i, int j){//删除边（i，j）并返回边的信息。要求边确实存在
    Te temp = E[i][j]->data;
    delete E[i][j];
    E[i][j] = NULL;
    V[i].outDegree--;
    V[j].inDegree--;
    return temp;
}

#endif /* graph_h */
