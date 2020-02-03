//
//  main.cpp
//  16Power
//
//  Created by April Yang on 2020/2/3.
//  Copyright © 2020 April Yang. All rights reserved.
//  实现 double Power(double base, int exponent)

#include <iostream>

/*
 实现 double Power(double base, int exponent)，
 求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 */

bool equal(double a, double b)
{
    double eps = 1E-15;
    double gap = a > b ? a-b : b-a;
    return gap < eps;
}

double PowerAbs(double base, int absExp)
{
    if (absExp == 0)
        return 1;
    if (absExp == 1)
        return base;
    
    double result = PowerAbs(base, absExp >> 1);
    result*=result;
    
    if ((absExp&0x1) == 0x1)
        result*=base;
    
    return result;
}
double Power(double base, int exponent)
{
    // 处理异常，exponent正负问题
    if (exponent == 0)
        return 1;
    if (equal(base, 0.0))
        return 0;
    
    int absExp = exponent > 0 ? exponent : -exponent;
    double result = PowerAbs(base, absExp);
    if (exponent < 0)
        result = 1.0/result;
    
    return result;
}



void Test(std::string testName, double base, int exponent, double expected)
{
    printf("---------------------\n%s:\n", testName.c_str());
    
    double result = Power(base, exponent);
    printf("%f ^ %d = %f\n", base, exponent, result);
    if (equal(result, expected))
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, const char * argv[]) {
    
    Test("test1", 2.0, 3, 8.0);
    Test("test2", 2.0, 10, 1024.0);
    Test("test3", 2.0, 11, 2048.0);
    Test("test4", 0.0, 11, 0.0);
    // 0 按 1 处理
    Test("test5", 0.0, 0, 1.0);
    Test("test6", 0.0, -2, 0.0);
    Test("test7", 2.0, -2, 1/4.0);
    Test("test8", 2.0, -3, 1/8.0);
    Test("test9", 2.0, -4, 1/16.0);
    
    
    return 0;
}
