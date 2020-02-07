//
//  main.cpp
//  33BinaryTreeIsSearchTree
//
//  Created by April Yang on 2020/2/7.
//  Copyright © 2020 April Yang. All rights reserved.
//  二叉搜索树的后序遍历序列

#include <iostream>
#include "BinaryTree.hpp"

/*
 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回true，
 否则返回false。假设输入的数组的任意两个数字都互不相同。
 例如，输入数组{5, 7, 6, 9, 11, 10, 8}, 则返回true，如果输入的数组是{7, 4, 6, 5},
 则由于没有哪颗二叉搜索树的后序遍历结果是这个序列，因此返回false.
 */


bool VerifySquenceOfBST(int sequence[], int length)
{
    if (sequence == nullptr || length <= 0)
        return false;
    
    // 最后一个点是根节点，左子树的数都比根节点小，右子树的数都比根节点大
    
    int root = sequence[length-1];
    
    // 找到左子树
    int i=0;
    for (; i<length-1; i++)
    {
        if (sequence[i]>root)
            break;
    }
    
    // 找到右子树
    int j=i;
    for(; j<length-1; j++)
    {
        if (sequence[j]<root)
            return false;
    }
    
    // 判断左子树
    bool left = true;
    if (i > 0)
    {
        left = VerifySquenceOfBST(sequence, i);
    }
    
    // 判断右子树
    bool right = true;
    if (i < length-1)
    {
        right = VerifySquenceOfBST(sequence+i, length-1-i);
    }
    
    return left && right;
}

// ====================���Դ���====================
void Test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(VerifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else
        printf("failed.\n");
}

//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void Test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    Test("Test1", data, sizeof(data)/sizeof(int), true);
}

//           5
//          / \
//         4   7
//            /
//           6
void Test2()
{
    int data[] = {4, 6, 7, 5};
    Test("Test2", data, sizeof(data)/sizeof(int), true);
}

//               5
//              /
//             4
//            /
//           3
//          /
//         2
//        /
//       1
void Test3()
{
    int data[] = {1, 2, 3, 4, 5};
    Test("Test3", data, sizeof(data)/sizeof(int), true);
}

// 1
//  \
//   2
//    \
//     3
//      \
//       4
//        \
//         5
void Test4()
{
    int data[] = {5, 4, 3, 2, 1};
    Test("Test4", data, sizeof(data)/sizeof(int), true);
}

// ����ֻ��1�����
void Test5()
{
    int data[] = {5};
    Test("Test5", data, sizeof(data)/sizeof(int), true);
}

void Test6()
{
    int data[] = {7, 4, 6, 5};
    Test("Test6", data, sizeof(data)/sizeof(int), false);
}

void Test7()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    Test("Test7", data, sizeof(data)/sizeof(int), false);
}

void Test8()
{
    Test("Test8", nullptr, 0, false);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();

    return 0;
}

