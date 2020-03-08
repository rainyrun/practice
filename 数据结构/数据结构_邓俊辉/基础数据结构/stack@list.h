//
//  stack@list.h
//  BDS
//
//  Created by 润蕾 on 2018/8/7.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef stack_list_h
#define stack_list_h
#include "list.h"

template <class T>
class Stack: public List<T>{//以列表为基类，派生出栈模板类
public:
    void push(const T& e);//入栈
    T pop();//出栈
    T& top();//返回栈顶元素
};

template <class T>
void Stack<T>::push(const T& e){
    insertAsLast(e);
}

template <class T>
T pop(){
    return remove(last());
}

template <class T>
T& top(){
    return last()->data;
}

#endif /* stack_list_h */
