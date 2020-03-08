#include <stdio.h>
#include <string.h>

int num_of_palindrome_substring(char *string){
    if(string == NULL)
        return 0;
    
    int n = strlen(string);
    int dp[n][n];//dp[j][i]表示从j到i的字符串是否是回文串
    int i, j;
    int num = 0;
    
    memset(dp, 0, sizeof(dp));
    
    for(i = 0; i < n; i++){
        for(j = 0; j <= i; j++){
            if(i == j){
                dp[j][i] = 1;
                num++;
            }
            else if((j + 1) == i && string[i] == string[j]){
                dp[j][i] = 1;
                num++;
            }
            else{
                if(string[i] == string[j] && dp[j+1][i-1]){
                    dp[j][i] = 1;
                    num++;
                }
            }
        }
    }
    return num;
}

int num_of_palindrome_substring_brute(char *string){
    if(string == NULL)
        return 0;
    
    int n = strlen(string);
    int i, j, start, end;
    int num = 0;
    
    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            start = i;
            end = j;
            while(string[start] == string[end] && start < end){
                start++;
                end--;
            }
            if(start >= end)
                num++;
        }
    }
    return num;
}

void test1(void){
    char string[] = "";
    int num1, num2;
    num1 = num_of_palindrome_substring(string);
    num2 = num_of_palindrome_substring_brute(string);
    if(num1 == num2)
        printf("test1 pass.\n");
    else
        printf("test1 failed.\n");
}

void test2(void){
    char *string = NULL;
    int num1, num2;
    num1 = num_of_palindrome_substring(string);
    num2 = num_of_palindrome_substring_brute(string);
    if(num1 == num2)
        printf("test2 pass.\n");
    else
        printf("test2 failed.\n");
}

void test3(void){
    char string[] = "a";
    int num1, num2;
    num1 = num_of_palindrome_substring(string);
    num2 = num_of_palindrome_substring_brute(string);
    if(num1 == num2)
        printf("test3 pass.\n");
    else
        printf("test3 failed.\n");
}

void test4(void){
    char string[] = "abccba";
    int num1, num2;
    num1 = num_of_palindrome_substring(string);
    num2 = num_of_palindrome_substring_brute(string);
    if(num1 == num2)
        printf("test4 pass.\n");
    else
        printf("test4 failed.\n");
}

void test5(void){
    char string[] = "abcdcbaaba";
    int num1, num2;
    num1 = num_of_palindrome_substring(string);
    num2 = num_of_palindrome_substring_brute(string);
    if(num1 == num2)
        printf("test5 pass.\n");
    else
        printf("test5 failed.\n");
}

int main(void){
    test1();
    test2();
    test3();
    test4();
    test5();
}
