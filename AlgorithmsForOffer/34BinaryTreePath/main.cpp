//
//  main.cpp
//  34BinaryTreePath
//
//  Created by April Yang on 2020/2/7.
//  Copyright © 2020 April Yang. All rights reserved.
//  二叉树中和为某一值的路径

#include <iostream>
#include "BinaryTree.hpp"

/*
 输入一颗二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
 从树的根节点开始往下一直到叶节点锁经过的节点形成一条路径。
 */
void FindPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int currentSum);

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if (pRoot == nullptr)
        return;
    
    vector<int> path{};
    int currentSum = 0;
    
    FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath
(
    BinaryTreeNode*   pRoot,
    int               expectedSum,
    std::vector<int>& path,
    int              currentSum
)
{
    int value = pRoot->m_nValue;
    path.push_back(value);
    currentSum += value;
    
    
    // 是否叶子节点，是否和相等
    bool isLeaf = pRoot->m_pLeft==nullptr && pRoot->m_pRight==nullptr;
    if (isLeaf && currentSum==expectedSum)
    {
        // 打印序列
        for (int i=0; i<path.size(); i++)
            printf("%d ", path[i]);
        printf("\n");
    }
    
    // 继续遍历
    if (pRoot->m_pLeft != nullptr)
        FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    
    if (pRoot->m_pRight != nullptr)
        FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
    
    // 返回上一级的时候，消除当前最后一个节点。
//    currentSum -= value;
    path.pop_back();
}

// ====================���Դ���====================
void Test(char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    FindPath(pRoot, expectedSum);

    printf("\n");
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// ������·���ϵĽ���Ϊ22
void Test1()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("Two paths should be found in Test1.\n");
    Test("Test1", pNode10, 22);

    DestroyTree(pNode10);
}

//            10
//         /      \
//        5        12
//       /\
//      4  7
// û��·���ϵĽ���Ϊ15
void Test2()
{
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode12 = CreateBinaryTreeNode(12);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNode10, pNode5, pNode12);
    ConnectTreeNodes(pNode5, pNode4, pNode7);

    printf("No paths should be found in Test2.\n");
    Test("Test2", pNode10, 15);

    DestroyTree(pNode10);
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
// ��һ��·������Ľ���Ϊ15
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);
    ConnectTreeNodes(pNode2, pNode1, nullptr);

    printf("One path should be found in Test3.\n");
    Test("Test3", pNode5, 15);

    DestroyTree(pNode5);
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
// û��·������Ľ���Ϊ16
void Test4()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode1, nullptr, pNode2);
    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    printf("No paths should be found in Test4.\n");
    Test("Test4", pNode1, 16);

    DestroyTree(pNode1);
}

// ����ֻ��1�����
void Test5()
{
    BinaryTreeNode* pNode1 = CreateBinaryTreeNode(1);

    printf("One path should be found in Test5.\n");
    Test("Test5", pNode1, 1);

    DestroyTree(pNode1);
}

// ����û�н��
void Test6()
{
    printf("No paths should be found in Test6.\n");
    Test("Test6", nullptr, 0);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();

    return 0;
}

