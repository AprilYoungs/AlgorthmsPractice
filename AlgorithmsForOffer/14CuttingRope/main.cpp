//
//  main.cpp
//  14CuttingRope
//
//  Created by April Yang on 2020/2/3.
//  Copyright © 2020 April Yang. All rights reserved.
//  剪绳子， 动态规划&贪婪算法

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
 给你一根长度为n的绳子，请把绳子剪成m段(m, n都是整数 n > 1 并且 m > 1),
 每段绳子的长度记为k[0],k[1],...,k[m]。 请问k[0]*k[1]*k[...]*k[m]可能的最大乘积是多少？
 例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */


/// 动态规划算法
/// @param n 绳子长度
int maxProduct_dynamic(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    
    // 大于等于4
    int *products = new int[n+1];
    products[1]=1;
    products[2]=2;
    products[3]=3;
    
    int max = 0;
    
    // 从4开始需找最优解
    for (int i=4; i<=n; i++)
    {
        // 寻找局部最优解，使用缓存的值
        max=0;
        for (int j=1; j <= i/2; j++)
        {
            if (max < products[j]*products[i-j])
                max = products[j]*products[i-j];
        }
        products[i]=max;
    }
    
    max = products[n];
    delete [] products;
    
    return max;
}


/// 贪婪算法
/// @param n 绳子长度
int maxProduct_greedy(int n)
{
    if (n < 2)
        return 0;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    
    // 当n >= 5 时，3 越多越好
    int timesOf3 = n/3;
    
    // 如果最后一段是4，不能剪成 1，3
    if(n-timesOf3*3==1)
        timesOf3--;
    
    int timesOf2 = (n-timesOf3*3)/2;
    
    return pow(3, timesOf3)*pow(2, timesOf2);
}

void Test(string testName, int len, int expected)
{
    printf("------------------\n%s:\n", testName.c_str());
    if (maxProduct_dynamic(len) == expected)
        printf("Dynamic passed.\n");
    else
        printf("Dynamic failed.\n");
    
    if (maxProduct_greedy(len) == expected)
        printf("Greedy passed.\n");
    else
        printf("Greedy failed.\n");
}


int main(int argc, const char * argv[]) {
    
    Test("test1", 1, 0);
    Test("test2", 2, 1);
    Test("test3", 3, 2);
    Test("test4", 4, 4);
    Test("test5", 5, 6);
    Test("test6", 6, 9);
    Test("test7", 7, 12);
    Test("test8", 8, 18);
    Test("test9", 9, 27);
    
    return 0;
}
