//
//  queue@list.h
//  BDS
//
//  Created by 润蕾 on 2018/8/13.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef queue_list_h
#define queue_list_h
#include "list.h"

template <class T>
class Queue: public List<T>{
public:
    void enqueue(const T& e){ this->insertAsLast(e);}
    T dequeue(){ return this->remove(this->first());}
    T& front(){ return this->first()->data; }
};

#endif /* queue_list_h */
