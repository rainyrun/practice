//
//  intro.h
//  BDS
//
//  Created by 润蕾 on 2018/8/6.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef intro_h
#define intro_h

template <class T>
class Intro{
public:
    void shift(T A[], int n, int k);
};


template <class T>
void Intro<T>::shift(T A[], int n, int k){
    int x, y;
    x = 0;
    for(int i = 0; i < n; i++){
        T temp;
        y = (x - k + n) % n;
        temp = A[0];
        A[0] = A[y];
        A[y] = temp;
        x = y;
    }
}

#endif /* intro_h */
