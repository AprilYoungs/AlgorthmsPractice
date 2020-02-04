//
//  main.cpp
//  17Print1ToMaxN
//
//  Created by April Yang on 2020/2/4.
//  Copyright © 2020 April Yang. All rights reserved.
//  打印从1到最大的n位数

#include <iostream>

/*
 输入数字n，按顺序打印出从1到最大的n位十进制数。比如输入3，则打印出1、2、3一直到最大的3位数999。
 
 注：n并没有范围，很容易超出long long， 所以需要使用字符串代表大数。
 */

// 给字符串的数字加1，并判断是否不能继续增加了
bool Increment(char *number)
{
    int len = (int)strlen(number);
    
    bool isOverflow = false;
    int nTakeover = 0;
    int nSum = 0;
    for (int i=len-1; i>=0; i--)
    {
        nSum = number[i]-'0'+nTakeover;
        if (i==len-1)
            nSum++;
        if (nSum>=10)
        {
            if (i==0)
                isOverflow = true;
            else
            {
                nSum-=10;
                nTakeover = 1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            // 没有进位，结束进程
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}

/// 打印数字忽略数字前面的0
void PrintNumber(char *number)
{
    int len = (int)strlen(number);
    
    bool isBeginZero = true;
    
    for (int i=0; i<len; i++)
    {
        if(isBeginZero && number[i]!='0')
            isBeginZero = false;
        if (!isBeginZero)
            printf("%c", number[i]);
    }
    
    printf("\t");
}

void Print1ToMaxOfDigits_1(int n)
{
    // 非法输入，不打印
    if (n < 1)
        return;
    
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n]='\0';
    
    while (!Increment(number)) {
        PrintNumber(number);
    }
    
    delete [] number;
}

void Print1ToMaxOfDigitsRecursively(char *number, int length, int index)
{
    if (index == length-1)
    {
        PrintNumber(number);
        return;
    }
    
    for(int i=0; i < 10; ++i)
    {
        number[index+1] = i+'0';
        Print1ToMaxOfDigitsRecursively(number, length, index+1);
    }
}

/// 利用递归打印，忽略数学，把数字想象成一个数字队列
/// 前面一位每变化一次后面一位要跟着变化10次，最后一位每变化一次打印一次。
void Print1ToMaxOfDigits_2(int n)
{
    // 非法输入，不打印
    if (n < 1)
        return;
    
    char *number = new char[n+1];
    memset(number, '0', n);
    number[n]='\0';
    
    int index = 0;
    for(int i=0; i < 10; ++i)
    {
        number[index] = i+'0';
        Print1ToMaxOfDigitsRecursively(number, n, index);
    }
    
    delete [] number;
}


int main(int argc, const char * argv[]) {
    
    Print1ToMaxOfDigits_2(-1);
    Print1ToMaxOfDigits_2(0);
    Print1ToMaxOfDigits_2(3);
    
    return 0;
}
