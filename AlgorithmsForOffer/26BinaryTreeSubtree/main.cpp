//
//  main.cpp
//  26BinaryTreeSubtree
//
//  Created by April Yang on 2020/2/5.
//  Copyright © 2020 April Yang. All rights reserved.
//  🌲树的子结构

#include <iostream>
#include "BinaryTree.hpp"

/*
 输入两颗二叉树A和B，判断B是不是A的子结构。
 */

bool doesTreeAHasTreeB(BinaryTreeNode *pTreeA, BinaryTreeNode *pTreeB)
{
    // A == B 继续比较分支，穷尽B的时候才算是包含B
    if (pTreeB == nullptr)
        return true;
    if (pTreeA == nullptr)
        return false;
    
    if (pTreeA->m_nValue != pTreeB->m_nValue)
        return false;
        
    return doesTreeAHasTreeB(pTreeA->m_pLeft, pTreeB->m_pLeft)
    && doesTreeAHasTreeB(pTreeA->m_pRight, pTreeB->m_pRight);
}

bool isSubTree(BinaryTreeNode *pTreeA, BinaryTreeNode *pTreeB)
{
    if (pTreeA == nullptr || pTreeB == nullptr)
        return false;
    
    // 1. 找出根节点相同
    // 2. 比较树结构
    
    bool result = false;
    if (pTreeA->m_nValue == pTreeB->m_nValue)
        result = doesTreeAHasTreeB(pTreeA, pTreeB);
    if (!result)
        result = isSubTree(pTreeA->m_pLeft, pTreeB);
    if (!result)
        result = isSubTree(pTreeA->m_pRight, pTreeB);

    return result;
}

void Test(string testName, BinaryTreeNode *pHead1, BinaryTreeNode *pHead2, bool expected)
{
    printf("%s: ", testName.c_str());
    
    if (isSubTree(pHead1, pHead2) == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

void test1()
{
    vector<NodeData> data1{
        NodeData(8, true),
        NodeData(8, true),
        NodeData(7, true),
        NodeData(9, true),
        NodeData(2, true),
        NodeData(0, false),
        NodeData(0, false),
    };
    
    vector<NodeData> data2{
        NodeData(8, true),
        NodeData(9, true),
        NodeData(2, true),
    };
    
    BinaryTreeNode *pHead1 = widthlyBinaryTree(&data1);
    BinaryTreeNode *pHead2 = widthlyBinaryTree(&data2);
    
    Test(__func__, pHead1, pHead2, true);
}

void test2()
{
    vector<NodeData> data1{
        NodeData(8, true),
        NodeData(8, true),
        NodeData(7, true),
        NodeData(9, true),
        NodeData(2, true),
        NodeData(0, false),
        NodeData(0, false)
    };
    
    vector<NodeData> data2{
        NodeData(8, true),
        NodeData(9, true),
        NodeData(1, true),
    };
    
    BinaryTreeNode *pHead1 = widthlyBinaryTree(&data1);
    BinaryTreeNode *pHead2 = widthlyBinaryTree(&data2);
    
    Test(__func__, pHead1, pHead2, false);
}

void test3()
{
    vector<NodeData> data1{
        NodeData(1, true),
        NodeData(2, true),
        NodeData(3, true),
    };
    
    vector<NodeData> data2{
        NodeData(2, true)
    };
    
    BinaryTreeNode *pHead1 = widthlyBinaryTree(&data1);
    BinaryTreeNode *pHead2 = widthlyBinaryTree(&data2);
    
    Test(__func__, pHead1, pHead2, true);
}

void test4()
{
    vector<NodeData> data1{
        NodeData(1, true),
        NodeData(2, true),
        NodeData(3, true),
    };
    
    BinaryTreeNode *pHead1 = widthlyBinaryTree(&data1);
    Test(__func__, pHead1, nullptr, false);
}

void test5()
{
    Test(__func__, nullptr, nullptr, false);
}

int main(int argc, const char * argv[]) {
    
    test1();
    test2();
    test3();
    test4();
    test5();
    
    return 0;
}
