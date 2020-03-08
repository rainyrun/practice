//
//  04_ReplaceBlank.cpp
//  C++Programing
//
//  Created by 润蕾 on 2018/6/23.
//  Copyright © 2018年 润蕾. All rights reserved.
//

#include <iostream>
using namespace std;

void replaceBlank(char * strings, int length);
void test(const char * testName, char *strings, int length);

/*将给定字符串中的空格，替换为%20.在字符串上修改，长度超过给定长度时，不做处理*/
void replaceBlank(char *strings, int length){
    if(strings != NULL && length > 0){
        int blankNum, oldLen, newLen;
        blankNum = oldLen = newLen = 0;
        //统计字符串长度及空格数
        for(; strings[oldLen] != '\0'; oldLen++){
            if(strings[oldLen] == ' ')
                blankNum++;
        }
        newLen = oldLen + blankNum * 2;
        if(newLen > length)
            return;
        //for (int i = newLen, j = oldLen; i > 0 && j > 0; i--, j--) {
        //当i = j时，说明前面没有空格，就不用再比较元素了.(移动元素要包括'\0',所以 i = newLen 而不是 i = newLen - 1;)
        //疑问：当改成i = newLen - 1时，运行结果依然正确，并没有想象中程序无法判断字符串结尾的情况，这是为什么？
        for (int i = newLen, j = oldLen; i > j && j >= 0; i--, j--) {
            if(strings[j] == ' '){
                strings[i--] = '0';
                strings[i--] = '2';
                strings[i] = '%';
            }
            else
                strings[i] = strings[j];
        }
    }
}

void Test(const char *testName, char *strings, int length, const char *expected){
    if(testName != NULL)
        printf("%s begins: ", testName);
    
    replaceBlank(strings, length);
    
    if(expected == NULL && strings == NULL)
        printf("passed.\n");
    else if(expected == NULL && strings != NULL)
        printf("failed.\n");
    else if(strcmp(strings, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
    
   /* cout << "original string is: " << strings <<endl;//如果是*string，则显示的是一个字母，而不是字符串。
    replaceBlank(strings, length);
    cout << "after replaceBlank: " << strings <<endl;*/
}

// 空格在句子中间
void Test1()
{
    const int length = 100;
    
    char string[length] = "hello world";
    Test("Test1", string, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
    const int length = 100;
    
    char string[length] = " helloworld";
    Test("Test2", string, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;
    
    char string[length] = "helloworld ";
    Test("Test3", string, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
    const int length = 100;
    
    char string[length] = "hello  world";
    Test("Test4", string, length, "hello%20%20world");
}

// 传入NULL
void Test5()
{
    Test("Test5", NULL, 0, NULL);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;
    
    char string[length] = "";
    Test("Test6", string, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;
    
    char string[length] = " ";
    Test("Test7", string, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;
    
    char string[length] = "helloworld";
    Test("Test8", string, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;
    
    char string[length] = "   ";
    Test("Test9", string, length, "%20%20%20");
}


int main(int argc, const char * argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    return 0;
}
