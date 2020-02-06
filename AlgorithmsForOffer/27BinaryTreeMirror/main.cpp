//
//  main.cpp
//  27BinaryTreeMirror
//
//  Created by April Yang on 2020/2/6.
//  Copyright © 2020 April Yang. All rights reserved.
//  二叉树的镜像

#include <iostream>
#include "BinaryTree.hpp"
#include <stack>

/*
 请完成一个函数，输入一颗二叉树，该函数输出它的镜象。
 */

void MirrorRecursively(BinaryTreeNode *pHead)
{
    if (pHead == nullptr)
        return;
    if (pHead->m_pLeft == nullptr && pHead->m_pRight == nullptr)
        return;
    
    BinaryTreeNode *temp = pHead->m_pLeft;
    pHead->m_pLeft = pHead->m_pRight;
    pHead->m_pRight = temp;
    
    MirrorRecursively(pHead->m_pLeft);
    MirrorRecursively(pHead->m_pRight);
}

void MirrorIteratively(BinaryTreeNode *pHead)
{
    if (pHead == nullptr)
        return;
    
    stack<BinaryTreeNode *> cached;
    cached.push(pHead);
    
    while (!cached.empty()) {
        BinaryTreeNode *top = cached.top();
        cached.pop();
        
        if (top->m_pLeft != nullptr || top->m_pRight != nullptr)
        {
            BinaryTreeNode *temp = top->m_pLeft;
            top->m_pLeft = top->m_pRight;
            top->m_pRight = temp;
            
            if (top->m_pLeft != nullptr)
                cached.push(top->m_pLeft);
            if (top->m_pRight != nullptr)
                cached.push(top->m_pRight);
        }
    }
}

void Test1()
{
    printf("=====Test1 starts:=====\n");
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

    PrintTree(pNode8);

    printf("=====Test1: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test1: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//          7
//        6
//      5
//    4
void Test2()
{
    printf("=====Test2 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, pNode7, nullptr);
    ConnectTreeNodes(pNode7, pNode6, nullptr);
    ConnectTreeNodes(pNode6, pNode5, nullptr);
    ConnectTreeNodes(pNode5, pNode4, nullptr);

    PrintTree(pNode8);

    printf("=====Test2: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test2: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ���Զ���������Ҷ�ӽ��֮�⣬���ҵĽ�㶼����ֻ��һ�����ӽ��
//            8
//             7
//              6
//               5
//                4
void Test3()
{
    printf("=====Test3 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);

    ConnectTreeNodes(pNode8, nullptr, pNode7);
    ConnectTreeNodes(pNode7, nullptr, pNode6);
    ConnectTreeNodes(pNode6, nullptr, pNode5);
    ConnectTreeNodes(pNode5, nullptr, pNode4);

    PrintTree(pNode8);

    printf("=====Test3: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test3: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);

    DestroyTree(pNode8);
}

// ���Կն������������Ϊ��ָ��
void Test4()
{
    printf("=====Test4 starts:=====\n");
    BinaryTreeNode* pNode = nullptr;

    PrintTree(pNode);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode);
    PrintTree(pNode);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode);
    PrintTree(pNode);
}

// ����ֻ��һ�����Ķ�����
void Test5()
{
    printf("=====Test5 starts:=====\n");
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);

    PrintTree(pNode8);

    printf("=====Test4: MirrorRecursively=====\n");
    MirrorRecursively(pNode8);
    PrintTree(pNode8);

    printf("=====Test4: MirrorIteratively=====\n");
    MirrorIteratively(pNode8);
    PrintTree(pNode8);
}


int main(int argc, const char * argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    
    return 0;
}
