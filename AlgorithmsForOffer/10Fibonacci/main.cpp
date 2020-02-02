//
//  main.cpp
//  10Fibonacci
//
//  Created by April Yang on 2020/2/2.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>

using namespace std;

/*
 递归和循环问题
 
 变体：🐸青蛙跳台阶问题
 
    一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙上一个n级的台阶总共有多少种跳法。
 
 */

/*
 分析：f(1)=1, f(2)=2, 当只有一个台阶的时候，有一种跳法，有两个台阶的时候有两种跳法。
 当n>2的时候，青蛙第一跳要么1阶，要么2阶，所以f(n)=f(n-1)+f(n-2)
 */


/// 递归求法
/// @param n n
long fibonacci_Recursive(unsigned n)
{
    if (n < 3)
        return n;
    
    return fibonacci_Recursive(n-1)+fibonacci_Recursive(n-2);
}

long fibonacci_Loop(unsigned n)
{
    if (n < 3)
        return n;
    
    long minusOne = 2;
    long minusTwo = 1;
    long finN = 0;
    for (int i=3; i<=n; i++)
    {
        finN = minusOne + minusTwo;
        minusTwo = minusOne;
        minusOne = finN;
    }
    
    return finN;
}


int main(int argc, const char * argv[]) {
    
    unsigned num = 30;
    clock_t begin = clock();
    cout << fibonacci_Recursive(num) << endl;
    clock_t end = clock();
    cout << "time:" << end - begin << endl;
    begin = clock();
    cout << fibonacci_Loop(num) << endl;
    end = clock();
    cout << "time:" << end - begin << endl;
    
    return 0;
}
