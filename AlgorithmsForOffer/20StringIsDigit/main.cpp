//
//  main.cpp
//  20StringIsDigit
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  表示数值的字符串


#include <iostream>
using namespace std;

/*
 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 例如，字符串"+100", "5e2", "-123", "3.1416"及"-1E-16"都表示数值，
 但"12e"，"1a3.14", "1.2.3","+-5"及"12e+5.4"都不是。
 */

// 数字的格式可以用A[.[B]][e｜EC], 或者.B[e｜EC]表示，其中A、C是有符号整数，B是无符号整数
bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);
bool isNumberic(const char* str)
{
    if (str == nullptr)
        return false;
    
    bool numeric = scanInteger(&str);
    
    if (*str == '.')
    {
        str++;
        
        numeric = scanUnsignedInteger(&str) || numeric;
    }
    if (*str == 'e' || *str == 'E')
    {
        str++;
        numeric = scanInteger(&str) && numeric;
    }
    
    return numeric && *str == '\0';
}

bool scanUnsignedInteger(const char** str)
{
    const char *begin = *str;
    
    while (**str >= '0' && **str <= '9') {
        (*str)++;
    }
    
    return begin < *str;
}

bool scanInteger(const char** str)
{
    if (**str=='-' || **str=='+')
        (*str)++;
    return scanUnsignedInteger(str);
}

void Test(char* testName, const char* str, bool expected)
{
    printf("%s begin: ", testName);
    if (isNumberic(str) == expected)
    {
        printf("%s\t", str);
        printf("Passed.\n");
    }
       
    else
        printf("Failed.\n");
    
    
}

int main(int argc, const char * argv[]) {
    
//    float arr[] = {2345, 1., 1.e2, 1.2e4, 1.2E3, 1.2E-1, .2, .2e2, .2e-2, .2E3, 0.2E-3,};
    
    Test("test1", "-2345", true);
    Test("test2", "1.", true);
    Test("test3", "+1.e2", true);
    Test("test4", "1.2e-4", true);
    Test("test5", "1.2E+3", true);
    Test("test6", "-1.2E-1", true);
    Test("test7", ".2", true);
    Test("test8", ".2e2", true);
    Test("test9", ".2e-2", true);
    Test("test10", ".2E3", true);
    Test("test11", "0.2E-3", true);
    Test("test12", "12e", false);
    Test("test13", "1a3.14", false);
    Test("test14", "1.2.3", false);
    Test("test15", "+-5", false);
    Test("test16", "12e+5.4", false);

    return 0;
}
