//
//  list.h
//  Created on 2018/7/30.

#ifndef list_h
#define list_h

#include "list_listnode.h"

typedef int Rank;

template <class T>
class List{
private:
    int _size;
    ListNodePosi(T) header;
    ListNodePosi(T) trailer;
/*备注
 1.错误代码：ListNodePosi(T) header, trailer;
 使用宏时，尽量不要使用这种形式。宏展开后是：ListNode<T>* header, trailer; 此时的trailer的类型是ListNode<T>.
 */
    
protected:
    void init();//列表创建时的初始化
    void clear();//清除所有节点
    void copyNodes(ListNodePosi(T) p, int n);//复制列表中自位置p起的n项
    //!归并排序，对比示例代码
    void merge(ListNodePosi(T) &p, int m, ListNodePosi(T) q, int n);//将包括p在内的m个结点和将包括q在内的n个结点，按非降序排列在一起，p指向排序后的首结点。
    void mergeSort(ListNodePosi(T) &p, int n);//p是归并的起始位置，n是区间长度。
    void mergeSort(){ mergeSort(header->succ, _size); };//全区间归并排序
    void selectionSort(ListNodePosi(T) p, int n);//选择排序
    void insertionSort(ListNodePosi(T) p, int n);//对从p开始连续的n个节点插入排序
    
public:
//构造函数
    List(){ init(); };//默认构造函数
    List(const List<T>& L){ init(); copyNodes(L.header->succ, L._size); };//复制构造
    /*备注：需要先构造一个空列表，然后再依次复制节点*/
    List(ListNodePosi(T) p, int n){ init(); copyNodes(p, n); };//区间复制构造
    ~List(){
        clear();
        delete header;
        delete trailer;
//        header = NULL;
//        trailer = NULL;
    };//析构函数函数
    /*备注：
     */
//只读访问接口
    int size() const { return _size; };
    bool empty() const { return !_size; };//!对比return _size <= 0;
    T& operator[](Rank r) const;//返回从首节点开始的第r个元素
    ListNodePosi(T) first() const { return header->succ; }//首节点位置
    ListNodePosi(T) last() const { return trailer->pred; }//末节点位置
    bool valid(ListNodePosi(T) p);//检查位置p是不是当前列表的合法位置
    bool disordered() const ;//判断列表是否有序,1表示无序
    ListNodePosi(T) find(const T& e) const { return find(header->succ, _size, e); };//无序列表查找
    ListNodePosi(T) find(ListNodePosi(T) p, int n, const T& e) const;//无序列表区间查找，从p开始的n个节点中查找
    ListNodePosi(T) search(const T& e) const { return search(header->succ, _size, e); };//有序列表查找，查找失败返回不大于e的最大元素的最靠后的位置
    ListNodePosi(T) search(ListNodePosi(T) p, int n, const T& e) const ;//有序列表的区间查找，查找失败返回不大于e的最大元素的最靠后的位置
    ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);//在p及其n-1个后继中选出最大者
    ListNodePosi(T) selecMax(){return selecMax(header->succ, _size);};//全局中选出最大元素
//可写访问接口
    ListNodePosi(T) insertAsFirst(const T& data);//在列表的头部插入元素data
    ListNodePosi(T) insertAsLast(const T& data);//在列表的末尾插入元素data
    ListNodePosi(T) insertA(ListNodePosi(T) p, const T& data);//在p之后插入元素data
    ListNodePosi(T) insertB(ListNodePosi(T) p, const T& data);//将data当作p的前驱插入
    T remove(ListNodePosi(T) p);//p是列表中的节点，删除节点p，返回被删除的元素
    void sort(){ sort(header->succ, _size);};//列表整体排序
    void sort(ListNodePosi(T) p, int n);//列表从p开始的n个元素进行排序
    int deduplicate();//无序向量去重，返回删除的元素个数
    int uniquify();//有序向量去重，返回删除的元素个数
    void reverse();//将列表中的元素颠倒
    void traverse(void (*visit)( T& ));//!注意visit函数指针的参数
    template <typename VST>//操作器
    void traverse(VST& visit);
};//List

template <class T>
void List<T>::init(){
    _size = 0;
    header = new ListNode<T>;
    trailer = new ListNode<T>;
    header->pred = NULL;
    header->succ = trailer;
    trailer->pred = header;
    trailer->succ = NULL;
}
/*备注
 错误：trailer = new ListNode<T>;//No viable overloaded '='*/

template <class T>
void List<T>::clear(){
    ListNodePosi(T) temp;
    ListNodePosi(T) p;
    p = header->succ;
    while (p != trailer) {
        temp = p;
        p = p->succ;
        remove(temp);
    }
    _size = 0;
}
/*精简版本
 int oldSize = _size;
 while ( 0 < _size ) remove ( header->succ ); //反复删除首节点，直至列表变空
 return oldSize;
 */

template <class T>
T List<T>::remove(ListNodePosi(T) p){
    if(p){//p不是空指针
        T temp = p->data;
        p->pred->succ = p->succ;
        p->succ->pred = p->pred;
        delete p;
        _size--;
        return temp;
    }
    exit(-1);//空指针
}

template <class T>
void List<T>::copyNodes(ListNodePosi(T) p, int n){
    clear();
    for(int i = 0; i < n; i++){
        insertAsLast(p->data);
        p = p->succ;
    }
    _size = n;
}

template <class T>
bool List<T>::valid(ListNodePosi(T) p){
    ListNodePosi(T) temp;
    bool val = true;
    for(temp = header->succ; temp != p && temp != trailer; temp = temp->succ);
    if(temp == trailer)
        val = false;
    return val;
}

template <class T>
ListNodePosi(T) List<T>::insertAsLast(const T& data){
    _size++;
    return trailer->insertAsPred(data);
}
/*备注
 1.插入有两种情况：1）插入数据，需新建节点；2）插入已有节点。是否需要重载插入？答：不需要，插入已有节点，直接修改前后继即可
 */

template <class T>
ListNodePosi(T) List<T>::insertAsFirst(const T& data){
    _size++;
    return header->insertAsSucc(data);
}

template <class T>
void List<T>::merge(ListNodePosi(T) &p, int m, ListNodePosi(T) q, int n){
    //assert: rank(p) + m <= _size
    ListNodePosi(T) temp = p->pred;
    ListNodePosi(T) r = p->pred;//！方便待排序首节点的插入，r指向待插入的位置，p指向列表1待比较节点，q指向列表2待比较节点
    while( 0 < m || 0 < n){
        if((0 < m && p->data <= q->data) || n <= 0){
            r->succ = p;
            p->pred = r;
            r = r->succ;
            p = p->succ;
            --m;
        }
        else if((0 < n && q->data < p->data) || m <=0){
            r->succ = q;
            q->pred = r;
            r = r->succ;
            q = q->succ;
            --n;
        }
    }
    r->succ = q;
    q->pred = r;
    p = temp->succ;
}

/*code-0.1
 ListNodePosi(T) r = p->pred;//！方便待排序首节点的插入
 while( 0 < m || 0 < n){
 if((0 < m && p->data <= q->data) || n <= 0){
 r->succ = p;
 p->pred = r;
 r = r->succ;
 p = p->succ;
 --m;
 }
 else if((0 < n && q->data < p->data) || m <=0){
 r->succ = q;
 q->pred = r;
 r = r->succ;
 q = q->succ;
 --n;
 }
 }
 r->succ = q;
 q->pred = r;
 
 */

/*code-0.2
 ListNodePosi(T) r = p;
 List<T> cpl(*this, p, m);
 ListNodePosi(T) cp = cpl.header->succ;
 while( 0 < m || 0 < n){
 if((0 < m && cp->data <= q->data) || n <= 0){
 r->data = cp->data;
 r = r->succ;
 cp = cp->succ;
 --m;
 }
 else if((0 < n && q->data < cp->data) || m <=0){
 r->data = q->data;
 r = r->succ;
 q = q->succ;
 --n;
 }
 }
 
 */

/*备注
 1.错误代码:while循环结束后，没有修改r末尾的指向，造成循环
 2.错误：如序列5830972，第2次merge（序列为5380972），p指向5，q应指向3，但q指向了8。
 原因：p、q是指针，存放的内容是某个节点的位置。第一次merge时，p指向5，q指向8，排序后改变的是节点的相对次序，但pq里的内容没有变，所以q仍指向8，后继是0（相对次序改变）
 3.通用性不强，只适用p、q在同一列表的情况。!借鉴示例代码
 4.code-0.1，增加如下代码，并将merge()和mergeSort()的参数改为&p，即能正确运行
 ListNodePosi(T) temp = p->pred;
 ……
 p = temp->succ;
 原因：p需要始终指向新排序列表的起点
 仍建议借鉴示例代码，示例代码中将列表2插入列表1中的方法非常巧妙，而且思路清晰
 */

template <class T>
void List<T>::mergeSort(ListNodePosi(T) &p, int n){
    if (n <= 1) return;
    ListNodePosi(T) q = p;
    for(int i = 0; i < n/2; i++)
        q = q->succ;
    mergeSort(p, n/2);
    mergeSort(q, n - n/2);
    merge(p, n/2, q, n - n/2);
}

template <class T>
void List<T>::selectionSort(ListNodePosi(T) p, int n){
    ListNodePosi(T) q = p->pred;//指向查找的起始点的前驱
    ListNodePosi(T) r = p;
    for (int i = 0; i < n; i++)//找到待插入的位置，待排序区间为(q, r)
        r = r->succ;
    for(int i = n; 1 < i; i--){//待排序区间至少还剩2个节点
        r = insertB(r, remove(selecMax(q->succ, i)));
    }
}
/*1.错误代码：insertAsLast(remove(selecMax(p, i)));
 错误1)导致逆序输出
 错误2)首节点（即p）被删除释放后，无法从p开始查找剩余的序列*/

template <class T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n){//从起始于位置p的n个元素中选出最大者
    ListNodePosi(T) mp = p;
    for (int i = 0; i < n; i++, p = p->succ) {
        if (mp->data < p->data) {
            mp = p;
        }
    }
    return mp;
}

template <class T>
bool List<T>::disordered() const {
    ListNodePosi(T) p;
    for (p = header->succ; p != trailer->pred && p->data <= p->succ->data; p = p->succ);
    if (p == trailer->pred)
        return false;
    return true;
}
/*
 1.错误代码：for (p = header->succ; p != trailer && p->data <= p->succ->data; p = p->succ);
 p永远不可能==trailer（当p为最后一个元素时，p->data <= p->succ->data恒不成立）
 */

template <class T>
ListNodePosi(T) List<T>::find(ListNodePosi(T) p, int n, const T& e) const {
    //assert:0 <= n <= rank(p) < _size
    while (n--) {
        if (p->data == e)
            return p;
        p = p->succ;
    }
    return NULL;
}

template <class T>
ListNodePosi(T) List<T>::search(ListNodePosi(T) p, int n, const T& e) const {
    //在有序列表内节点p及n-1个后继中找到不大于e的最大的元素的位置
    while (n-- && p->data <= e) {
        p = p->succ;
    }
    return p->pred;
}

template <class T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, const T& data){
    _size++;
    return p->insertAsPred(data);
}

template <class T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, const T& data){
    _size++;
    return p->insertAsSucc(data);
}

template <class T>
void List<T>::insertionSort(ListNodePosi(T) p, int n){
    ListNodePosi(T) r = p->pred;
    ListNodePosi(T) q;
    ListNodePosi(T) temp;
    q = p->succ;//q指向待插入节点
    for(int i = 1; i < n; i++){
        temp = q;
        q = q->succ;
        insertA(search(r->succ, i, temp->data), remove(temp));//p及其之后的i个元素都是有序的，可用有序向量的查找返回合适的位置。
    }
}
/*备注
 1.错误代码：insertA(search(p, i, temp->data), remove(temp));//p被删除释放后，无法找到剩余的序列
 2.错误代码：for(int i = 1; i <= n; i++)//终止条件是 i < n (从n-1个元素里找到合适的位置，将第n个元素插入)
 3.精简版
 for ( int r = 0; r < n; r++ ) { //逐一为各节点
    insertA ( search ( p->data, r, p ), p->data ); //查找适当的位置并插入
    p = p->succ;
    remove ( p->pred ); //转向下一节点
 }
 */

template <class T>
T& List<T>::operator[](Rank r) const {
    ListNodePosi(T) p = header->succ;
    for(int i = 0; i < r; ++i, p = p->succ);
    return p->data;
}
/*疑问
 1.for循环中，最后一个条件写成：i++, p = p->succ。是否可行？答：可行，因为i++在语句结束后才会自增，++i测试过程中也可以正常运行，但理论上应该有风险。
 */

template <class T>
void List<T>::sort(ListNodePosi(T) p, int n){
    mergeSort(p, n);
//    selectionSort(p, n);
//    insertionSort(p, n);
}

template <class T>
int List<T>::deduplicate(){
    if (_size < 2) return 0;//!平凡情况
    int delNum = 0;
    ListNodePosi(T) p = header->succ->succ;//p指向待比较元素
    ListNodePosi(T) q = NULL;//q指向与p重复的元素
    for(int i = 1; p != trailer; p = p->succ){
        if((q = find(header->succ, i, p->data))){
            remove(q);
            delNum++;
        }
        else
            i++;
    }
    return delNum;
}

template <class T>
int List<T>::uniquify(){
    if ( _size < 2 ) return 0; //平凡列表自然无重复
    ListNodePosi(T) p;
    int delNum = 0;
    for (p = header->succ; p != trailer;) {
        if(p->data == p->succ->data){
            remove(p->succ);
            delNum++;
        }
        else
            p = p->succ;
    }
    return delNum;
}

template <class T>
void List<T>::traverse(void (*visit)( T& )){
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
        visit(p->data);
    }
}

template <class T>
template <typename VST> void List<T>::traverse(VST& visit){
    for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
        visit(p->data);
}

template <class T>
void List<T>::reverse(){
    ListNodePosi(T) p;
    ListNodePosi(T) q;
    T e;
    int i;
    for (i = 0, p = header->succ, q = trailer->pred; i < _size / 2; p = p->succ, q = q->pred, i++) {
        e = p->data;
        p->data = q->data;
        q->data = e;
    }
}

#endif /* list_h */



