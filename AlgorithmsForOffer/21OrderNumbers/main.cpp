//
//  main.cpp
//  21OrderNumbers
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  调整数组顺序使奇数位于偶数前面

#include <iostream>

/*
 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
 */

bool isOdd(int num)
{
    return (num&1) == 1;
}

void orderArrWithFunc(int arr[], int length, bool(*func)(int))
{
    if (arr == nullptr || length <= 0)
        return;
    
    // 两边包围中间
    
    int left = 0;
    int right = length-1;
    while (left < right) {
        
        while (func(arr[left]) && left < right)
            left++;
           
        while (right>left && !func(arr[right]))
            right--;
        
        if (left < right)
        {
            arr[left] = arr[left] + arr[right];
            arr[right] = arr[left] - arr[right];
            arr[left] = arr[left] - arr[right];
        }
    }
}

void orderArr(int arr[], int length)
{
    orderArrWithFunc(arr, length, isOdd);
}

void Test(std::string testName, int arr[], int length)
{
    printf("----------------\n%s begin:\n", testName.c_str());
    
    orderArr(arr, length);
    bool odd = true;
    bool isPassed = true;
    for (int i=0; i < length; i++)
    {
        printf("%d\t", arr[i]);
        if (odd && !isOdd(arr[i]))
        {
            odd = false;
            continue;
        }
        if (!odd && isOdd(arr[i]))
        {
            isPassed = false;
        }
    }
    
    if (isPassed)
        printf("\nPassed.\n");
    else
        printf("\nFailed.\n");
}

void test1()
{
    int arr[] = {1, 2, 3, 4, 5};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, arr, len);
}

void test2()
{
    int arr[] = {1, 3, 5, 7, 9};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, arr, len);
}

void test3()
{
    int arr[] = {2, 2, 6, 8, 10};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, arr, len);
}

void test4()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 8};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, arr, len);
}

void test5()
{
    int arr[] = {1};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, arr, len);
}

void test6()
{
    int arr[] = {1};
    int len = sizeof(arr)/sizeof(int);
    Test(__func__, nullptr, 0);
}


int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    return 0;
}
