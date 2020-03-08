//  vector.h
//  Created on 2018/7/25.

#ifndef vector_h
#define vector_h
/*待完成
    双向冒泡排序
    patition();//轴点构造算法
    void quickSort(Rank lo, Rank hi);//快速排序
    heapSort();//堆排序
 */


typedef int Rank;   //秩
#define DEFAULT_CAPACITY 6  //默认的初始容量

template <class T>
class Vector{
protected:
    //下划线表示内部定义的元素，和形参做区分
    Rank _size; //规模
    T* _elem;   //数据区
    int _capacity;  //容量
    
    void copyFrom(const T* A, Rank lo, Rank hi);//复制
    void expand();//如有必要，扩容
    void shrink();//如有必要，缩容
    int bubble(Rank lo, Rank hi);//扫描交换
    void bubbleSort(Rank lo, Rank hi);//冒泡排序
    //双向冒泡排序
    Rank max(Rank lo, Rank hi);//在[lo, hi)中选取最大元素
    void selectionSort(Rank lo, Rank hi);//选择排序
    void merge(Rank lo, Rank mi, Rank hi);//归并算法
    void mergeSort(Rank lo, Rank hi);//归并排序
//    patition();//轴点构造算法
//    void quickSort(Rank lo, Rank hi);//快速排序
//    heapSort();//堆排序
//
public:
//构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0){
        _elem = new T[_capacity = c];
        for (_size = 0; _size < s; _elem[_size++] = v)
            ;
//        printf("defalut constructor called.\n");
    }
    Vector(const T* A, Rank n){//A是T类型的指针，指向一个常量
        copyFrom(A, 0, n);
//        printf("fullcopy constructor called.\n");
    }//数组整体复制
    Vector(const T* A, Rank lo, Rank hi){
        copyFrom(A, lo, hi);
//        printf("partcopy constructor called.\n");
    }//区间复制
    Vector(const Vector<T>& V){
        copyFrom(V._elem, 0, V._size);
//        printf("vector fullcopy constructor called.\n");
    }//向量整体复制
    Vector(const Vector<T>& V, Rank lo, Rank hi){
        copyFrom(V._elem, lo, hi);
//        printf("vector partcopy constructor called.\n");
    }//向量区间复制
//析构函数
    ~Vector(){
        delete [] _elem;
//        printf("destructor called.\n");
    }

//用const修饰，表示只读
    int size() const {return _size;};//返回向量当前的规模（元素总数）
    bool empty() const {return !_size;};
    int disordered() const {return bubble(0, _size);};//判断所有元素是否已按非降序排列
    Rank find(T e) const {return find(e, 0, _size);};//查找等于e且秩最大的元素，无序向量
    //Rank find ( T const& e );
    /*疑问
     1.为什么使用长引用？什么时候使用长引用，什么时候用值传递？*/
    Rank find(T e, Rank lo, Rank hi) const;//无序向量，区间查找
    Rank search(T e) const {return search(e, 0, _size);};//查找目标元素e，返回不大于e且秩最大的元素(有序向量)
    Rank interpolatinSearch(const T& e) const;
    /*
     Rank search ( T const& e ) const //有序向量整体查找
     { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
     疑问：参数的合法性判断，放在哪个位置比较好？答：例子都放在了上层调用函数里。
     */
    Rank search(T e, Rank lo, Rank hi) const;//有序向量，区间查找
    
    void put(Rank r, T e);//用e替换秩为r的元素的数值
    int insert(Rank r, T e);//e作为秩为r的元素插入，原后继元素依次后移
    int insert(T e){ return insert(_size, e); };//默认作为末元素插入；
    T remove(Rank r);//删除秩为r的元素，返回该元素中原存放的对象
    int remove(Rank lo, Rank hi);//区间删除
    void swap(T& i, T& j);
    void sort(){sort(0, _size);};//调整各元素的位置，使之按非降序排列
    void sort(Rank lo, Rank hi);//区间排序
    
    void unsort(Rank lo, Rank hi);//区间置乱
    void unsort(){unsort(0, _size);};//整体置乱
    int deduplicate(Rank lo, Rank hi);//删除重复元素，返回删除的元素数
    int uniquify(Rank lo, Rank hi);//删除重复元素（有序向量），返回删除的元素数
    void traverse(void (*)(T&));//遍历向量并统一处理所有元素，处理方法由函数指针制定
    template <typename VST> void traverse ( VST& ); //遍历（使用函数对象，可全局性修改）
    
    T& operator [](Rank i) const;
    /*备注：
     1.此处的返回值为引用类型*/
    Vector<T> & operator= ( Vector<T> const& ); //重载赋值操作符，以便直接克隆向量
    
};//vector

template <class T>
void Vector<T>::copyFrom(const T* A, Rank lo, Rank hi){
    _size = hi - lo;
    _capacity = 2 * _size;
    _elem = new T[_capacity];
    for (int i = 0; i < _size; i++, lo++) {
        _elem[i] = A[lo];
    }
}//copyFrom
/*疑问
 1.复制构造需要分配空间吗？答：需要，复制构造是在对象已构造好以后，用已存在的对象去初始化同类型的新对象。和构造函数的意义类似
 2.复制构造时，参数hi超过的数组的长度，为什么没有报错？答：因为传递的是指针，并不知道数组长度，按指针来看并没有出错。
 3.情况2中的越界问题，应该如何避免？
 */

template <class T>
void Vector<T>::expand(){
    if(_size == _capacity){//扩容条件
        if ( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //不低于最小容量
//        printf("expanding.\n");
        /*初始代码比较繁琐
        T* oldElem;
        _capacity *= 2;
        T* newElem = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            newElem[i] = _elem[i];
        }
        oldElem = _elem;
        _elem = newElem;
        */
        T* oldElem = _elem;
        _elem = new T[_capacity <<= 1]; //容量加倍
        for ( int i = 0; i < _size; i++ )
            _elem[i] = oldElem[i]; //复制原向量内容（T为基本类型，或已重载赋值操作符'='）
        delete [] oldElem;
    }
}
/*备注
 增加代码
 if ( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //不低于最小容量
 */

template <class T>
void Vector<T>::put(Rank r, T e){
    if (r < _size && 0 <= r){
        _elem[r] = e;
    }
}

template <class T>
Rank Vector<T>::insert(Rank r, T e){
    expand();
    for (int i = _size; i > r; i--) {
        _elem[i] = _elem[i-1];
    }
    _elem[r] = e;
    _size++;
    return r;
}

template <class T>
void Vector<T>::shrink(){
    if ( _capacity < DEFAULT_CAPACITY << 1 ) return; //不致收缩到DEFAULT_CAPACITY以下
    if(_size < _capacity >> 2){//缩容条件
//        printf("shrinking.\n");
        T* oldElem = _elem;
        _capacity /= 2;
        _elem = new T[_capacity];
        for (int i = 0; i < _size; i++) {
            _elem[i] = oldElem[i];
        }
        delete [] oldElem;
    }
}
/*备注
 添加代码：if ( _capacity < DEFAULT_CAPACITY << 1 ) return; //不致收缩到DEFAULT_CAPACITY以下
 */

template <class T>
int Vector<T>::remove(Rank lo, Rank hi){//区间删除
//    printf("removing...\n");
    int i, j;//其实可以直接使用lo 和 hi
    for (i = lo, j = hi; i >= 0 && j < _size; i++, j++) {//循环条件内加入了界限判断
        _elem[i] = _elem[j];
    }
    //or _size = i;
    _size -= (j - i);
    shrink();
    return j-i;
}

template <class T>
T Vector<T>::remove(Rank r){
    T temp = _elem[r];
    remove(r, r+1);
    return temp;
}

template <class T>
int Vector<T>::bubble(Rank lo, Rank hi){
    if(hi <= _size && 0 <= lo){
        int rank = lo;
        for (int i = lo; i < hi; i++) {
            if(_elem[i] > _elem[i + 1]){//检查是否有逆序
                rank = i;//rank指向最后发生逆序的位置
                swap(_elem[i], _elem[i + 1]);
            }
        }
        return rank;
    }
    return -1;
}
/*备注
 1.rank指向逆序对的前一个即可。因为最后一个逆序对元素交换后，后一个元素必然就位。
 2.因为后续程序会引用bubble，所以 i=哨兵 更合适
 */

template <class T>
void Vector<T>::swap(T& i, T& j){
    T temp;
    temp = i;
    i = j;
    j = temp;
}

template <class T>
void Vector<T>::sort(Rank lo, Rank hi){
//    bubbleSort(lo, hi);
//    selectionSort(lo, hi);
    mergeSort(lo, hi);
//    quickSort(lo, hi);
}

template <class T>
void Vector<T>::bubbleSort(Rank lo, Rank hi){
    /*原代码
    for (int i = _size; 0 < i;) {
        i = bubble(0, i);
    }
    */
    while(lo < (hi = bubble(lo, hi)));
}
/*备注：
 1.初次调试，未能正确排序。发现for(int i = _size; 0 < i; i++) 中的“i++”这个条件不需要。因为bubble返回的是秩，直接使用即可，i++后反而会跳过某些值*/

template <class T>
void Vector<T>::selectionSort(Rank lo, Rank hi){
    for(int i = hi; lo < i; i--)//依次将最大的元素放在最末尾
        swap(_elem[i - 1], _elem[max(lo, i)]);
}

template <class T>
Rank Vector<T>::max(Rank lo, Rank hi){
    Rank maxRank = lo;
    for(int i = lo; i < hi; i++){
        if( _elem[maxRank] < _elem[i])//注意不要用maxRank和_elem[i]相比较
            maxRank = i;
    }
    return maxRank;
}
/*备注：
 1.注意命名规范，若将maxRank起名为max，则极易出现max(秩)和_elem[i](元素)相比较的错误。
 2.因为max()需要将前缀都遍历一遍，即使前缀已是顺序，也无法及时发现，故选择排序复杂度0(n^2);
 */

template <class T>
void Vector<T>::mergeSort(Rank lo, Rank hi){
    Rank mi = (hi + lo) / 2;
    if(1 < mi - lo)//or if ( hi - lo < 2 ) return;
        mergeSort(lo, mi);
    if(1 < hi - mi)
        mergeSort(mi, hi);
    merge(lo, mi, hi);
}
/*备注：
 1.mi != （hi - lo) / 2;
 2.如果不想漏掉某个函数的执行过程，可以在该函数第一句打一个断点
 3.错误代码
 if(hi - lo > 1){//当区间长度为3时，拆分的左半区间长度为1，而右半区间就直接略过没有处理。
    Rank mi = (hi + lo) / 2;
    mergeSort(lo, mi);
    mergeSort(mi, hi);
    merge(lo, mi, hi);
 }
 限制条件尽量和相关代码紧邻，防止出错。
 */

/*疑问
 1.通常错误处理放在哪部分处理？主函数还是被调函数？*/

//！重点关注
/*code-0.1
template <class T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi){//子向量[lo, mi), [mi, hi)
    //！经过合适的重新封装，可以帮助理解，还不容易出错
    T* A = _elem + lo; //合并后的向量A[0, hi - lo) = _elem[lo, hi)
    int lb = mi - lo;
    //B使用T类型的数组即可，不需要是向量类型
    //Vector<T> B(*this, lo, mi);//A = B + C
    T* B = new T[lb];
    for ( Rank i = 0; i < lb; B[i] = A[i++] ); //复制前子向量
    Rank i, j, k;//i, j, k分别指向向量B（前半部分向量），C（后半部分向量），A（待排序向量）
    
    for(i = 0, j = mi, k = lo; i < mi - lo;){
        if((i < mi - lo && B[i] <= _elem[j]) || (hi <= j))
            _elem[k++] = B[i++];
        else if(j < hi && _elem[j] < B[i])
            _elem[k++] = _elem[j++];
    }
}
*/

template <class T> //有序向量的归并
void Vector<T>::merge ( Rank lo, Rank mi, Rank hi ) { //各自有序的子向量[lo, mi)和[mi, hi)
    //使用合适的封装可以帮助理解，还可以避免备注2的错误
    T* A = _elem + lo; //合并后的向量A[0, hi - lo) = _elem[lo, hi)
    T* C = _elem + mi; //后子向量C[0, lc) = _elem[mi, hi)
    int lc = hi - mi;
    int lb = mi - lo;
    T* B = new T[lb]; //前子向量B[0, lb) = _elem[lo, mi)
    for ( Rank i = 0; i < lb; i++)
        B[i] = A[i]; //复制前子向量
    
    for ( Rank i = 0, j = 0, k = 0; ( j < lb ) || ( k < lc ); ) { //B[j]和C[k]中的小者续至A末尾
        //B中还有数 && （C中没数 或 B中的数小）则……
        if ( ( j < lb ) && ( ! ( k < lc ) || ( B[j] <= C[k] ) ) ) A[i++] = B[j++];
        if ( ( k < lc ) && ( ! ( j < lb ) || ( C[k] <  B[j] ) ) ) A[i++] = C[k++];
    }
    delete [] B; //释放临时空间B
} //归并后得到完整的有序向量[lo, hi)


/*备注
 1.(code-0.1)不需要主动delete B，B在析构时会自动释放
 2.(code-0.1)错误代码
 for(i = lo, j = mi, k = lo; i < mi;){
    if((i < mi && B._elem[i] <= _elem[j]) || (hi <= j))//B向量的秩从0开始，而不是lo
 */


//template <class T>
//void Vector<T>::quickSort(Rank lo, Rank hi){
//
//}

template <class T>
Rank Vector<T>::find(T e, Rank lo, Rank hi) const {// 0 <= lo < hi <= _size
    int i;
    for(i = hi - 1; lo <= i && _elem[i] != e; i--);
    if( lo <= i && _elem[i] == e)
        return i;
    else
        return -1;
}

template <class T>
Rank Vector<T>::search(T e, Rank lo, Rank hi) const {// 0 <= lo < hi <= _size
    Rank mi;
    while ( lo != hi ){
        mi = (lo + hi) / 2;
        if (_elem[mi] <= e)
            lo = mi + 1;
        else
            hi = mi;
        //简洁版( e < A[mi] ) ? hi = mi : lo = mi + 1;
    }
    return --lo;
}
/*备注：
 1.错误代码
 return lo--//返回的是lo，而不是lo-1
 */

template <class T>
void Vector<T>::unsort(Rank lo, Rank hi){
    for(int i = hi - 1; lo < i; i--)
        swap(_elem[i], _elem[lo + rand()%(i - lo)]);
}
/*向量重新封装后比较好理解
 T* V = _elem + lo; //将子向量_elem[lo, hi)视作另一向量V[0, hi - lo)
 for ( Rank i = hi - lo; i > 0; i-- ) //自后向前
    swap ( V[i - 1], V[rand() % i] ); //将V[i - 1]与V[0, i)中某一元素随机交换
 */

template <class T>
int Vector<T>::deduplicate(Rank lo, Rank hi){//无序向量去重
    int oldSize = hi - lo;
    Rank i = lo + 1;
    while(i < hi){
        if(find(_elem[i], lo, i) != -1){
            remove(i);
            hi--;
        }
        else
            i++;
    }
    return oldSize - (hi - lo);
}
/*备注
 1.去重后，hi的值会变化
 2.错误代码
     _size -= (oldSize - (hi - lo));//不需要加这句，remove()在删除元素后，会更新size的值。
 */

template <class T>
int Vector<T>::uniquify(Rank lo, Rank hi){//有序向量去重
    Rank i, j;//i指向去重后的向量，j指向原向量
    i = lo;
    j = lo + 1;
    while(j < hi){
        if(_elem[j] == _elem[i])
            j++;
        else
            _elem[++i] = _elem[j++];
    }
    _size = i + 1;
    return j - _size;
}
/*备注：
 1.while循环中的简洁版
 while ( ++j < _size ) //逐一扫描，直至末元素
    if ( _elem[i] != _elem[j] ) //跳过雷同者
    _elem[++i] = _elem[j]; //发现不同元素时，向前移至紧邻于前者右侧
 */

template <class T>
void Vector<T>::traverse(void (*visit)(T&)){
    for (int i = 0; i < _size; i++) {
        visit(_elem[i]);
    }
}

template <class T> template <typename VST>
void Vector<T>::traverse(VST& visit){
    for(int i = 0; i < _size; i++)
        visit(_elem[i]);
}

template <class T>
T& Vector<T>::operator [](Rank i) const{
    return _elem[i];
}

template <class T>
Vector<T>& Vector<T>::operator= ( Vector<T> const& V){
    if ( _elem ) delete [] _elem; //释放原有内容
    copyFrom(V._elem, 0, V._size);
    return *this; //返回当前对象的引用，以便链式赋值
}
/*备注：
 增加内容为：
 if ( _elem ) delete [] _elem; //释放原有内容
 return *this; //返回当前对象的引用，以便链式赋值
 */

template <class T>
Rank Vector<T>::interpolatinSearch(const T& e) const{
    Rank hi, lo, mi;
    hi = _size - 1;
    lo = 0;
    do{
        mi = lo + (hi - lo) * (e - _elem[lo]) / (_elem[hi] - _elem[lo]);
        if(_elem[mi] == e)
            return mi;
        else if (e < _elem[mi])
            hi = mi - 1;
        else
            lo = mi + 1;
    }while( lo < hi);
    return 0;
}

template <class T>
struct Double{
    virtual void operator() (T& e) {
        e *= 2;
    }
};

template <class T>
void doubler(Vector<T>& V){
    V.traverse(Double<T>());
}

#endif /* vector_h */
