//
//  stack@vector.h
//  BDS
//
//  Created by 润蕾 on 2018/8/7.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef stack_vector_h
#define stack_vector_h

#include "vector.h"
using namespace std;

template <class T>
class Stack: public Vector<T>{//以向量为基类，派生出栈模板类
public:
    void push(const T& e);
    T pop();
    T& top();
};

template <class T>
void Stack<T>::push(const T& e){
    this->insert(e);
}

template <class T>
T Stack<T>::pop(){
    return this->remove(this->size() - 1);
}

template <class T>
T& Stack<T>::top(){
    return (*this)[this->size() - 1];
}
/*备注
 1.基类成员函数无法被访问
 void Stack<T>::push(const T& e){
 insert(e);//提示 use of undeclared identifer.
 }
 原因：https://www.zhihu.com/question/28139230
 解决方法：加上作用域Vector<T>::或this->
 2.错误代码：
 return this->get(this->size() - 1);//Non-const lvalue reference to type 'char' cannot bind to a temporary of type 'char'
 原因：get的返回值为T，和T&不匹配
 */

#endif /* stack_vector_h */
