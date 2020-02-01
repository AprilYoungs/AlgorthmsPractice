//
//  main.cpp
//  8FindTheNextNode
//
//  Created by April Yang on 2020/2/1.
//  Copyright © 2020 April Yang. All rights reserved.
//

#include <iostream>
#include "BinaryTreeAdvanced.hpp"

/*
 给定一棵二叉树中的一个节点，如何找出中序遍历序列的下一个节点？
 树中的节点除了有两个分别指向左、右节点的指针，还有一个指向父节点的指针。
 */

BinaryTreeNode* getNext(BinaryTreeNode *node)
{
    if (node == nullptr)
        return nullptr;
    
    if (node->m_pRight != nullptr)
    {
        // 6 14
        node = node->m_pRight;
        
        // 10
        while (node->m_pLeft != nullptr) {
            node = node->m_pLeft;
        }
        return node;
    }
    
    // 4 12
    if (node->m_pParent != nullptr
        && node->m_pParent->m_pLeft == node)
    {
        return node->m_pParent;
    }
    
    // 8 16
    if (node->m_pParent != nullptr
        && node->m_pParent->m_pRight == node)
    {
        while (node->m_pParent != nullptr
               && node->m_pParent->m_pLeft != node) {
            node = node->m_pParent;
        }
        return node->m_pParent;
    }
        
    return nullptr;
}

void test1()
{
    vector<NodeData> array = {
        NodeData(10, true),
        NodeData(6, true),
        NodeData(14, true),
        NodeData(4, true),
        NodeData(8, true),
        NodeData(12, true),
        NodeData(16, true)};
    
    BinaryTreeNode *pHead = widthlyBinaryTree(&array);
   
    vector<int> result = inOrderReadBinaryTree2(pHead);
    
    BinaryTreeNode *pInput = pHead->m_pRight->m_pRight;
    BinaryTreeNode *pNext = getNext(pInput);
    
    printf("input: %d \n", pInput->m_nValue);
    
    if (pNext != nullptr)
    {
        printf("output: %d \n", pNext->m_nValue);
    }
    else
    {
        printf("output: null\n");
    }
}


int main(int argc, const char * argv[]) {
    
    test1();
    
    return 0;
}
