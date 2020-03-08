//
//  main.cpp
//  C++Programing
//
//  Created by 润蕾 on 2018/6/14.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include <iostream>
using namespace std;

bool Find(int matrix[][4], int col, int row, int number);
void Test(const char* testName, int* matrix, int rows, int columns, int number, bool expected);
void Test1();
void Test2();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();

int main(int argc, const char * argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    return 0;
}


/*总结
 1. bool Find(int matrix[][4], int cols, int rows, int number){
 使用int matrix[][4]作为参数，会限制数组只能是4列。可以用一维数组，模拟二维数组，使程序更灵活
 2. 当查找有序序列时，首先考虑二分查找。在该数组情况下，每一行和每一列的交点，从左到右，从上到下有序，因此可以考虑从右上角或左下角逼近
 3. 程序有效性检查，一般采用“符合该条件则开始运行程序”，如：
     if( matrix != NULL && cols >=0 && rows >= 0){
     }
 4. 
 */

/*功能：在matrix中查找number
 matrix：为二维数组，每一行都从左到右递增排序，每一列都从上到下递增排序
 cols/rows：行数、列数
 number：要查找的数字
 */
bool Find(int *matrix, int cols, int rows, int number){
    bool found = false;
    int col, row;

    if(matrix == NULL || cols < 0 || rows < 0)
        return false;
    row = 0;
    col = cols - 1;
    while(row < rows && col >= 0){
        if(matrix[row * cols + col] == number){
            found = true;
            break;
        }
        else if(matrix[row * cols + col] < number)
            row += 1;
        else
            col -= 1;
    }
    return found;
}

// ====================测试代码====================
void Test(const char* testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    bool result = Find(matrix, rows, columns, number);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数在数组中
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int*)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数不在数组中
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int*)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最小的数字
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int*)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数是数组中最大的数字
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int*)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最小的数字还小
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int*)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// 要查找的数比数组中最大的数字还大
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int*)matrix, 4, 4, 16, false);
}

// 鲁棒性测试，输入空指针
void Test7()
{
    Test("Test7", NULL, 0, 0, 16, false);
}


