//
//  bitmap.h
//  BDS
//
//  Created by 润蕾 on 2018/8/16.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#ifndef bitmap_h
#define bitmap_h

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

class Bitmap{
private:
    char* M;//位图所存放的空间，一个char占1比特存放8位
    int N;//容量，=N*sizeof(char)*8个位
protected:
    void init(int n){
        M = new char[N = (n + 7) / 8];//n为集合中元素的个数，N = n／8 向上取整
        memset(M, 0, N);//初始化，将M指向的地址为起始的N个字节设置为0
    }
public:
    Bitmap(int n = 8){ init(n); }//按指定或默认规模，构造位图
    Bitmap(char* file, int n = 8){//按指定或默认规模，从指定文件中读取位图
        init(n);
        FILE* fp = fopen(file, "r");
        fread(M, sizeof(char), N, fp);
        fclose(fp);
    }
    ~Bitmap(){ delete [] M; M = NULL; }
    
    void set(int k){//将第i位置为true（将整数i加入当前集合）
        expand(k);
        M[k >> 3] |= (0x80 >> (k & 0x07));//(k & 0x07)相当于 k % 8; k >> 3相当于 k / 8
    }
    void clear(int k){//将第i位置为false（从当前集合中删除整数i）
        expand(k);
        M[k >> 3] &= ~(0x80 >> (k & 0x07));
    }
    bool test(int k){//测试第i位是否位true（整数i是否属于当前集合）
        expand(k);
        return M[k >> 3] & (0x80 >> (k & 0x07));
    }
    void dump(char* file){//将位图整体导出到指定的文件
        FILE* fp = fopen(file, "w");
        fwrite(M, sizeof(char), N, fp);
        fclose(fp);
    }
    char* bits2string(int n){//将前n位转化为字符串
        expand(n - 1);
        char* s = new char[n + 1];
        s[n] = '\0';
        for (int i = 0; i < n; i++) {
            s[i] = test(i) ? '1' : '0';
        }
        return s;
    }
    void expand(int k){//若被访问的Bitmap[k]已出界，则需扩容
        if( k < 8 * N)//没有越界，无序加倍
            return;
        int oldN = N;
        char* oldM = M;
        init(2 * k);//加倍
        memcpy_s(M, N, oldM, oldN);//原数据转移至新空间
        delete [] oldM;
    }
};

#endif /* bitmap_h */
