//
//  main.cpp
//  32-2PrintTreeLayerByLayerTwo
//
//  Created by April Yang on 2020/2/7.
//  Copyright © 2020 April Yang. All rights reserved.
//  分行从上到下打印二叉树

#include <iostream>
#include <queue>
#include "BinaryTree.hpp"

/*
 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行
 */

// 通过记录换行的点
void treePrintByLines1(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;
    
    int nodesToPrint = 1;
    int stepCount = 0;
    queue<BinaryTreeNode *> cached{};
    cached.push(pRoot);
    
    while (!cached.empty()) {
        BinaryTreeNode *node = cached.front();
        cached.pop();
        printf("%d\t", node->m_nValue);
        nodesToPrint--;
        
        if (node->m_pLeft != nullptr)
        {
            cached.push(node->m_pLeft);
            stepCount++;
        }
        if (node->m_pRight != nullptr)
        {
            cached.push(node->m_pRight);
            stepCount++;
        }
        
        if (nodesToPrint == 0)
        {
            printf("\n");
            nodesToPrint = stepCount;
            stepCount = 0;
        }
    }
}

// 通过queue缓存
void treePrintByLines2(BinaryTreeNode *pRoot)
{
    if (pRoot == nullptr)
        return;
    
    queue<BinaryTreeNode *> cached{};
    queue<BinaryTreeNode *> currentLayer{};
    currentLayer.push(pRoot);
    
    while (!currentLayer.empty()) {
        BinaryTreeNode *node = currentLayer.front();
        printf("%d\t", node->m_nValue);
        currentLayer.pop();
        
        if (node->m_pLeft != nullptr)
            cached.push(node->m_pLeft);
        if (node->m_pRight != nullptr)
            cached.push(node->m_pRight);
        
        if (currentLayer.empty())
        {
            printf("\n");
            queue<BinaryTreeNode *> temp = currentLayer;
            currentLayer = cached;
            cached = temp;
        }
    }
}


void treePrintByLines(BinaryTreeNode *pRoot)
{
    treePrintByLines2(pRoot);
}
// ====================���Դ���====================
//            8
//        6      10
//       5 7    9  11
void Test1()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    printf("====Test1 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("8 \n");
    printf("6 10 \n");
    printf("5 7 9 11 \n\n");

    printf("Actual Result is: \n");
    treePrintByLines(pNode8);
    printf("\n");

    DestroyTree(pNode8);
}

//            5
//          4
//        3
//      2
void Test2()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, pNode4, nullptr);
    ConnectTreeNodes(pNode4, pNode3, nullptr);
    ConnectTreeNodes(pNode3, pNode2, nullptr);

    printf("====Test2 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    treePrintByLines(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

//        5
//         4
//          3
//           2
void Test3()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNode5, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode2);

    printf("====Test3 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n");
    printf("4 \n");
    printf("3 \n");
    printf("2 \n\n");

    printf("Actual Result is: \n");
    treePrintByLines(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test4()
{
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    printf("====Test4 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("5 \n\n");

    printf("Actual Result is: \n");
    treePrintByLines(pNode5);
    printf("\n");

    DestroyTree(pNode5);
}

void Test5()
{
    printf("====Test5 Begins: ====\n");
    printf("Expected Result is:\n");

    printf("Actual Result is: \n");
    treePrintByLines(nullptr);
    printf("\n");
}

//        100
//        /
//       50
//         \
//         150
void Test6()
{
    BinaryTreeNode* pNode100 = CreateBinaryTreeNode(100);
    BinaryTreeNode* pNode50 = CreateBinaryTreeNode(50);
    BinaryTreeNode* pNode150 = CreateBinaryTreeNode(150);

    ConnectTreeNodes(pNode100, pNode50, nullptr);
    ConnectTreeNodes(pNode50, nullptr, pNode150);

    printf("====Test6 Begins: ====\n");
    printf("Expected Result is:\n");
    printf("100 \n");
    printf("50 \n");
    printf("150 \n\n");

    printf("Actual Result is: \n");
    treePrintByLines(pNode100);
    printf("\n");
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

