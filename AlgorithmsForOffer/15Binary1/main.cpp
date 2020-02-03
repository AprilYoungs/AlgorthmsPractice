//
//  main.cpp
//  15Binary1
//
//  Created by April Yang on 2020/2/3.
//  Copyright © 2020 April Yang. All rights reserved.
//  二进制中1的个数， 位运算

#include <iostream>

/*
 请实现一个函数，输入一个整数， 输出该数二进制表示中1的个数。
 例如，把9表示成二进制是1001，有2位是1。因此，如果输入9，则该函数输出2。
 */

/// 右移原来的数字，遇到负数会出现死循环
int numberOfOne1(int number)
{
    int count = 0;
    while (number) {
        if (number&1)
            count++;
        number=number>>1;
    }
    return count;
}

int numberOfOne2(int number)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (number&flag)
            count++;
        flag=flag<<1;
    }
    return count;
}

int numberOfOne3(int number)
{
    int count = 0;
    
    while (number) {
            count++;
        number=number&(number-1);
    }
    return count;
}

void Test(std::string testName, int num, int expected)
{
    printf("------------------\n%s:\n", testName.c_str());
//    if (numberOfOne1(num) == expected)
//        printf("1 passed.\n");
//    else
//        printf("1 failed.\n");
    
    if (numberOfOne2(num) == expected)
        printf("2 passed.\n");
    else
        printf("2 failed.\n");
    
    if (numberOfOne3(num) == expected)
         printf("3 passed.\n");
     else
         printf("3 failed.\n");
}

int main(int argc, const char * argv[]) {
    
    Test("test1", 9, 2);
    Test("test2", -1, 32);
    Test("test3", 0, 0);
    Test("test4", 0b1001001001, 4);
    
    // 判断一个数是否是2的整次方
    // 1000 & 0111 == 0, 所以是2的整次方
    int a = 0b1000;
    printf("%d %s 二的整次方\n",  a, (a&(a-1))==0 ? "是" : "不是");
    
    // 求两个数m和n表示成二进制之后，需要改变多少位才能把m变成n ？
    // 使用异或: ^
    // c = m ^ n, 求c中1的个数
    int m = 0b10010;
    int n = 0b11001;
    printf("不同的个数 %d\n", numberOfOne3(m^n));
    
    return 0;
}
