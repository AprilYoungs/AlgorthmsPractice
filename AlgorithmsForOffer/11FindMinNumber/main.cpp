//
//  main.cpp
//  11FindMinNumber
//
//  Created by April Yang on 2020/2/2.
//  Copyright © 2020 April Yang. All rights reserved.
//  旋转数组中的最小数字, 考察二分查找

#include <iostream>
#include <vector>
using namespace std;

/*
 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 例如，数组{3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
 */

int findMin(const vector<int> &arr)
{
    // throw if empty arr
    if (arr.size() < 2)
        return arr[0];
    
    int left = 0;
    int right = (int)arr.size()-1;
    int mid = 0;
    
    while (arr[left] >= arr[right]) {
        
        if (left == right-1)
        {
            mid = right;
            break;
        }
        
        mid = (left+right)/2;
        
        // 如果三个数相同， 用这种方法无法找出最小值
        // {1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1}
        if (arr[left] == arr[mid]
            && arr[mid] == arr[right])
        {
            for (int i=1; i<arr.size(); i++)
                if (arr[i-1]>arr[i])
                    return arr[i];
        }
        
        if (arr[mid] >= arr[left])
            left = mid;
        else
            right = mid;
    }
    
    return arr[mid];
}

void Test(string testName, const vector<int> &arr, int expected)
{
    cout << "-------------------\n" << testName << ":";
    int result = findMin(arr);
    result == expected ? printf("Passed.\n") : printf("Failed.\n");
}

void test1()
{
    vector<int> arr{3, 4, 5, 1, 2};
    Test(__func__, arr, 1);
}

void test2()
{
    vector<int> arr{6, 7, 7, 7, 3, 4, 5};
    Test(__func__, arr, 3);
}

void test3()
{
    vector<int> arr{1};
    Test(__func__, arr, 1);
}

void test4()
{
    vector<int> arr{2, 1};
    Test(__func__, arr, 1);
}

void test5()
{
    vector<int> arr{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1};
    Test(__func__, arr, 0);
}

void test6()
{
    vector<int> arr{1, 2, 3, 4, 5};
    Test(__func__, arr, 1);
}


int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    
    try {
        throw exception();
    } catch (...) {
        cout << "catched" << endl;
    }
    
    return 0;
}
